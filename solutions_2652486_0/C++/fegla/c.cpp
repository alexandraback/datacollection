/*
 TASK:
 LANG: C++
 */
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <bitset>
#include <cstring>
#include <climits>
#include <deque>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <ctime>
#include <valarray>
//#include "vc.h"
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif

template<class key>
struct hashtemp {

	enum {
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;
#ifndef M_PI
const long double M_PI=acos((long double)-1);
#endif
#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO = 0;
const long double INF = 1 / ZERO, EPSILON = 1e-12;
#define all(c) (c).begin(),(c).end()
#define rep2(i,a,b) for(int i=(a);i<=((int)b);++i)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define sz(v) ((int)((v).size()))
#define let(x,y) __typeof(y) x(y)

#define rrep(i,n) for(int  i=((int)n)-1;i>=0;--i)
#define rall(c) (c).rbegin(),(c).rend()
#define rrep2(i,a,b) for(int i=(a);i>=((int)b);--i)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define rep2d(i, j, v) rep(i, sz(v)) rep(j, sz(v[i]))
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define ABS(x) ((x)>=0?(x):-(x))
int R, N, M, K;
int arr[3];
int p[7];
map<vector<int>,double > mp;
void bt(int i) {
	if (i == N) {
		map<int,int> fq;
		rep(i,1<<N)
		{
			int pp=1;

			rep(j,N)
				if(1&(i>>j))
					pp*=arr[j];
			fq[pp]++;
		}
		double pp=0;
		rep(i,K)
			pp+=fq[p[i]]/(1.0*(1<<N));
		vector<int> v(arr,arr+N);
		sort(all(v));
		mp[v]+=pp/K;
	} else {
		rep2(j,2,M)
		{
			arr[i] = j;
			bt(i + 1);
		}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("1.in", "rt", stdin);
	freopen("1.out","wt",stdout);
#endif
	int t, tt = 1;
	cin >> t;
	while (t--) {
		cout << "Case #" << tt++ << ":\n";
		cin >> R >> N >> M >> K;
		while (R--) {
			mp.clear();
			rep(i,K)
				cin >> p[i];
			bt(0);
			vector<int> res;
			double dd=0;
			foreach(x,mp)
			{
				if(dd<x->second)
					dd=x->second,res=x->first;
			}
			rep(i,sz(res))
				cout<<res[i];
			cout<<endl;
		}

	}
	return 0;
}
