#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

using namespace std;
set <pair<double, pair<int,pnt > > > s;
double d[11][11][1010];
int f[11][11];
int c[11][11];
int dx[]={0,0,1,-1,0};
int dy[]={1,-1,0,0,0};
int n,m,h;
bool can()
{
	s.clear();
		FOR(i,0,11)
			FOR(j,0,11)
				FOR(k,0,1010)
					d[i][j][k]=2000000000.0;
		d[0][0][h]=0;
		s.insert(mp(0,mp(h,mp(0,0))));
		double res=0;
		while (s.size())
		{
			int ch=s.begin()->second.first;
			int x=s.begin()->second.second.first;
			int y=s.begin()->second.second.second;
			if ((x==n-1) && (y==m-1))
			{
				return true;
			}
			s.erase(s.begin());
			FOR(k,0,4)
			{
				int nx=x+dx[k];
				int ny=y+dy[k];
				if ((nx<0) || (ny<0) || (nx>=n) || (ny>=m))
					continue;
				double t=0;
				if ((c[nx][ny]-ch<50) || (c[nx][ny]-f[x][y]<50) || (c[nx][ny]-f[nx][ny]<50) || (c[x][y]-f[nx][ny]<50))
					continue;
				else
				{
					double nt=d[x][y][ch];
					int nh=ch;
					if (d[x][y][ch]+t<d[nx][ny][nh])
					{
						s.erase(mp(d[nx][ny][nh],mp(nh,mp(nx,ny))));
						d[nx][ny][nh]=d[x][y][ch]+t;
						s.insert(mp(d[nx][ny][nh],mp(nh,mp(nx,ny))));
					}
				}
			}
		}
	return false;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	FOR(it,1,t+1)
	{
		scanf("%d%d%d",&h,&n,&m);
		FOR(i,0,n)
			FOR(j,0,m)
				scanf("%d",&c[i][j]);
		FOR(i,0,n)
			FOR(j,0,m)
				scanf("%d",&f[i][j]);
		//if (can())
		//{
		//	double res=0;
		//	printf("Case #%d: %.10lf\n",it,0);
		//	continue;
		//}
		s.clear();
		FOR(i,0,11)
			FOR(j,0,11)
				FOR(k,0,1010)
					d[i][j][k]=2000000000.0;
		d[0][0][h]=0;
		s.insert(mp(0,mp(h,mp(0,0))));
		double res=0;
		while (s.size())
		{
			int ch=s.begin()->second.first;
			int x=s.begin()->second.second.first;
			int y=s.begin()->second.second.second;
			if ((x==n-1) && (y==m-1))
			{
				res=s.begin()->first;
				break;
			}
			s.erase(s.begin());
			FOR(k,0,5)
			{
				int nx=x+dx[k];
				int ny=y+dy[k];
				if ((nx<0) || (ny<0) || (nx>=n) || (ny>=m))
					continue;
				double t=0;
				if ((x==nx) && (y==ny))
				{
					int nh=ch-1;
					if (nh<f[nx][ny])
						continue;
					t=0.1;
					if (d[x][y][ch]+t<d[nx][ny][nh])
					{
						s.erase(mp(d[nx][ny][nh],mp(nh,mp(nx,ny))));
						d[nx][ny][nh]=d[x][y][ch]+t;
						s.insert(mp(d[nx][ny][nh],mp(nh,mp(nx,ny))));
					}
				}
				if ((c[nx][ny]-ch<50) || (c[nx][ny]-f[x][y]<50) || (c[nx][ny]-f[nx][ny]<50) || (c[x][y]-f[nx][ny]<50))
					continue;
				else
				{
					if ((x==1) && (y==2))
					{
						int k=1;
					}
					if ((nx==1) && (ny==2))
					{
						int k=1;
					}
					if (ch-f[x][y]>=20)
						t=1;
					else
						t=10;
					if (ch==h)
						t=0;
					double nt=d[x][y][ch]+t;
					double nnh=MAX(f[x][y],h-nt*10);
					int nh=(int)(nnh+1e-9);
					if (d[x][y][ch]+t<d[nx][ny][nh])
					{
						s.erase(mp(d[nx][ny][nh],mp(nh,mp(nx,ny))));
						d[nx][ny][nh]=d[x][y][ch]+t;
						s.insert(mp(d[nx][ny][nh],mp(nh,mp(nx,ny))));
					}
				}
			}
		}
		printf("Case #%d: %.10lf\n",it,res);
	}
	return 0;
}