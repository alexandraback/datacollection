#include <iostream>
#include <vector>

long long solve(long long n) {
    if (n == 0) {
        return 0;
    }

    bool k[10] = {0};
    int total = 0;
    long long i = 1;
    while (true) {
        long long temp = n * i;
        while (temp) {
            if (k[temp % 10] == 0) {
                k[temp % 10] = 1;
                total += 1;
                if (total == 10) {
                    return n * i;
                }
            }
            temp /= 10;
        }
        i += 1;
    }
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        int t = solve(n);
        std::cout << "Case #" << i + 1 << ": ";
        if (t == 0) {
            std::cout << "INSOMNIA" << std::endl;
        } else {
            std::cout << t << std::endl;
        }
    }
}
