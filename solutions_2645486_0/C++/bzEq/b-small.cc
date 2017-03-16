#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <bitset>
#include <utility>

using namespace std;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())
#define MP(x,y) make_pair((x),(y))

typedef long long ll;
const int INF=2147483647;
const int MOD=(int)1e9+7;
const int MAX=20;
int N,E,v[MAX],R;
int dfs(int n, int eleft,int e,int now) {
    if (n==N) return now;
    now+=e*v[n];
    int ret=now;
    eleft-=e;
    eleft=(eleft+R>=E?E:eleft+R);
    for (int e=0; e<=eleft; e++)
        ret=max(ret,dfs(n+1,eleft,e,now));
    return ret;
}

int main() {
    int T;
    scanf("%d",&T);
    REP(t,T) {
        scanf("%d%d%d",&E,&R,&N);
        REP(i,N) scanf("%d",v+i);
        int ans=0;
        for (int e=0; e<=E; e++)
            ans=max(ans,dfs(0,E,e,0));
        printf("Case #%d: %d\n",t+1,ans);
    }
    return 0;
}
