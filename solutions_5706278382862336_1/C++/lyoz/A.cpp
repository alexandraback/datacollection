#include <bits/stdc++.h>
using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

const int INF=1e9;
const int MOD=1e9+7;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

const string impossible="impossible";

void solve()
{
	ll p,q;
	{
		string s; cin>>s;
		replace(all(s),'/',' ');
		istringstream ss(s); ss>>p>>q;
	}
	ll g=__gcd(p,q); p/=g,q/=g;
	
	if(__builtin_popcountll(q)>1){
		cout<<impossible<<endl;
		return;
	}
	
	ll x=__builtin_popcountll(p);
	ll y=63-__builtin_clzll(q);
	if(max(x,y)>40){
		cout<<impossible<<endl;
		return;
	}
	
	int res=0;
	for(;p<q;p*=2,res++);
	cout<<res<<endl;
}

int main()
{
	int T; scanf("%d",&T);
	rep(i,T){
		printf("Case #%d: ",i+1);
		solve();
	}
	
	return 0;
}
