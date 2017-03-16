#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI  3.1415926535897932385
#define EPS 1e-7
#define MOD 1000000007
#define INF 1500111222
#define MAX 33

int d, m, k, a[MAX];
int choosen[MAX], res;
bool weHave[MAX], mark[MAX];

bool check(int n, int cnt) {
    fill(mark, false);
    mark[0] = true;
    rep(i, n) {
        for (int j = m; j >= choosen[i]; j--)
            if (mark[j - choosen[i]])
                mark[j] = true;
    }
    fr(i, 1, m) if (!mark[i])
        return false;
    res = min(res, cnt);
    return true;
}

void recurse(int n, int val, int cnt) {
    if (cnt >= res) return;
    if (check(n, cnt)) return;
    if (val > m) return;

    if (weHave[val]) {
        choosen[n] = val;
        n++;
    }
    recurse(n, val + 1, cnt);
    if (weHave[val]) n--;

    choosen[n] = val;
    if (!weHave[val]) cnt++;
    recurse(n + 1, val + 1, cnt);
}

int solve() {
    fill(weHave, false);
    rep(i, d) weHave[a[i]] = true;
    res = min(m, 5);
    recurse(0, 1, 0);
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("csmall.inp", "r", stdin);
        freopen("csmall.out", "w", stdout);
    #endif
    int cases, caseNo = 0;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d %d %d", &k, &d, &m);
        rep(i, d) scanf("%d", &a[i]);
        printf("Case #%d: %d\n", ++caseNo, solve());
    }
    return 0;
}

// Viet P. Lam - lamphanviet@gmail.com - http://blog.lamphanviet.com