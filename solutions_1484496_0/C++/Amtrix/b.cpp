#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <stack>
#include <assert.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define pb push_back

const int maxn = 505;
const int maxv = 100000+55;

int n;
int x[maxn];


short dp[22][maxv*3][2][2];
int sel[22];

bool solve(int dx, int sum, bool f, bool s) {
    if (dx == n) {
        if(sum == 0 && f && s) {
            return true;
        }
        return false;
    }

    short &state = dp[dx][sum+maxv][f][s];
    if (state != -1) {//shouldn't happen
        return state;
    }
    state = false;

    state = solve(dx+1, sum, f, s);
    if(state) {
        sel[dx] = 0;
        return true;
    }

    state = solve(dx+1, sum + x[dx], true, s);
    if(state) {
        sel[dx] = 1;
        return true;
    }

    state = solve(dx+1, sum - x[dx], f, true);
    if(state) {
        sel[dx] = -1;
        return true;
    }
    return false;
}

int main() {
    freopen("Ulaz","r",stdin);
    freopen("Izlaz","w",stdout);

    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
            scanf("%d",&x[i]);

        memset(dp, -1, sizeof(dp));
        int ok = solve(0, 0, false, false);
        printf("Case #%d:\n",t);

        if(!ok) {
            printf("Impossible\n");
        }

        vector<int>f,s;
        for (int i = 0; i < n; ++i)
            if(sel[i] == 1) f.pb(x[i]);
            else if(sel[i] == -1) s.pb(x[i]);

        for (int i = 0; i < f.size(); ++i)
            printf("%d ",f[i]);
        printf("\n");
        for (int i = 0; i < s.size(); ++i)
            printf("%d ",s[i]);
        printf("\n");

        int s1 = 0;
        for (int i = 0; i < f.size(); ++i)
            s1 += f[i];
        for (int i = 0; i < s.size(); ++i)
            s1 -= s[i];

    }
    return 0;
}
