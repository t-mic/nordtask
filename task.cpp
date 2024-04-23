#include <iostream>
#include <fstream>
#include <stack>
#include <string>

void DetectInvalidBrackets(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stack<std::pair<char, std::pair<int, int>>> opening_bracket_stack; // Stores opening bracket type and its position

    if (file.is_open()) {
        std::string line;
        int line_number = 1;
        while (std::getline(file, line)) {
            int column_number = 1;
            for (char& c : line) {
                if (c == '[' || c == '{' || c == '(') {
                    opening_bracket_stack.push(std::make_pair(c, std::make_pair(line_number, column_number)));
                } else if (c == ']' || c == '}' || c == ')') {
                    if (opening_bracket_stack.empty()) {
                        std::cout << "Invalid bracket " << c << " found at " << filePath << ":" << line_number << ":" << column_number << ".\n";
                    } else {
                        char top = opening_bracket_stack.top().first;
                        if ((top == '[' && c != ']') || (top == '{' && c != '}') || (top == '(' && c != ')')) {
                            std::cout << "Invalid bracket " << c << " found at " << filePath << ":" << line_number << ":" << column_number << ".\n";
                        } else {
                            opening_bracket_stack.pop();
                        }
                    }
                }
                column_number++;
            }
            line_number++;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << filePath << ".\n";
    }
}

void NextProcessor(const std::string& input) {
    // Placeholder for processing input in another module
    std::cout << "Processing input in another module: " << input << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>\n";
        return 1;
    }

    std::string filePath(argv[1]);
    DetectInvalidBrackets(filePath);
  
    return 0;
}
