#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <cassert>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif

#define MOD 1000000007LL
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

map<string,int> ma;

void mainmain(){
	int T;
	cin >> T;
	reep(o,1,T+1){
		ma.clear();
		cout << "Case #" << o << ": ";
		int n;
		cin >> n;
		vector<string> va(n);
		vector<string> vb(n);
		int cnt = 0;
		rep(i,n){
			cin >> va[i] >> vb[i];
			if(ma.count(va[i])==0) ma[va[i]]=cnt++;
			if(ma.count(vb[i])==0) ma[vb[i]]=cnt++;
		}
		vector<pii> v(n);
		rep(i,n){
			v[i].F=ma[va[i]];
			v[i].S=ma[vb[i]];
		}
		vvint vv1(n);
		vvint vv2(n);
		rep(i,n){
			rep(j,n){
				if(v[i].F==v[j].F){
					vv1[i].PB(j);
					vv1[j].PB(i);
				}
				if(v[i].S==v[j].S){
					vv2[i].PB(j);
					vv2[j].PB(i);	
				}
			}
		}
		vint dp(1<<n,0);
		rep(i,1<<n){
			rep(j,n){
				if((1<<j)&i) continue;
				bool f1 = false;
				bool f2 = false;
				for(int x:vv1[j]){
					if((1<<x)&i) f1=true;
				}
				for(int x:vv2[j]){
					if((1<<x)&i) f2=true;
				}
				maxs(dp[i+(1<<j)],dp[i]+(f1&&f2));
			}
		}
		cout<<dp[(1<<n)-1]<<endl;
	}
	
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}