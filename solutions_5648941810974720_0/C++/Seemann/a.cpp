#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;

vector<string> names = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int> ord = {0, 2, 6, 8, 7, 5, 4, 1, 3, 9};
vector<char> cs = {'Z', 'W', 'X', 'G', 'S', 'V', 'U', 'O', 'T', 'I'};
char c[500];
int ans[10];
void solve() {
    string s;
    cin >> s;
    forn(i, s.length()) {
        c[s[i]]++;
    }
    forn(i, 10) {
        int d = ord[i];
        char ch = cs[i];
        int n = c[ch];
        ans[d] = n;
        forn (j, names[d].length()) {
            c[names[d][j]] -= n;
        }
    }
    forn(i, 10) {
        forn(j, ans[i])
            printf("%d", i);
    }
    printf("\n");
}
int main() {
#ifdef LOCAL
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int T;
    cin >> T;
    forn(test, T) {
        printf("Case #%d: ", test + 1);
        solve();
    }
    
    return 0;
}

