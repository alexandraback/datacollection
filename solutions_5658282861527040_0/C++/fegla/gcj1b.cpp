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
#include <string>
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
#define __typeof(x) auto
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
	virtual ~hashtemp() {
	}

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
int a,b,k;

long long mem[31][2][2][2];


long long get(int ind,bool aa,bool bb,bool kk)
{
	if(ind==-1)
		return 1;
	long long &r=mem[ind][aa][bb][kk];
	if(r!=-1)
		return r;
	int A,B,K;
	int aaa=!aa || (A=((a>>ind)&1));
	int bbb=!bb || (B=((b>>ind)&1));
	int kkk=!kk || (K=((k>>ind)&1));
	r=0;
	rep2(i,0,aaa)
		rep2(j,0,bbb)
			if((i&&j)<=kkk)
				r+=get(ind-1,aa && i==A,bb& j==B,kk && (i&&j)==K);
	return r;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("1.in", "rt", stdin);
	freopen("1.out", "wt", stdout);
#endif
	int tt,n;
	cin >> tt;
	rep2(t,1,tt)
	{
		cin>>a>>b>>k;
		a--,b--,k--;
		memset(mem,-1,sizeof mem);
		printf("Case #%d: %lld\n",t,get(30,1,1,1));

	}
	return 0;
}
