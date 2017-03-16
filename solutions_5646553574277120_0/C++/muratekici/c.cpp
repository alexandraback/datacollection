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

int a, c, i, j, n, m, x, k, h[N], y, d, dp[N], t;

int solve(int x) {
	if(x > 15) {
		FOR(i,0,a) dp[i] = 0; dp[0] = 1;
		FOR(s,1,a) 
			if(h[s])
				ROF(i,a,s) if(dp[i-s]) dp[i] = 1;
		FOR(i,1,a) if(!dp[i]) { return inf; }
		return 0;
	}
	int ans = inf;
	int temp = h[x];
	h[x] = 1;
	ans = solve(x+1) + 1; 	
	h[x] = temp;
	ans = min(solve(x+1), ans);
	return ans;
}

int main(){
	
	scanf("%d",&t);

	FOR(i,1,t) {
		memset(h,0,sizeof h);
		scanf("%d %d %d",&c,&d,&a);
		FOR(j,1,d) { scanf("%d",&x); h[x] = 1; }
		printf("Case #%d: %d\n",i,solve(1));
	}
	
    return 0;
}
