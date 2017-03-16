#include <iostream>
#include <vector>
#include <array>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
using namespace std;
using namespace boost::multiprecision;

constexpr int num_count = 150000000;
uint8_t isnprime[num_count];
int divisor[num_count];
vector<int> primes;

template<typename IntType>
string to_binary(IntType num)
{
    string result;
    while (num > 0)
    {
        result += (num%2 == 0 ? '0' : '1');
        num /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

void eratosphen()
{
    primes.reserve(num_count / 5);
    isnprime[0] = 1;
    isnprime[1] = 1;
    for (int i = 2; i < num_count; i++)
        if (!isnprime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j < num_count; j += i)
            {
                isnprime[j] = 1;
                divisor[j] = i;
            }
        }
}

inline bool isPrime(const mpz_int& num)
{
    return miller_rabin_test(num, 20);
}

inline bool isJamCoin(uint64_t coin, array<uint64_t, 9>& divisors)
{
    if ((coin & 1) == 0)
        return false;
    string coin_str = to_binary(coin);
    for (int base = 2; base <= 10; base++)
    {
        mpz_int value(0);
        for (char c: coin_str)
        {
            value = value * base + (c - '0');
        }

        //uint64_t value = stoull(coin_str, nullptr, base);

        if (isPrime(value))
            return false;

        // if (value < num_count)
        // {
        //     divisors[base - 2] = divisor[value];
        // }
        // else
        {
            bool found = false;
            // int limit = sqrt(value);
            for (auto prime : primes)
            {
                if (value % prime == 0)
                {
                    divisors[base - 2] = prime;
                    found = true;
                    break;
                }
                // if (prime > limit)
                //     break;
            }
            if (!found)
                return false;
        }
    }
    return true;
}

vector<pair<uint64_t, array<uint64_t, 9>>> test()
{
    uint64_t len, count;
    cin >> len >> count;
    uint64_t num = (1ull << (len - 1ull)) | 1ull;
    vector<pair<uint64_t, array<uint64_t, 9>>> result;
    while (result.size() < count)
    {
        array<uint64_t, 9> divisors;
        if (isJamCoin(num, divisors)) {
            result.push_back(make_pair(num, divisors));
        }
        num += 2;
    }

    return result;
}

int main(int argc, char const *argv[]) {
    eratosphen();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        auto result = test();
        cout << "Case #" << i + 1 << ":\n";
        for (auto& p : result)
        {
            cout << to_binary(p.first);
            for (int num : p.second)
                cout << " " << num;
            cout << endl;
        }
    }
}
