#include <iostream>
#include <string>

int main() {
    int T, i, count;
    std::string str;
    std::string::reverse_iterator rit;
    char last_seen;
    
    std::cin >> T;
    for (i = 1; i <= T; ++i) {
        std::cin >> str;
        last_seen = '+';
        count = 0;
        for (rit = str.rbegin(); rit != str.rend(); ++rit) {
            if (last_seen != *rit) {
                last_seen = *rit;
                ++count;
            }
        }
        std::cout << "Case #" << i << ": " << count << std::endl;
    }
    return 0;
}
