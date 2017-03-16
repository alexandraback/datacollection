#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define sz(x) (int)x.size()

typedef pair<int, int> II;
const int inf = 1e9;
const int Nmax = 1100;

int n, p[Nmax];

int check(int eatTime) {
    int res = 0;
    FOR(i, 1, n) if (p[i] > eatTime){
        int cur = p[i]/eatTime + (int)(p[i]%eatTime > 0) - 1;
        res += cur;
    }
    return res;
}

int main() {
   // freopen("B-large.in", "r", stdin);
   // freopen("ans.out", "w", stdout);
    int test;
    cin >> test;
    FOR(t, 1, test) {
        cin >> n;
        int MaxP = 0;
        FOR(i, 1, n) {
            cin >> p[i];
            MaxP = max(MaxP, p[i]);
        }
        int res = MaxP;
        FOR(i, 1, MaxP) res = min(res, i + check(i));
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
