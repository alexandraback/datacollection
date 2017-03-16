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

bool kenzan(int H, int W, int i)
{
	const int starty = H-1;
	const int startx = W-1;

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
					{
						printf(".");
					}
				}
			}
			printf("\n");
		}

		return true;
	}

	printf("Test Impossible\n");
	return false;
}


int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);

	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase<=T; ++testcase)
	 {
		 bool possible = false;
		 int ans[55]={};

		 int H,W,M;
		 fprintf(stderr,"Case #%d:\n",testcase);
		 printf("Case #%d:\n",testcase);
		 scanf("%d %d %d",&H,&W,&M);
		 vector <vector < vector <int> > > dp(H+1, vector < vector <int> > (W+1, vector<int>(M+1,NG)));

		 if(H*W==M)
		 {
			 possible = false;
		 }
		 else if (H*W-1==M)
		 {
			 possible = true;
			 for (int y = 0; y < H; ++y)
			 {
				 if(y<H-1)
				 {
					 ans[y]=W;
				 }
				 else
				 {
					 ans[y]=W-1;
				 }

			 }
		 }
		 else
		 {
			 for (int x = 0; x <= W; ++x)
			 {
				 dp[0][x][M]=0;
			 }


			 for (int y = 0; y < H; ++y)
			 {
				 for (int x = 0; x <= W; ++x)
				 {
					 if(W>1 && x==W-1) continue;

					 for(int m=0; m<=M; ++m)
					 {
						 if(dp[y][x][m]!=NG)
						 {

							 for (int nx = 0; nx <= x; ++nx)
							 {
								 if(W>1 && nx==W-1) continue;
								 if(y==H-1 && nx!=x) continue;

								 const int nm = m-nx;
								 if(nm>=0)
								 {
									 amax(dp[y+1][nx][nm],x);
								 }
							 }
						 }
					 }
				 }
			 }

			 for(int x=0;x<=W;++x)
			 {
				 if(dp[H][x][0]!=NG)
				 {
					 int nowx = x;
					 int nowm = 0;
					 for (int y = H-1; y >= 0; --y)
					 {
						 ans[y] = nowx;
						 nowx = dp[y+1][nowx][nowm];
						 nowm += ans[y];
						 possible = true;
					 }
					 break;
				 }
			 }

		 }


		 if(possible)
		 {
			 int kenzan_i = 0;
			 for (int y = 0; y < H; ++y)
			 {
				 string s;
				 s += string(ans[y],'*');
				 s += string(W-ans[y],'.');
				 if(y==H-1)
				 {
					 s[W-1]='c';
				 }
				 printf("%s\n",s.c_str());

				 for (int x = 0; x < ans[y]; ++x)
				 {
					 kenzan_i |= (1<<(y*W+x));
				 }
			 }
		 }
		 else
		 {
			 printf("Impossible\n");
		 }


	 }

	 return 0;
}
