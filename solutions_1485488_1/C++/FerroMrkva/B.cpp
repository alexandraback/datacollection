#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

#define MX 105

int tt;
int h,n,m;
int F[MX][MX];
int C[MX][MX];
int V[MX][MX];
set<pair<double,pair<int,int> > > Q;

void go(int x,int y,int f,int c)
{
	if (x<0||x>=n||y<0||y>=m) return;
	if (f>C[x][y]-50||F[x][y]>C[x][y]-50||h>C[x][y]-50) return;
	if (F[x][y]>c-50) return;
	if (V[x][y]) return;
	V[x][y]=1;
	Q.insert(make_pair(0,make_pair(x,y)));
	go(x-1,y,F[x][y],C[x][y]);
	go(x+1,y,F[x][y],C[x][y]);
	go(x,y-1,F[x][y],C[x][y]);
	go(x,y+1,F[x][y],C[x][y]);
}

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

double solve()
{
	while(Q.size()>0)
	{
		pair<double,pair<int,int> > top=*Q.begin();
		Q.erase(top);
		int x=top.second.first;
		int y=top.second.second;
		double cas=top.first;
		//printf("%lf %d %d\n",cas,x,y);
		if (x==n-1&&y==m-1)
			return cas;
		V[x][y]=1;
		for(int i=0;i<4;++i)
		{
			int x2=x+dir[i][0];
			int y2=y+dir[i][1];
			if (x2<0||x2>=n||y2<0||y2>=m) continue;
			double h2=h-cas*10;
			double cas0=cas;
			if (F[x][y]>C[x2][y2]-50||F[x2][y2]>C[x2][y2]-50)
				continue;
			if (F[x2][y2]>C[x][y]-50)
				continue;
			if (V[x2][y2])
				continue;
			if (h2>C[x2][y2]-50)
			{
				h2=C[x2][y2]-50;
				cas0=(h-h2)/(double)10;
			}
			double cas2;
			if (h2>=F[x][y]+20)
				cas2=cas0+1;
			else
				cas2=cas0+10;
			Q.insert(make_pair(cas2,make_pair(x2,y2)));
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&tt);
	for(int t=1;t<=tt;++t)
	{
		Q.clear();
		scanf("%d%d%d",&h,&n,&m);
		memset(V,0,sizeof V);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
				scanf("%d",C[i]+j);
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
				scanf("%d",F[i]+j);
		}
		go(0,0,F[0][0],C[0][0]);
		printf("Case #%d: %.9lf\n",t,solve());
	}
	return 0;
}
