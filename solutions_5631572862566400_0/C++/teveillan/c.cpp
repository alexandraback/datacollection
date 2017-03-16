#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
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

bool visit[1100];
int v[1100];
VI head[1100];
int dfs1(int cur, int tmp) {
    if(head[cur].size() == 0) return tmp;
    int ret = 0;
    for(int to: head[cur]) {
        ret = max(ret, dfs1(to, tmp + 1));
    }
    return ret;
}


int f[1100];
int dfs2(int cur, int tmp) {
    visit[cur] = 1;
    f[cur] = tmp;
    if(visit[v[cur]]) {
        return f[cur] - f[v[cur]] + 1;
    }
    return dfs2(v[cur], tmp + 1);
}

int dp[1100];
bool flag[1100];
int main()
{
	freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int casnum;
    cin >> casnum;
    FOR(casid, 1, casnum) {
        memset(visit, 0, sizeof(visit));
        memset(dp, 0, sizeof(dp));
        memset(flag, 0, sizeof(flag));
        int n;
        cin >> n;
        FOR(i, 1, n) head[i].clear();
        FOR(i, 1, n) scanf("%d", &v[i]);

        int ret = 0;
        FOR(i, 1, n) {
            memset(visit, 0, sizeof(visit));
            ret = max(ret, dfs2(i, 0));
        }

        FOR(cur, 1, n) head[v[cur]].pb(cur);
        FOR(cur, 1, n) if(v[v[cur]] == cur) flag[cur] = flag[v[cur]] = 1;

        FOR(cur, 1, n) if(!flag[cur] && flag[v[cur]]) {
            int tmp = dfs1(cur, 1);
            dp[v[cur]] = max(dp[v[cur]], tmp);
        }

        int tmp = 0;
        memset(visit, 0, sizeof(visit));
        FOR(cur, 1, n) {
            if(flag[cur] && !visit[cur]) {
                visit[cur] = visit[v[cur]] = 1;
                tmp += 2 + dp[cur] + dp[v[cur]];
            }
        }
        ret = max(tmp, ret);



        printf("Case #%d: %d\n", casid, ret);
    }

    return 0;
}

