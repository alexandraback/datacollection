#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8


inline void update(LL &a, LL b){
	if(a < b){ a = b; }
}


LL solve(){
	LL e, r, n;
	scanf("%lld%lld%lld", &e, &r, &n);
	vLL v(n);
	for(int i = 0; i < n; ++i){
		scanf("%lld", &v[i]);
	}

	map<LL,LL> mp1, mp2;
	map<LL,LL>::iterator it;
	mp1.insert(pll(e, 0));
	
	int s = e / r;

	for(int i = 0; i < n; ++i){
		LL to = max(0LL, e - r * (n - i - 1));
		
		mp2 = mp1;
		for(it = mp1.begin(); it != mp1.end(); ++it){
			update(mp2[0], it->second + v[i] * it->first);

			for(int j = 1; j <= s && j <= n; ++j){
				LL dif = it->first - (e - j * r);
				if(dif > 0){
					update(mp2[e - j * r], it->second + dif * v[i]);
				}
			}
		}
		mp1.clear();
		for(it = mp2.begin(); it != mp2.end(); ++it){
			update(mp1[min(it->first + r, e)], it->second);
		}
	}

	LL ans = 0;
	for(it = mp1.begin(); it != mp1.end(); ++it){
		update(ans, it->second);
	}

	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		printf("Case #%d: %lld\n", i, solve());
	}
}
