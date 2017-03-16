#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<climits>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<complex>
#include<set>
#include<bitset>
#include<utility>
#include<valarray>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;

#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define all(a) (a).begin(),(a).end()
#define len(a) ((int)(a).size())
#define mem(a,n) memset(a,n,sizeof(a))
#define eps 1e-9
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)

bool fun(ll n,double r,ll t){
	if((double)(r+2*n-1)*(r+2*n-1)>1e18)return (double)((r+2*n-1)*(r+2*n-1)-r*r)<=t;
	return ((r+2*n-1)*(r+2*n-1)-r*r)<=t;
}

bool fun2(ll n, ll r , ll t){
	if((double)n*r>1e8 || (double)2*n*(n+1)>1e8)
	return (double)2*n*r+(double)2*n*(n+1)-n<=t;
	//~ cout<<2*n*r+2*n*(n+1)-n<<endl;
	return 2*n*r+2*n*(n+1)-3*n<=t;
}

int main(void){
	ios_base::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	ll tst,rr,t;
	cin>>tst;
	rep(k,tst){
		cin>>rr>>t;
		ll ans=1,l=1,r=1000000000000000000LL;
		while(l<r){
			ll mid=l+r;
			mid/=2;
			if(fun2(mid,rr,t)){l=mid+1;ans=max(ans,mid);}
			else r=mid;
			//~ cout<<l<<" "<<r<<" "<<mid<<endl;
		}
		//~ ans = (t-2*rr+3)/4;
		cout<<"Case #"<<k+1<<": "<<ans<<endl;
	}
	return 0;
}
