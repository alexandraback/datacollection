#include <array>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <limits>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

constexpr auto BASES = 9ul;

struct Jamcoin final {
    const std::string id;
    const std::array<unsigned long int, BASES> divisors;
};

void num_to_bin_str(unsigned long int num, char str[], const unsigned long int length) {
    for (auto i = length; i-- > 0ul;) {
        str[i] = (num % 2ul == 1) ? '1' : '0';
        num /= 2ul;
    }
}

unsigned long int interpret(const char id[], const unsigned long int length, unsigned long int base) {
    auto val = 0ul;
    for (auto i = 0ul; i < length; ++i) {
        val *= base;
        if (id[i] == '1') {
            ++val;
        }
    }
    return val;
}

unsigned long int get_smallest_prime_divisor(
    const unsigned long int num, 
    const std::vector<unsigned long int>* primes
) {
    for (const auto prime: *primes) {
        if (num % prime == 0ul) {
            return prime;
        }
    }
    return num;
}

std::unique_ptr<std::vector<Jamcoin>> solve(
    const unsigned long int N,
    const unsigned long int J,
    const std::vector<unsigned long int>* primes
) {
    auto coins = std::unique_ptr<std::vector<Jamcoin>>(
        new std::vector<Jamcoin>()
    );
    coins->reserve(J);

    auto num_id = (1ul << (N - 1)) + 1;

    char buffer[N + 1];
    buffer[N] = '\0';

    std::array<unsigned long int, BASES> divisors;
    do {
        num_to_bin_str(num_id, buffer, N);

        auto base = 2ul;
        auto valid = true;
        do {
            auto num_in_base = interpret(buffer, N, base);
            auto prime = get_smallest_prime_divisor(num_in_base, primes);
            if (prime == num_in_base) {
                valid = false;
                break;
            } else {
                divisors[base - 2ul] = prime;
            }
            ++base;
        } while (valid && base < 11ul);

        if (valid) {
            for (auto i = 0ul; i < BASES; ++i) {
                const auto num_in_base = interpret(buffer, N, i + 2);
                const auto res = num_in_base % divisors[i];
                assert(res == 0);
            }
            coins->push_back(Jamcoin{std::string(buffer), divisors});
        }

        num_id += 2;                
    } while(coins->size() < J);
    return coins;
}

std::unique_ptr<std::vector<unsigned long int>> primes_up_to(const unsigned long int max_prime) {
    const auto high = max_prime + 1;
    const unsigned long int div_high = std::lround(std::sqrt(max_prime)) + 1;

    auto sieve = std::vector<bool>(high, true);
    sieve[0] = false;
    sieve[1] = false;

    for (auto i = 2ul; i < div_high; ++i) {
        if (sieve[i]) {
            #pragma omp parallel for default(none) shared(i, sieve) schedule(static)
            for (auto multiple = i * i; multiple < high; multiple += i) {
                sieve[multiple] = false;
            }
        }
    }
    
    auto primes = std::unique_ptr<std::vector<unsigned long int>>(
        new std::vector<unsigned long int>()
    );
    for (auto i = 0ul; i < max_prime + 1; ++i) {
        if (sieve[i]) {
            primes->push_back(i);
        }
    }
    return primes;
} 

int main() {
    unsigned int T;
    std::cin >> T;
    
    for (auto i = 1u; i <= T; ++i) {
        unsigned long int N, J;
        std::cin >> N >> J;

        const auto max_num = std::pow(10ul, N + 1) - 1;
        const auto max_prime = std::lround(std::floor(std::sqrt(max_num)));
        const auto primes = primes_up_to(max_prime);

        std::cout << "Case #" << i << ":" << std::endl;
        const auto coins = solve(N, J, primes.get());
        for (const auto& ans: *coins) {
            std::cout << ans.id << " ";
            std::copy(ans.divisors.begin(), ans.divisors.end(),
                      std::ostream_iterator<unsigned long int>(std::cout, " ")
            );
            std::cout << std::endl;
        }
    }
}
