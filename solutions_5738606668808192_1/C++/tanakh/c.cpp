#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cstdio>
#include <cstring>
using namespace std;

vector<int> primes;

void init()
{
    vector<bool> sieve(100, false);

    for (int i = 2; i < sieve.size(); i++) {
        if (sieve[i]) continue;
        sieve[i] = true;
        primes.push_back(i);
        for (int j = i + i; j < sieve.size(); j += i)
            sieve[j] = true;
    }
}

int div(int64_t bits, int base, int p)
{
    if (bits == 0) return 0;

    int rem = div(bits >> 1, base, p);
    return (rem * base + (bits & 1)) % p;
}

void solve()
{
    int n, j; cin >> n >> j;

    set<int64_t> ss;
    mt19937 rng;
    uniform_int_distribution<int64_t> dist(0, (1LL<<(n-2))-1);

    while (ss.size() < j) {
        auto cand = dist(rng) * 2 + (1LL << (n-1)) + 1;
        if (ss.count(cand)) continue;
        // cout << "*** " << cand << endl;

        int ds[11] = {};
        bool ok = true;

        for (int base = 2; base <= 10; base++) {
            ds[base] = 0;
            for (auto &p: primes) {
                if (div(cand, base, p) == 0) {
                    ds[base] = p;
                    break;
                }
            }
            if (ds[base] == 0) {
                ok = false;
                break;
            }
        }

        if (!ok) continue;

        ss.insert(cand);

        for (int i = 0; i < n; i++) cout << ((cand >> (n - 1 - i)) & 1);
        for (int i = 2; i <= 10; i++) cout << " " << ds[i];
        cout << endl;
    }

}

int main()
{
    init();

    int cases; cin >> cases;
    for (int cn = 1; cn <= cases; cn++) {
        cout << "Case #" << cn << ":" << endl;
        solve();
    }
    return 0;
}
