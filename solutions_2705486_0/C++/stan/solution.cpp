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
#include <fstream>
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
const int NMAX = 100;
const int KMAX = 5;
int d[NMAX][KMAX];
const int INF = 1e8;
void solve()
{
    ifstream data("dict", ifstream::in);
    vector<string> words;
    words.reserve(500000);
    {
        string s;
        while (data >> s) {
            words.pb(s);
        }
    }
    int numTests; cin >> numTests;
    for1(testId, numTests) {
        string s; cin >> s;
        int n = s.length();
        forn(i, n + 1) forn(j, KMAX) d[i][j] = INF;
        d[0][4] = 0;
        forn(i, n) {
            forn(j, KMAX) {
                if (d[i][j] == INF) continue;
                for (const string& w : words) {
                    if ((int)w.size() + i > n) continue;
                    int prev = i - j - 1;
                    bool ok = true;
                    int cnt = 0;
                    forv(k, w) {
                        if (w[k] == s[i + k]) continue;
                        if (prev + 5 > i + k) {
                            ok = false;
                            break;
                        }
                        ++cnt;
                        prev = i + k;
                        if (!ok) break;
                    }
                    if (ok) {
                        int jj = i + (int)w.size() - prev - 1;
                        jj = min(jj, 4);
                        assert(jj >= 0);
                        d[i + w.size()][jj] = min(d[i + w.size()][jj], d[i][j] + cnt);
                    }
                }
            }
        }
        int ans = INF;
        forn(i, KMAX) ans = min(ans, d[n][i]);
        cout << "Case #" << testId << ": " << ans << endl;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
