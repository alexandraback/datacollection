#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

struct Solution {
    int64_t number;
    std::vector<int64_t> proofs;
};

const size_t PrimesCount = 1000;

int64_t n, count;
std::vector<Solution> solutions;

std::vector<int64_t> prime_numbers;


bool can_divide(int64_t num, int64_t d, int64_t mod) {
    int64_t cur = 0, mult = 1;
    while (num > 0) {
        if (num & 1) {
            cur = (cur + mult) % mod;
        }

        mult = (mult * d) % mod;
        num >>= 1;
    }
    return cur == 0;
}


bool try_factor(int64_t num, int64_t d, std::vector<int64_t> &proofs) {
    for (auto prime : prime_numbers) {
        if (can_divide(num, d, prime)) {
            proofs.push_back(prime);
            return true;
        }
    }
    return false;
}


std::shared_ptr<Solution> try_factor(int64_t num) {
    std::vector<int64_t> proofs;
    for (int64_t d = 2; d < 11; ++d) {
        if (!try_factor(num, d, proofs)) {
            return nullptr;
        }
    }
    return std::make_shared<Solution>(Solution{num, proofs});
}


void solve() {
    int64_t max_number = static_cast<int64_t>(1) << n - 2;
    for (int64_t i = 0; i < max_number && solutions.size() < count; ++i) {
        int64_t num = 1 + 2 * (i + max_number);
        auto solution = try_factor(num);
        if (solution != nullptr) {
            solutions.push_back(*solution);
        }
    }
}


void read(std::istream &input) {
    input >> n >> count;
}


void binary_print(int64_t number, std::ostream &output) {
    std::string str;
    while (number) {
        str.push_back('0' + (number & 1));
        number >>= 1;
    }
    reverse(begin(str), end(str));
    output << str << ' ';
}


void print(std::ostream &output) {
    output << std::endl;
    for (size_t i = 0; i < count; ++i) {
        binary_print(solutions[i].number, output);
        for (auto proof : solutions[i].proofs) {
            output << proof << ' ';
        }
        output << std::endl;
    }
}


bool is_prime(int64_t x) {
    for (int64_t i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


void init() {
    for (int64_t i = 2; prime_numbers.size() < PrimesCount; ++i) {
        if (is_prime(i)) {
            prime_numbers.push_back(i);
        }
    }
}


int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    init();

    size_t t;
    std::cin >> t;
    for (size_t i = 1; i <= t; ++i) {
        read(std::cin);
        solve();
        std::cout << "Case #" << i << ": ";
        print(std::cout);
    }
    return 0;
}