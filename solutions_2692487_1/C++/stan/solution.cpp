#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
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

int greedySolve(const vi& m, int a)
{
    int res = 0;
    for (int x : m) {
        while (x >= a) {
            a += a - 1;
            if (a == 1) return 1e8;
            ++res;
        }
        a += x;
    }
    return res;
}

void solve()
{
    int numTests; cin >> numTests;
    for1(testId, numTests) {
        int a, n; cin >> a >> n;
        vi m(n); forn(i, n) cin >> m[i];
        sort(all(m));
        int ans = 1e8;
        forn(k, n + 1) {
            int cand = k;
            vi mc(m.begin(), m.end() - k);
            cand += greedySolve(mc, a);
            ans = min(ans, cand);
        }
        cout << "Case #" << testId << ": " << ans << endl;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
