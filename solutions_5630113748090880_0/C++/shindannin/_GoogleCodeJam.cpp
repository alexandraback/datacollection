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
#include <unordered_map>
#include "assert.h"

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x,T a,T b){return a<=x&&x<=b;}
template<class T> void amin(T &a,T v){if(a>v) a=v;}
template<class T> void amax(T &a,T v){if(a<v) a=v;}
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;

#define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);


#if 1

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		int N;
		scanf("%d ",&N);

		vector <int> freq(3000);

		for (int i = 0; i < 2*N-1; ++i)
		{
			for (int k = 0; k < N; ++k)
			{
				int tmp;
				scanf("%d ",&tmp);

				freq[tmp]++;
			}
		}

		vector <int> ans;
		for (int i = 0; i < SZ(freq); ++i)
		{
			if(freq[i]%2==1)
			{
				ans.push_back(i);
			}
		}
		sort(ans.begin(),ans.end());

		PRINTF("Case #%d:",testcase+1);
		for (int i = 0; i < SZ(ans); ++i)
		{
			PRINTF(" %d",ans[i]);
		}
		PRINTF("\n");
	}

	return 0;
}


#else
int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		string s, ans;
		cin >> s;

		for (int i = 0; i < SZ(s); ++i)
		{
			string a1, a2;

			a1 = ans + s[i];
			a2 = s[i] + ans;
			if(a1>a2)
			{
				ans = a1;
			}
			else
			{
				ans = a2;
			}
		}


		PRINTF("Case #%d: %s\n",testcase+1, ans.c_str());
	}

	return 0;
}
#endif