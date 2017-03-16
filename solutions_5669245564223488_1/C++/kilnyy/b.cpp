#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,n) for(int i=1;i<=(n);i++)
#define FORD(i,n) for(int i=(n);i>=1;i--)

#define SZ(x) ((int)x.size())
#define CC(a,x) memset(a,x,sizeof(a))
#define TWO(x) ((LL)1<<(x))

#define DEBUG

using namespace std;

typedef long long LL;

string s[102];

int y[256];

int c[256][2];

int n;

const LL mod = 1000000007;

LL ans;

void dfs(int u, char f) {
    if (y[u]) return;
    y[u] = true;
    REP(v, n) if (s[v][0] != s[v][1] && !y[v]) {
        if (s[v][0] == s[u][1]) {dfs(v, f); return;}
    }
    if (f == s[u][1]) {ans=0; return;}
}

void solve() {
    ans = 0;
    CC(y, 0);
    CC(c, 0);
    REP(i, n) {
        int l = s[i].size();
        for(int j=0; j<l; j++) {
            if (j==0 || s[i][j] != s[i][j-1])
                y[s[i][j]]++;
            if (s[i][j]!=s[i][0] && s[i][j]!=s[i][l-1])
            if (y[s[i][j]] > 1 || (y[s[i][j]] > 0 && s[i][0] == s[i][l-1]) )
             return;
        }
        s[i] = s[i].substr(0, 1) + s[i].substr(l-1, 1);
    }
    sort(s, s+n);
    CC(y, 0);
    REP(i, n) {
        if (s[i][0] == s[i][1]) {
            y[s[i][0]]++;
        } else {
            if (++c[s[i][0]][0] > 1) return;
            if (++c[s[i][1]][1] > 1) return;
        }
    }

    ans = 1;
    int cnt = 0;
    for (int x='a'; x<='z'; x++) {
        FOR(i, y[x]) ans = (ans * i) % mod;
        if (c[x][0] + c[x][1] == 1) cnt ++;
        else if (c[x][0] + c[x][1] == 0 && y[x]) cnt+=2;
    }
    FOR(i, cnt/2) ans = (ans * i) % mod;

    CC(y, 0);
    REP(i, n) {
        if (s[i][0] != s[i][1]) dfs(i, s[i][0]);
    }
}

int main()
{
#ifdef DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    FOR(i, T) {
        scanf("%d\n", &n);
        REP(j, n) cin>>s[j];
        solve();
        printf("Case #%d: %lld\n", i, ans);
    }
	return 0;
}
