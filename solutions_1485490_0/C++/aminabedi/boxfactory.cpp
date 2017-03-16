//VERDICT:

#include<iostream>
#include<algorithm>
#include<cstring>
//#include<cstdlib>
#include<vector>
#include<cstdio>
//#include<iomanip>
//#include<map>
//#include<set>
#include<queue>
//#include<deque>
//#include<utility>
#include<cmath>
#define pb push_back
#define mkp make_pair
#define foR(i,j,n) for(int i=j;i<n;i++)
#define error(x) cerr<<#x<<"="<<x<<endl;
#define stf(x) st.find(x)!=st.end()
#define X first
#define Y second
typedef unsigned long long ll;
using namespace std;
const int maxn=110,inf=1000000000,mod=1000003;
vector<pair<ll,int> > x,y;
ll dp[maxn][maxn];
ll f(int i,int j){
	if(i==x.size()||j==y.size())
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll ans=0,t=0;
	if(x[i].Y==y[j].Y){
		t=min(x[i].X,y[j].X);
		x[i].X-=t;y[j].X-=t;
	}
	if(x[i].X)
		ans=max(ans,f(i,j+1));
	if(y[j].X)
		ans=max(f(i+1,j),ans);
	if(!y[j].X&&!x[i].X)
		ans=max(ans,f(i+1,j+1));
	x[i].X+=t;
	y[j].X+=t;
	return dp[i][j]=ans+t;
}		
int main(){
	int t;
	cin>>t;
	foR(j,1,t+1){
		memset(dp,-1,sizeof dp);
		x.clear();y.clear();
		int n,m,s;
		ll k;
		cin>>n>>m;
		foR(i,0,n){
			cin>>k>>s;
			x.pb(mkp(k,s));
		}
		foR(i,0,m){
			cin>>k>>s;
			y.pb(mkp(k,s));
		}
		cout<<"Case #"<<j<<": "<<f(0,0)<<endl;
	}
	return 0;
}
