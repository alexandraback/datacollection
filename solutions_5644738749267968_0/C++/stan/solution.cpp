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

int play(deque<ld> ken, const vector<ld>& naomi)
{
    int result = 0;
    for (ld w : naomi) {
        auto it = upper_bound(all(ken), w);
        if (it == ken.end()) {
            ++result;
            ken.pop_front();
        } else {
            ken.erase(it);
        }
    }
    return result;
}

int playDeceit(deque<ld> ken, const vector<ld>& naomi)
{
    int result = 0;
    for (ld w : naomi) {
        if (w > ken.front()) {
            ++result;
            ken.pop_front();
        } else {
            ken.pop_back();
        }
    }
    return result;
}

void solveNaive()
{
    int n; 
    cin >> n;
    deque<ld> ken(n), naomi(n);
    forn(i, n) cin >> naomi[i];
    forn(i, n) cin >> ken[i];
    sort(all(ken));
    sort(all(naomi));
    vi p(n);
    forn(i, n) p[i] = i;
    int best = 0, bestDeceit = 0;
    do {
        vector<ld> naomi_ordered(n);
        forn(i, n) naomi_ordered[i] = naomi[p[i]];
        best = max(best, play(ken, naomi_ordered));
        bestDeceit = max(bestDeceit, playDeceit(ken, naomi_ordered));
        break;
    } while (next_permutation(all(p)));
    cout << " " << bestDeceit << " " << best << endl;
}

void solve()
{
    int numTests; cin >> numTests;
    for1(testId, numTests) {
        cerr << testId << endl;
        cout << "Case #" << testId << ":";
        solveNaive();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
