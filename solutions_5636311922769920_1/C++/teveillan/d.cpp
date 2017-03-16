#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define MEM(arr, v) memset(arr, v, sizeof(arr))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

LL id;
LL dfs(LL pos, LL deep, LL c, LL k) {
    if(deep == c) return pos;
    id = min(id + 1, k);
    return dfs((pos-1) * k + id, deep+1, c, k);
}

int main()
{
	freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int casnum;
    cin >> casnum;
    FOR(casid, 1, casnum) {
        LL k, c, s;
        cin >> k >> c >> s;
        printf("Case #%d:", casid);
        LL ans = (k + c - 1) / c;
        if(s < ans) puts(" IMPOSSIBLE");
        else {
            id = 0;

            FOR(i, 1, ans) {
                id = min(id + 1, k);
                printf(" %lld", dfs(id, 1, c, k));
            }
            puts("");
        }
    }

    return 0;
}

