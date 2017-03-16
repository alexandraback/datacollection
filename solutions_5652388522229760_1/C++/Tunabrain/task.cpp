#include <iostream>

void checkDigits(int n, bool *result)
{
    while (n) {
        result[n % 10] = true;
        n /= 10;
    }
}

int count(int n)
{
    bool seen[10] = {false};
    
    bool seenAll = false;
    int iter = 1;
    while (!seenAll) {
        checkDigits(n*iter++, seen);
        seenAll = true;
        for (int i = 0; i < 10; ++i)
            seenAll = seenAll && seen[i];
    }
    
    return n*(iter - 1);
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        std::cout << "Case #" << (i + 1) << ": ";
        if (n == 0)
            std::cout << "INSOMNIA" << std::endl;
        else
            std::cout << count(n) << std::endl;
    }
    return 0;
}