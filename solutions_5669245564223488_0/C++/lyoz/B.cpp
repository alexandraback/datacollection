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

void solve_naive(vs ts)
{
	int n=ts.size();
	vi p(n); iota(all(p),0);
	
	for(auto& t:ts)
		t.erase(unique(all(t)),end(t));
	
	int len;
	{
		set<char> occ;
		for(char c:accumulate(all(ts),string()))
			occ.emplace(c);
		len=occ.size();
	}
	
	int res=0;
	do{
		string s;
		for(int i:p) s+=ts[i];
		s.erase(unique(all(s)),end(s));
		if(s.size()==len) res++;
	}while(next_permutation(all(p)));
	cout<<res<<endl;
}

void solve()
{
	int n; cin>>n;
	vs ts(n);
	rep(i,n) cin>>ts[i];
	solve_naive(ts);
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
