#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
#pragma comment(linker, "/STACK:167772160")

#define sz(x) int((x).size())
const int inf = 1000000000;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
typedef long long Int;

int c[1001][1001],f[1001][1001];
double D[1001][1001];
set< pair<double,pair<int,int> > >q;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tes;
	cin>>tes;
	FOR(o,1,tes)
	{
		int n,m;
		double h;
		cin>>h>>n>>m;
		FOR(i,1,n)
			FOR(j,1,m)cin>>c[i][j];
		FOR(i,1,n)
			FOR(j,1,m)cin>>f[i][j];

		FOR(i,1,n)
			FOR(j,1,m)D[i][j]=inf;

		q.clear();
		D[1][1]=0;
		q.insert(mp(0,mp(1,1)));
		for(;;)
		{
			if(q.empty())break;
			int x=(*q.begin()).second.first,y=(*q.begin()).second.second;
			q.erase(*q.begin());
			FOR(ii,-1,1)
			FOR(jj,-1,1)
			if(abs(ii)+abs(jj)==1 && x+ii<=n && x+ii>=1 && y+jj<=m && y+jj>=1)
			{
				int xx=x+ii,
					yy=y+jj;

				if(f[x][y]<=c[xx][yy]-50 && h<=c[xx][yy]-50 && f[xx][yy]<=c[xx][yy]-50 && f[xx][yy]<=c[x][y]-50)
				{
					if(D[x][y]<D[xx][yy])
					{
						q.erase(mp(D[xx][yy],mp(xx,yy)));
						D[xx][yy]=D[x][y];
						q.insert(mp(D[xx][yy],mp(xx,yy)));
					}
				}
			}
		}

		q.clear();
		FOR(i,1,n)
		FOR(j,1,m)
		if(D[i][j]==0)q.insert(mp(0,mp(i,j)));

		for(;;)
		{
			if(q.empty())break;
			int x=(*q.begin()).second.first,y=(*q.begin()).second.second;
			q.erase(*q.begin());
			
			FOR(ii,-1,1)
			FOR(jj,-1,1)
			if(abs(ii)+abs(jj)==1 && x+ii<=n && x+ii>=1 && y+jj<=m && y+jj>=1)
			{
				int xx=x+ii,
					yy=y+jj;

				if(f[x][y]<=c[xx][yy]-50 && f[xx][yy]<=c[xx][yy]-50 && f[xx][yy]<=c[x][y]-50)
				{
					double wait;
					if(h-10*D[x][y]<=c[xx][yy]-50)wait=0;else
						wait=((h-10*D[x][y])-(c[xx][yy]-50))/10.0;
					double tt;
					if(h-10*(D[x][y]+wait) - 20 >= f[x][y])tt=1;else
						tt=10;

					if(D[x][y] + wait + tt <D[xx][yy])
					{
						q.erase(mp(D[xx][yy],mp(xx,yy)));
						D[xx][yy]=D[x][y]+wait+tt;
						q.insert(mp(D[xx][yy],mp(xx,yy)));
					}
				}
			}
		}


		cout<<"Case #"<<o<<": ";
		printf("%.7f\n",D[n][m]);
	}
	
	return 0;
}