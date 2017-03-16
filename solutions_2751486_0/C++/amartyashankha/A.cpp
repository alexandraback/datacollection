#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
 
using namespace std;
 
#define s(n)                                 	scanf("%d",&n)
#define sl(n)                                   scanf("%lld",&n)
#define sf(n)                                   scanf("%lf",&n)
 
#define EPS                                     (1e-9)
 
#define FOR(i,a,b)                              for(int i=a;i<b;i++)
#define REP(i,n)                                FOR(i,0,n)
#define foreach(v,c)            				for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
 
#define mp                                              make_pair
#define pb                                              push_back
 
#define FF                                              first
#define SS                                              second
 
#define tri(a,b,c)                              mp(a,mp(b,c))
#define XX                                              first
#define YY                                              second.first
#define ZZ                                              second.second
 
/*Important ones*/
#define fill(a,v)                               memset(a,v,sizeof a)     //Works properly only for v = 0 or -1
#define all(x)                                  x.begin(),x.end()
 
#define SZ(v)                                   ((int)(v.size()))
#define DREP(a)                                 sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)                  (lower_bound(all(arr),ind)-arr.begin())
 
//typedefs. Use if you feel comfortable
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef pair< int, PII > TRI;

typedef vector<int> VI;
typedef long long LL;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
 
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

#define MAX 1000010
#define INF (1e9)
#define psum(i, j)		(pref[j]-pref[i-1])

LL tests, ans, N, L, arr[MAX], pref[MAX], vow[MAX];
string str;
VI strt;

int main(){
	
	sl(tests);
	vow[0] = 1;
	vow[4] = 1;
	vow[8] = 1;
	vow[14] = 1;
	vow[20] = 1;
	FOR(tst,0,tests){
		str.resize(0);
		cin >> str;
		sl(N);
		L = SZ(str);
		pref[0] = 0;
		FOR(i,0,L){
			if(vow[str[i]-'a'])
				arr[i] = 0;
			else 
				arr[i] = 1;
		}
		int t = 0;
		strt.resize(0);
		for(int i = L-1 ; i >= 0 ; --i){
			if(!arr[i])
				t = 0;
			else
				++t;
			if(t >= N)
				strt.pb(i);
		}
		reverse(all(strt));
		ans = 0;
		FOR(i,0,L){
			int tp = INDEX(strt, i);
			if(tp < SZ(strt)){
				tp = strt[tp]+N-1;
				ans += max(0LL, L-tp);
			}
		}
		cout<<"Case #"<<tst+1<<": "<<ans<<"\n";
	}
	
	return 0;
	
}
