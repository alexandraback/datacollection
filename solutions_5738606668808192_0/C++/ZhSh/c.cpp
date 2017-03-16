#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

//cout.precision(12);
//cout.setf( std::ios::fixed, std:: ios::floatfield );

const long long MOD = 1000000007LL;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned int ui;
typedef long long ll;
typedef vector<ll> vll;

template<class T> void printImpl(const vector<T> & coll) { copy(coll.begin(), coll.end(), ostream_iterator<T>(cout, " ")); cout << endl; }
template<class T, int N> void printImpl(T (&coll)[N]) { copy(coll, coll + N, ostream_iterator<T>(cout, " ")); cout << endl; }
template<class Key, class Value> void printImpl(const map<Key, Value> & data) { typename map<Key, Value>::const_iterator it; for (it = data.begin(); it != data.end(); ++it) { cout << it->first << ":" << it->second << endl; } }
template<class T> void printImpl(const T & data) { cout << data << endl; }

#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

int N, J;

const int PRIME_COUNT = 100000;
vector<long long> primes;

long long table[PRIME_COUNT][11][16];

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
    long long number = 0;
    for (int i = 0; i < N; ++i)
    {
        if (x & (1LL << i))
        {
            number += table[0][base][i];
        }
    }

    for (int prIx = 0; prIx < primes.size(); ++prIx)
    {
        int p = primes[prIx];
        if (number == p) return false;
        if (number % p == 0)
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
//                table[i][base][pow] = (table[i][base][pow-1] * base) % p;
                table[i][base][pow] = table[i][base][pow-1] * base;
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
