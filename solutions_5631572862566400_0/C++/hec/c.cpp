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
const int limit=2510;


int main(void){
	int T;
	cin >> T;	
	rep(testcase,1,T+1){
		int n;
		cin >> n;
		vector<int> bid(n);
		rep(i,n) cin >> bid[i],bid[i]--;

		vector<int> ary(n);
		rep(i,n) ary[i]=i;
		int ans=0;

		do{
			vector<int> ok(n);
			rep(i,n){
				int prv=i-1,nxt=i+1;
				if(prv>=0 && bid[ary[i]] == ary[prv]) ok[i]=true;
				if(nxt<n  && bid[ary[i]] == ary[nxt]) ok[i]=true;
			}
			rep(cur,2,n+1){
				bool hasans=true;
				rep(i,1,cur-1) if(ok[i]==false) hasans=false;
				if(bid[ary[0]]!=ary[cur-1]&& bid[ary[0]]!=ary[1]) hasans=false;
				if(bid[ary[cur-1]]!=ary[0]&& bid[ary[cur-1]]!=ary[cur-2]) hasans=false;
				if(hasans) chmax(ans,cur);
			}
		}while(next_permutation(_all(ary)));

		cout << "Case #" << testcase << ": " << ans << endl;
	}
	return 0;
}