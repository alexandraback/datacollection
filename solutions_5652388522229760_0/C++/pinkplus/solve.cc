#include <stdexcept>
#include <iostream>
#include <set>
#include <string>

class DigitSet {
    public:
        DigitSet() {
            for (int i=0; i<N; i++) {
                digits[i] = false;
            }
        }

        void add(int n) throw(std::runtime_error) {
            if (!(n >= 0 && n <= 10)) {
                throw std::runtime_error{""};
            }
            digits[n] = true;
        }

        void add(char c) {
            add(c - '0');
        }

        bool isFull() {
            for (int i=0; i<N; i++) {
                if (!digits[i]) {
                    return false;
                }
            }
            return true;
        }

    private:
        const static int N = 10;
        bool digits[N];
};

unsigned long solve(unsigned long n) {
    auto digits = DigitSet{};
    for (int i=1; i<=1000; i++) {
        unsigned long nn = n * i;
        auto s = std::to_string(nn);
        for (const auto c : s) {
            digits.add(c);
        }
        if (digits.isFull()) {
            return nn;
        }
    }
    return 0;
}

int main() {
    int T;
    std::cin >> T;
    for (int i=1; i<=T; i++) {
        int n;
        std::cin >> n;
        auto retval = solve(n);
        if (retval == 0) {
            std::cout << "Case #" << i << ": INSOMNIA" << std::endl;;
        } else {
            std::cout << "Case #" << i << ": " << retval << std::endl;;
        }
    }
    return 0;
}
