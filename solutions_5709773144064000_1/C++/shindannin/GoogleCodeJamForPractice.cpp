// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <tchar.h>
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
using namespace std;

typedef long long ll;

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())

int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);

	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase <= T; ++testcase)
	 {
		 double C,F,X;
		 scanf("%lf %lf %lf",&C,&F,&X);

		 double bestTime = DBL_MAX;

		 double time = 0;
		 double velocity = 2.0;
		 double lastTime = DBL_MAX;
		 for (int numFarms = 0; ; ++numFarms)
		 {
			 const double dt = X/velocity;

			 amin(bestTime,time+dt);
			 if(time+dt>lastTime)
			 {
				 break;
			 }
			 else
			 {
				 lastTime = time+dt;
			 }

			 time += C/velocity;
			 velocity += F;

		 }

		 printf("Case #%d: %.20f\n",testcase, bestTime);
	}

	return 0;
}
