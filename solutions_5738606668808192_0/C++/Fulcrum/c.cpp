#include <iostream>
#include <vector>

using std::vector;

long long get_divisor(long long n) {
    if (n % 2 == 0) {
        return 2;
    }

    long long p = 3;
    while (p * p <= n) {
        if (n % p == 0) {
            return p;
        }
        p += 2;
    }
    return n;
}

struct coin {
    vector<bool> bits;
    vector<int> divisors;
};

vector<coin> solve(int length, int count) {
    vector<bool> counter(length, false);
    counter[0] = true;
    counter[length - 1] = true;

    vector<coin> coins;

    while (true) {
        vector<int> divisors;
        bool is_non_primes = true;

        for (long long base = 2; base <= 10; ++base) {
            // Convert to a number
            long long number = 0;

            long long multiplier = 1;
            for (int i = 0; i < length; ++i) {
                if (counter[i] == true) {
                    number += multiplier;
                }
                multiplier *= base;
            }

            long long divisor = get_divisor(number);
            if (divisor == number) {
                is_non_primes = false;
                break;
            } else {
                divisors.push_back(divisor);
            }
        }

        if (is_non_primes) {
            vector<bool> bits = counter;

            coin answer = {
                bits,
                divisors,
            };
            coins.push_back(answer);

            if (coins.size() >= count) {
                return coins;
            }
        }

        // Increment the counter
        for (int i = 1; i < length - 1; ++i) {
            if (counter[i] == false) {
                counter[i] = true;
                break;
            } else {
                counter[i] = false;
            }
        }
    }
}


int main() {
    int tests_count = 0;

    std::cin >> tests_count;

    for (int i = 0; i < tests_count; ++i) {
        int length;
        int count;
        std::cin >> length >> count;
        vector<coin> answer = solve(length, count);
        std::cout << "Case #" << (i + 1) << ":" << std::endl;
        for (int i = 0; i < answer.size(); ++i) {
            for (int j = answer[i].bits.size() - 1; j >= 0; --j) {
                std::cout << (answer[i].bits[j] ? 1 : 0);
            }
            std::cout << " ";
            for (int j = 0; j < answer[i].divisors.size(); ++j) {
                std::cout << answer[i].divisors[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
