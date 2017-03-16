#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int a[MX]; ll x[MX], y[MX];

int main(){
	int t, n, v, o; ll e, r, ans, m; P p;
	scanf("%d",&t);
	
	rrep(ti,t){
		scanf("%lld%lld%d",&e,&r,&n);
		rep(i,n) scanf("%d",&a[i]);
		r = min(r,e);
		rep(i,n) x[i] = 0;
		ans = 0;
		priority_queue<P,vector<P>,greater<P> > q;
		rep(i,n){
			x[i] = (i?x[i-1]+r:e);
			y[i] = (i?r:e);
			ans += y[i]*a[i];
			while(!q.empty()){
				p = q.top();
				v = p.fi; o = p.se;
				if(v >= a[i]) break;
				q.pop(); m = y[o];
				for(int j = o; j < i; j++) m = min(m,x[j]-r*(j+1));
				if(m > 0){
					for(int j = o; j < i; j++) x[j] -= m;
					ans += m*(a[i]-v); y[o] -= m; y[i] += m;
				}
				//cout << ans << " " << v << " " << o << " " << m << endl;
			}
			q.push(P(a[i],i));
		}
		printf("Case #%d: %lld\n",ti,ans);
	}
	
	return 0;
}





