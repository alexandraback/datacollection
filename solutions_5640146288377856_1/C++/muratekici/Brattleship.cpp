#include <bits/stdc++.h>

using namespace std;

#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define orta (bas + son >> 1)
#define sag (k + k + 1)
#define sol (k + k)

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define endl '\n'

typedef pair < int ,int > pii;

typedef long long ll;

const int inf = 1e9, mod = 1e9+7;
const int N = 1e5+5;

int t, i, j, k, n, m, dp[22][1<<22];

int f(int x,int mask) {
	int &r = dp[x][mask];
	if(r != -1) return r;
	int s = 0, flag = false, flag2 = false;
	FOR(i,1,m) if(!(mask & (1 << i - 1))) s++; else { if(s == k) flag++; if(s > k) flag2 = true; s = 0; }
	if(s == k) flag++; if(s > k) flag2 = true; 
	if(flag == 1 && !flag2)  return r = 0;
	if(flag == 0 && flag2 == 0) return r = inf;
	if(x > m) return r = inf;
	return r = min(f(x+1,mask), f(x+1,mask | (1 << x - 1)) + 1);
}

int main(){
	
	scanf("%d",&t);

	FOR(i,1,t) {
		scanf("%d %d %d",&n,&m,&k);
		memset(dp,-1,sizeof dp);
		int ans = (n - 1) * (m - k + 1);
		ans += f(1,0) + k;
		printf("Case #%d: %d\n",i,ans);
	}
	
    return 0;
}
