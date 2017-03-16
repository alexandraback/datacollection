#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:260108864")

#include <iostream>
#include <ctime>
#include <cstdio>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>
#include <iterator>
#include <bitset>
#include <sstream>
#include <numeric>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); ++i)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 2000000000
#define PI 3.141592653589
#define eps 0.000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

int h,n,m;
int C[105][105],F[105][105];
double d[105][105];

bool equal(double a, double b)
{
	return abs(a-b)<eps;
}

double toWait(double nowTime, pii inCell, pii toCell)
{
	double waterLevel(h-nowTime*10);
	if (waterLevel<0. || abs(waterLevel-0.)<eps) waterLevel=0.;
	if (C[toCell.X][toCell.Y]-F[toCell.X][toCell.Y]<50) return 1e9;
	if (C[inCell.X][inCell.Y]<F[toCell.X][toCell.Y]+50) return 1e9;
	if (F[inCell.X][inCell.Y]+50>C[toCell.X][toCell.Y]) return 1e9;
	double left(C[toCell.X][toCell.Y]-waterLevel-50.);
	if (left>0. || equal(left,0.)) return 0.;
	left=abs(left);
	return left/10.;
}

bool exists(int x, int y)
{
	if (x<0 || x>=n || y<0 || y>=m) return false;
	return true;
}

double Dijikstra(pii start, pii finish)
{
	priority_queue< pair< double, pii >, 
		vector< pair< double, pii > >,
		greater< pair< double, pii > > > q;
	q.push(mp(0.,start));
	rept(i,n)
		rept(j,m)
			d[i][j]=1000000000.;
	d[0][0]=0;
	while (!q.empty())
	{
		pii now(q.top().Y);
		double tm(q.top().X);
		q.pop();
		if (abs(d[now.X][now.Y]-tm)>eps) continue;
		if (now==finish) return tm;
		for (int i=-1; i<2; ++i)
		{
			for (int j=-1; j<2; ++j)
			{
				if (abs(i)==abs(j)) continue;
				if (exists(now.X+i,now.Y+j))
				{
					double willBe(tm+toWait(tm,now,mp(now.X+i,now.Y+j)));
					double waterLevel(h-willBe*10.);
					if (willBe!=0.)
					{
						if (waterLevel<0. || equal(waterLevel,0.)) waterLevel=0.;
						if (waterLevel>F[now.X][now.Y]+20 ||
							equal(waterLevel,F[now.X][now.Y]+20))
						{
							willBe+=1.;
						}
						else willBe+=10.;
					}
					if (d[now.X+i][now.Y+j]>willBe)
					{
						d[now.X+i][now.Y+j]=willBe;
						q.push(mp(willBe,mp(now.X+i,now.Y+j)));
					}
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	int tst;
	scanf("%d",&tst);
	rept(t,tst)
	{
		printf("Case #%d: ",t+1);
		scanf("%d%d%d",&h,&n,&m);
		rept(i,n)
			rept(j,m)
				scanf("%d",&C[i][j]);
		rept(i,n)
			rept(j,m)
				scanf("%d",&F[i][j]);
		printf("%.8lf\n",Dijikstra(mp(0,0),mp(n-1,m-1)));
	}
	return 0;
}