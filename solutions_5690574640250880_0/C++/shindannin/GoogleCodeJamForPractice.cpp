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

int NumBit(int a)
{
	int ret=0;
	while(a) {
		a = a & (a-1);
		ret++;
	}
	return ret;
}

int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);

	 int T;
	 scanf("%d",&T);

//	 int testcase = 0;

//	 for(int H=2;H<=5;H++) for(int W=2;W<=5;W++) for(int M=0;M<=H*W;M++)

	 for (int testcase = 1; testcase<=T; ++testcase)
	 {
//		 testcase++;
		 printf("Case #%d:\n",testcase);

		 int H,W,M;
//		 printf("H=%d W=%d M=%d\n",H,W,M);
		 scanf("%d %d %d",&H,&W,&M);



		 for (int i = 0; i < 1<<(H*W); ++i)
		 {
			 if(NumBit(i)!=M) continue;

			 for (int starty = 0; starty < H; ++starty)
			 {
				 for (int startx = 0; startx < W; ++startx)
				 {
					 if(!(i & (1<<(starty*W+startx))))
					 {
						 vector < vector < int > > state( H, vector <int> (W, NG) );

						 queue < pair <int, int> > q;
						 q.push(make_pair(starty,startx));
						 while(!q.empty())
						 {
							 const pair <int, int> a = q.front();
							 q.pop();

							 int countbomb = 0;
							 for (int dy = -1; dy <= 1; ++dy)
							 {
								 for (int dx = -1; dx <= 1; ++dx)
								 {
									 if(!(dy==0 && dx==0))
									 {
										 const int nowy = a.first+dy;
										 const int nowx = a.second+dx;

										 if(INRANGE(nowy,0,H-1)&&INRANGE(nowx,0,W-1)&&(i&(1<<(nowy*W+nowx))))
										 {
											 countbomb++;
										 }
									 }
								 }
							 }

							 state[a.first][a.second]=countbomb;
							 if(countbomb==0)
							 {
								 for (int dy = -1; dy <= 1; ++dy)
								 {
									 for (int dx = -1; dx <= 1; ++dx)
									 {
										 const int nowy = a.first+dy;
										 const int nowx = a.second+dx;

										 if(!(dy==0 && dx==0)&&INRANGE(nowy,0,H-1)&&INRANGE(nowx,0,W-1)&&state[nowy][nowx]==NG)
										 {
											 q.push(make_pair(nowy,nowx));
										 }
									 }
								 }
							 }
						 }

						 bool ok = true;
						 for (int y = 0; y < H; ++y)
						 {
							 for (int x = 0; x < W; ++x)
							 {
								 if(state[y][x]==NG && !(i&(1<<(y*W+x))))
								 {
									 ok = false;
								 }
							 }
						 }

						 if(ok)
						 {
							 for (int y = 0; y < H; ++y)
							 {
								 for (int x = 0; x < W; ++x)
								 {
									 if (y==starty && x==startx)
									 {
										 printf("c");
									 }
									 else if(i & (1<<(y*W+x)))
									 {
										 printf("*");
									 }
									 else
									 {
										 /*
										 if(state[y][x]>0)
										 {
											 printf("%d",state[y][x]);
										 }
										 else
										 */
										 {
											 printf(".");
										 }
									 }
								 }
								 printf("\n");

							 }
    						goto NUKE;
						 }
					 }
				 }
			 }
		 }

		 printf("Impossible\n");

		NUKE:;

	}

	return 0;
}
