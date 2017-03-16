#include <iostream>
#include <vector>

class DigitChecker {
public:
    DigitChecker() : seen_(10, false), found_(0) {}

    void check(long long n) {
        auto digit = n%10;
        checkDigit(digit);
        if (n > 9)
            check(n/10);
    }

    void checkDigit(int d) {
        if (!seen_[d]) {
            seen_[d] = true;
            found_++;
        }
    }
    bool finished() const {
        return found_ == 10;
    }

private:
    std::vector<bool> seen_;
    int found_;

};

int main() {
    int T;
    std::cin >> T;

    for (int i=0; i<T; ++i) {
       long long N;
        std::cin >> N;

        if (N==0)
            std::cout << "Case #" << i+1 << ": INSOMNIA" << std::endl;
        else {
            DigitChecker b;
            int trials = 0;
            long long M = 0;
            while (!b.finished()) {
                M += N;
                b.check(M);
                ++trials;
            }

            std::cout << "Case #" << i+1 << ": " << M << std::endl;
        }
    }
}
