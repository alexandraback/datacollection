#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) int(a.size())
#define reset(a, x) memset(a, x, sizeof(a))

#define FOR(i, a, b)   for(int i = a; i <= b; ++i)
#define FORD(i, a, b)  for(int i = a; i >= b; --i)
#define REP(i, n)      for(int i = 0, _n = n; i < _n; ++i)
#define REPD(i, n)     for(int i = n - 1; i >= 0; --i)
#define FORSZ(i, x)    for(int i = 0; i < sz(x); ++i)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vii;

#define oo 1000000007
#define eps 1E-9

int T, R, C, W;

int main() {
    #ifdef LOCAL_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &R, &C, &W);

        int res = (R - 1) * C;

        if (W > C / 2) {
            res++;
            if (W < C)
                res += W;
            else
                res += W - 1;
        }
        else
            res += C / W + (C % W > 0) + W - 1;

        printf("Case #%d: %d\n", t, res);
    }
}
