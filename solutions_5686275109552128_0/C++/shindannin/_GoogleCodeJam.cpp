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
#include "assert.h"

using namespace std;
static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
template<class T> void amin(T &a,T v){if(a>v) a=v;}
template<class T> void amax(T &a,T v){if(a<v) a=v;}
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

#define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);


#if 1

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d",&T);

	for (int testcase = 0; testcase < T; testcase++)
	{
		int D;
		cin >> D;
		vector <int> P(D);

		for (int i = 0; i < D; ++i)
		{
			cin >> P[i];
		}

		const int MAX_NUM_PANCAKE = *max_element(P.begin(),P.end());

		int best = BIG;

		for (int maxCake = 1; maxCake <= MAX_NUM_PANCAKE; ++maxCake)
		{
			int move = 0;
			for (int i = 0; i < SZ(P); ++i)
			{
				int d = P[i]-maxCake;
				if(d>0)
				{
					move += (d+maxCake-1)/maxCake;
				}
			}

			amin(best,move+maxCake);
		}

		PRINTF("Case #%d: %d\n",testcase+1, best);
	}

	return 0;
}


#else

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d",&T);

	for (int testcase = 0; testcase < T; testcase++)
	{
		int smax;
		string s;
		cin >> smax >> s;

		int standing = 0;
		int ans = 0;
		for (int k = 0; k < smax+1; ++k)
		{
			int delta = max(0,k-standing);

			standing += delta + (s[k]-'0');
			ans += delta;
		}


		PRINTF("Case #%d: %d\n",testcase+1, ans);
	}

	return 0;
}

#endif