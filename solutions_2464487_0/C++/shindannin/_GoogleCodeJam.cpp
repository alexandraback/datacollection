// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <cstdio>
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
#include <complex>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;
static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
#define PI	(3.14159265358979323846)
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG (987654321)
#define SZ(a) ((int)a.size())
typedef long long ll;

#define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
// BEGIN CUT HERE
#undef FOR
#define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
// END CUT HERE

ll bsearch_false_max(ll lo, ll hi, const vector <bool>& p)
{
	// ※注意！ hiの値には要注意。大きめを値を入れたくなるけど、
	// - doubleなら桁落ちの危険性がある。
	// - midがint越えをすると、途中計算にmid*midとなっただけで死亡。
	// ちゃんと上限の値を入れること。

	while(lo<hi)
	{
		ll mid = lo+(hi-lo+1)/2LL; // +1 is necessary, otherwise infinite loop when only two elements.
		if(p[(int)mid])
		{
			hi=mid-1;
		}
		else
		{
			lo=mid;
		}
	}

	if (p[(int)lo])
	{
		lo=NG; // All true 
	}



	return lo;
}

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++)
	{
		ll r,t;
		cin >> r >> t;

		ll lo = 0;
		ll hi = (ll)1e9;

		while(lo<hi)
		{
			ll mid = lo+(hi-lo+1)/2LL; // +1 is necessary, otherwise infinite loop when only two elements.

			bool ok = false;
			if(2*mid*mid-mid<=t-2ll*mid*r)
			{
				ok = true;
			}

			if(!ok)
			{
				hi=mid-1;
			}
			else
			{
				lo=mid;
			}
		}

		printf("Case #%d: %lld\n",testcase+1,lo);
		
		NUKE:;
	}
}
