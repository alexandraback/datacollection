//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

int a,b,k;
LL dp[35][2][2][2];

LL dfs(int now,int la,int lb,int limit){
	if(now<0) return (la==0&&lb==0&&limit==0)?1:0;
	if(~dp[now][la][lb][limit]) return dp[now][la][lb][limit];
	LL &ans = dp[now][la][lb][limit];
	ans = 0;
	int ea,eb;
	if(la) ea = (a&(1<<now))?1:0;
	else ea = 1;
	if(lb) eb = (b&(1<<now))?1:0;
	else eb = 1;
	for(int i = 0;i<=ea;i++){
		for(int j = 0;j<=eb;j++){
			if((k&(1<<now))==0&&i&&j&&limit) continue;
			int eq = 0;
			if(k&(1<<now)){
				if(i&&j) eq = 1;
			}else eq = 1;
			ans+=dfs(now-1,la&&i==ea,lb&&j==eb,limit&&eq);
		}
	}
	return ans;
}

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/B-large.in","r",stdin);
	freopen("/Users/mac/Desktop/B.txt","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&a,&b,&k);
		memset(dp,-1,sizeof(dp));
		LL ans = dfs(31,1,1,1);
		static int ca = 1;
		printf("Case #%d: %lld\n",ca++,ans);
	}
	return 0;
}

