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
struct hashtemp
{

	enum
	{
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};

using namespace std;
#ifndef M_PI
const long double M_PI=acos((long double)-1);
#endif
#define rep(i,n) for(int  i=0;i<(int)(n);++i)
long double ZERO=0;
const long double INF=1/ZERO,EPSILON=1e-12;
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


int main() {
std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("1.in","rt",stdin);
	freopen("1.out","wt",stdout);
#endif
	int t,tt=1;
	cin>>t;
	while(t--)
	{
		set<int> locs,val;
		string str;
		string v="aeiou";
		int n;
		cin>>str>>n;
		rep(i,sz(str))
			if(v.find(str[i])!=-1)
				locs.insert(i);
	//	locs.insert(0);
		locs.insert(str.size());
		long long res=0;

		rep(s,sz(str))
		{
			int e=s+n-1;
			int x=*locs.lower_bound(s);
			if(x>e)
				val.insert(e);
		}
		rep(s,sz(str))
		{
			set<int>::iterator it=val.lower_bound(s+n-1);
			if(it!=val.end())
				res+=sz(str)-*it;
		}
		cout<<"Case #"<<tt++<<": "<<res<<endl;
	}
	return 0;
}
