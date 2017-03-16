#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
using namespace std;
int c[100][100],f[100][100],z[100][100];
struct st
{
	st(int ii, int jj, int tt)
	{
		i=ii,j=jj,t=tt;
	}
	int i,j,t;
	bool operator< (const st &a) const
	{
		return t > a.t;
	}
};
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt)
	{
		int h,n,m;
		scanf("%d%d%d",&h,&n,&m);
		for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j)scanf("%d",c[i]+j);
		for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j)scanf("%d",f[i]+j);
		memset(z,0x7f,sizeof(z));
		z[0][0]=0;
		priority_queue<st> p;
		p.push(st(0,0,0));
		int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		while(!p.empty())
		{
			st d=p.top();
			p.pop();
			if(d.t>z[d.i][d.j])continue;
			for(int i = 0;i<4;++i)
			{
				int x=d.i+fx[i][0],y=d.j+fx[i][1];
				if(x>=0&&y>=0&&x<n&&y<m)
				{
					int ff=max(f[d.i][d.j],f[x][y]);
					int cc=min(c[d.i][d.j],c[x][y]);
					int txy=d.t;
					if(ff+50>cc)
					{
						continue;
					}
					if(h-d.t+50>cc)
					{
						txy=h+50-cc;
					}
					else
					{
						txy=d.t;
					}
					if(txy>0)
					{
						if(h-txy>=f[d.i][d.j]+20)txy+=10;
						else txy+=100;
					}
					if(txy<z[x][y])
					{
						z[x][y]=txy;
						p.push(st(x,y,txy));
					}
				}
			}
		}
		printf("Case #%d: %lf\n",tt,z[n-1][m-1]/10.0);
	}
	return 0;
}
