#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int N, J;

const int PRIME_COUNT = 100000;
vector<long long> primes;

const int MAX_N = 32;
long long table[PRIME_COUNT][11][MAX_N];

bool isPrime(long long x, const vector<long long> & primes)
{
    for (int i = 0; i < primes.size(); ++i)
    {
        if (x % primes[i] == 0) return false;
        if (primes[i] * primes[i] > x) break;
    }
    return true;
}

vector<long long> genPrimes(int size)
{
    vector<long long> primes;
    primes.push_back(2);
    for (long long t = 3; primes.size() < size; t+=2)
    {
        if (isPrime(t, primes))
        {
            primes.push_back(t);
        }
    }
    return primes;
}

bool check(long long x, int base, long long & delimiter)
{
    for (int prIx = 0; prIx < primes.size(); ++prIx)
    {
        int p = primes[prIx];
        long long number = 0;
        for (int i = 0; i < N; ++i)
        {
            if (x & (1LL << i))
            {
                number += table[prIx][base][i];
                number %= p;
            }
        }
        if (number == 0)
        {
            delimiter = p;
            return true;
        }
    }

    return false;
}

string longlong2string(long long x, int N)
{
    string res(N, '0');
    for (int i = 0; i < N; ++i)
    {
        if (x & (1LL << i))
        {
            res[N-1-i] = '1';
        }
    }
    return res;
}

void solve()
{
    cin >> N >> J;

    primes = genPrimes(PRIME_COUNT);

    for (int i = 0; i < primes.size(); ++i)
    {
        long long p = primes[i];
        for (int base = 2; base <= 10; ++base)
        {
            table[i][base][0] = 1;
            for (int pow = 1; pow < N; ++pow)
            {
                table[i][base][pow] = (table[i][base][pow-1] * base) % p;
            }
        }
    }

    long long MIN_TEST = (1LL << (N - 1)) + 1;
    long long MAX_TEST = (1LL << N) - 1;

    int found = 0;
    for (long long test = MIN_TEST; test <= MAX_TEST; test += 2)
    {
        vector<long long> res(9);
        bool ok = true;
        for (int base = 2; base <= 10; ++base)
        {
            long long delimiter = 0;
            if (!check(test, base, delimiter))
            {
                ok = false;
                break;
            }
            else
            {
                res[base-2] = delimiter;
            }
        }
        if (ok)
        {
            cout << longlong2string(test, N);
            for (int i = 0; i < 9; ++i)
            {
                cout << " " << res[i];
            }
            cout << endl;
            found++;
            if (found >= J) break;
        }
    }
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        cout << "Case #" << csIx << ":" << endl;
        solve();
    }
    
    return 0;
}
