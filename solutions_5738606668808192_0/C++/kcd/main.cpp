#include <iostream>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <array>


using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }

using ui8 = unsigned char;
using ui32 = unsigned int;
using ui64 = unsigned long long;

ui32 LongMod(ui32 a, ui32 n, ui32 b) {
    ui32 r = 1;
    for (ui32 i = 1; i < n; ++i) {
        r = (r * a) % b;
    }
    return r;
}

const int maxp = 100;


array<ui32, maxp> primes;
array<array<ui32, maxp>, 11> mods;
int N, K;

void FillPrimes() {
    int cnt = 0;
    for (ui32 i = 2; ; i++) {
        bool isPrime = true;
        for (ui32 j = 2; j * j <= i; ++j) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes[cnt++] = i;
            if (cnt >= maxp) {
                break;
            }
        }
    }
}

void FillMods() {
    for (int i = 2; i <= 10; ++i) {
        for (int j = 0; j < maxp; ++j) {
            mods[i][j] = (LongMod(i, N, primes[j]) + 1) % primes[j];
        }
    }
}

using TNumber = array<ui32, 32>;
using TDivisors = array<ui32, 11>;

TNumber number;
TDivisors divisors;
vector<pair<TNumber, TDivisors>> ans;
int remain = 0;

void Do(int n) {
    if (remain == 0) {
        return;
    }
    if (n == 1) {
        bool ok = true;
        for (int i = 2; i <= 10; ++i) {
            ui64 value = 0;
            ui32 p = i;
            for (int j = 2; j < N; ++j) {
                value += number[j - 1] * p;
                p *= i;
            }
            bool isPrime = true;
            for (size_t j = 0; j < maxp; ++j) {
                if ((value % primes[j] + mods[i][j]) % primes[j] == 0) {
                    divisors[i] = primes[j];
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push_back(make_pair(number, divisors));
            --remain;
        }
    } else {
        number[n - 1] = 0;
        Do(n - 1);
        number[n - 1] = 1;
        Do(n - 1);
    }
}

void Solution() {
    cout << endl;
    int n, k;
    cin >> n >> k;
    N = n, K = k;
    FillPrimes();
    FillMods();
    remain = k;
    number.fill(0);
    number[n - 1] = 1;
    number[0] = 1;
    Do(n - 1);
    for (size_t i = 0; i < ans.size(); ++i) {
        for (int j = n - 1; j >= 0; --j) {
            cout << ans[i].first[j];
        }
        for (int j = 2; j <= 10; ++j) {
            cout << ' ' << ans[i].second[j];
        }
        cout << endl;
    }
}

int main() {
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
    }

    return 0;
}


