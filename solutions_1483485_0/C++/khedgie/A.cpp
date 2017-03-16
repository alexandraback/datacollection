#include <iostream>
#include <limits>

std::string map = "yhesocvxduiglbkrztnwjpfmaq"; 

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int X = 1; X <= T; ++X) {
        std::string s;
        getline(std::cin, s);
        for (std::string::iterator i = s.begin(); i != s.end(); ++i) {
            if (*i != ' ') {
                *i = map[*i - 'a'];
            }
        }
        std::cout << "Case #" << X << ": " << s << '\n';
    }
    return 0;
}
