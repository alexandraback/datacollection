#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;
using ll=long long;


const ll limit=1000000;
bool prime[limit+1];

void init(){
	rep(i,limit+1) prime[i]=true;
	prime[0]=prime[1]=false;
	for(ll i=2;i*i<=limit;++i){
		if(prime[i])
			for(ll j=i*i;j<=limit;j+=i)
				prime[j]=false;
	}
	return;
}

bool check(int n,int mask){
	vector<int> ans;
	rep(base,2,11){
		ll cur=0LL;
		rep(i,n) cur=cur*base+((mask>>i)&1);
		
		bool ok=false;
		for(ll f=2LL;f*f<=min<ll>(cur,limit*limit);++f){
			if(prime[f]==false) continue;
			if(cur%f!=0) continue;
			ans.push_back(f),ok=true;
			if(ok) break;
		}
		if(ok==false) return false;
	}
	rep(i,n) cout << ((mask>>i)&1);
	cout << " ";
	rep(i,ans.size()) cout << (i?" ":"") << ans[i];
	cout << endl;
	return true;
}

int main(void){
	init();
	int T;
	cin >> T;
	rep(testcase,1,T+1){
		int n,j;
		cin >> n >> j;
		cout << "Case #" << testcase << ":" << endl;
		const ll all=1<<n;
		rep(mask,all/2,all){
			if(mask%2==0) continue;
			if(check(n,mask)) j--;
			cerr << j << endl;
			if(j==0) return 0;
		}
	}
	return 0;
}