#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define foreach(_it,_v) for(typeof(_v.begin()) _it = _v.begin(); _it != _v.end(); ++_it)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 20;

int v[MAXN];
int dp[MAXN][MAXN];
int e,r,n;

int go(int i,int en) {
    if(i == n) return 0;
    if(dp[i][en] != -1) return dp[i][en];
    int ret = 0;
    for(int a=0;a<=en;++a) ret = max(ret,a*v[i] + go(i+1,min(e,en-a+r)));
    return dp[i][en] = ret;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&e,&r,&n);
        for(int a=0;a<n;++a) scanf("%d",&v[a]);
        printf("Case #%d: %d\n",t,go(0,e));
    }
        
    return 0;
}
