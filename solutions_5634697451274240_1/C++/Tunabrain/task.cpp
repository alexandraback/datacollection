#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    std::cin.get();
    for (int i = 0; i < t; ++i) {
        char last = std::cin.get(), next;
        int numFlips = 0;
        while ((next = std::cin.get()) != '\n') {
            if (next != last)
                numFlips++;
            last = next;
        }
        if (last == '-')
            numFlips++;
        std::cout << "Case #" << (i + 1) << ": ";
        std::cout << numFlips << std::endl;
    }
    return 0;
}