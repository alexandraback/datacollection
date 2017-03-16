#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
#include <limits>
using namespace std;

#define REQUIRE(cond, message) \
    do { \
        if (!(cond)) { \
            std::cerr << message << std::endl; \
            assert(false); \
        } \
    } while (false)

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef long double ld;

template<typename T>
inline int popcount(T t) {
    if (std::numeric_limits<T>::digits <=
                            std::numeric_limits<unsigned int>::digits) {
        return __builtin_popcount(t);
    } else {
        return __builtin_popcountll(t);
    }
}

const ld EPS = 1e-8;
const ld PI = acosl(0.0) * 2;

ll readDouble5()
{
    ld value;
    cin >> value;
    value *= 100000;
    return value + 0.5;
}

ld solveTest()
{
    ll c = readDouble5();
    ll f = readDouble5();
    ll x = readDouble5();
    ll n = 0;
    if (x * f - c * f - 2 * c * 100000 > 0) {
        n = (x * f - c * f - 2 * c * 100000 + c * f - 1) / (c * f);
    }
    ld result = 0;
    ll currentDenominator = 2 * 100000;
    forn(i, n) {
        result += c / static_cast<ld>(currentDenominator);
        currentDenominator += f;
    }
    result += x / static_cast<ld>(currentDenominator);
    return result;
}

void solve()
{
    int numTests; cin >> numTests;
    cout.precision(10);
    cout << fixed;
    for1(testId, numTests) {
        cout << "Case #" << testId << ": ";
        cout << solveTest() << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
