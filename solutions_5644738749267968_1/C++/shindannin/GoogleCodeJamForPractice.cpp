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
#define NG (-1)


int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);

	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase<=T; ++testcase)
	 {
		 int N;
		 scanf("%d",&N);

		 vector <double> myBlocks, oppoBlocks;
		 for (int i = 0; i < N; ++i)
		 {
			 double tmp;
			 scanf("%lf",&tmp);
			 myBlocks.emplace_back(tmp);
		 }
		 for (int i = 0; i < N; ++i)
		 {
			 double tmp;
			 scanf("%lf",&tmp);
			 oppoBlocks.emplace_back(tmp);
		 }
		 sort(myBlocks.begin(),myBlocks.end());
		 sort(oppoBlocks.begin(),oppoBlocks.end());

		 int cheatWin = 0;
		 int noCheatWin = 0;

		 for(int x=0;x<2;x++)
		 {
			 int lose = 0;

			 int k = 0;
			 for(int i=0;i<N;i++)
			 {
				 while(k<N)
				 {
					 if(myBlocks[i]<oppoBlocks[k])
					 {
						 lose++;
						 k++;
						 break;
					 }
					 k++;
				 }
			 }

			 const int win = N-lose;

			 if(x==0)
			 {
				 noCheatWin = win;
			 }
			 else
			 {
				 cheatWin = lose;
			 }

			 swap(myBlocks,oppoBlocks);
		 }

		 fprintf(stderr,"Case #%d: %d %d\n",testcase,cheatWin,noCheatWin);
		 printf("Case #%d: %d %d\n",testcase,cheatWin,noCheatWin);

	 }

	 return 0;
}
