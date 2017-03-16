#include <iostream>
#include <string>


int main(void)
{
    int t;
    std::cin >> t;
    std::string line;
    std::getline(std::cin, line);
    for (int i = 1; i <= t; i++) {
        std::getline(std::cin, line);
        int k = 0;
        for (unsigned o = line.size(); o; o--) {
            if (line[o - 1] == '+')
                continue;
            for (unsigned z = o; z; z--)
                line[z - 1] = line[z - 1] == '+' ? '-' : '+';
            k += 1;
        }
        std::cout << "Case #" << i << ": " << k << std::endl;
    }
    return 0;
}
