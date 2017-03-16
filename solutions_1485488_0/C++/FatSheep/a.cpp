

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
//#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#define eps 1e-12
#define MAX 1000000000
using namespace std;


double dp[2][101][101][1001];
bool in[2][101][101][1001];
int c[101][101];
int f[101][101];

struct node
{
	int down;
	int x,y,h;
	double step;
};

int main()
{
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases=1;
	int d[4][2]={-1,0,1,0,0,-1,0,1};
	int i,j,k,m,n,h;
	int re;
	cin>>re;
	while(re--)
	{
		cin>>h>>m>>n;
	
		memset(dp,0,sizeof(dp));
		for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		for(k=0;k<=h;k++)
		dp[0][i][j][k]=dp[1][i][j][k]=MAX;
		dp[0][0][0][h]=0;
		
		
		for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&c[i][j]);
		
		for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&f[i][j]);
			
		node ss,tt;
		ss.x=0;
		ss.y=0;
		ss.h=h;
		ss.step=0;
		ss.down=0;
		in[ss.down][ss.x][ss.y][ss.h]=true;
		queue <node> q;
		q.push(ss);
		double ans=MAX;
		while(!q.empty())
		{
			ss=q.front();
			q.pop();
			//cout<<ss.x<<" "<<ss.y<<" "<<ss.h<<" "<<ss.step<<endl;
			
			in[ss.down][ss.x][ss.y][ss.h]=false;
			ss.step=dp[ss.down][ss.x][ss.y][ss.h];
			
			if(ss.x==m-1&&ss.y==n-1)
				ans=min(ans,ss.step);
			for(i=0;i<4;i++)
			{
				tt.x=ss.x+d[i][0];
				tt.y=ss.y+d[i][1];
				tt.step=ss.step;
				tt.h=ss.h;
				tt.down=ss.down;
				if(tt.x<0||tt.x==m||tt.y<0||tt.y==n)
					continue;
				if(c[tt.x][tt.y]-f[tt.x][tt.y]<50)
					continue;
				
				if(c[tt.x][tt.y]-f[ss.x][ss.y]<50)
					continue;
			
				if(c[ss.x][ss.y]-f[tt.x][tt.y]<50)
					continue;
				
				if(c[tt.x][tt.y]-ss.h<50)//need to wait
				{
					tt.down=true;
					double th=50-(c[tt.x][tt.y]-ss.h);
					tt.h-=th;
					tt.step+=th/10;
				}
				
				if(tt.down)
				{
				if(tt.h-f[ss.x][ss.y]>=20)//1sec
				{
					tt.h-=10;
					tt.h=max(tt.h,0);
					tt.step+=1;
				}
				else//10sec
				{
					tt.h-=10*10;
					tt.h=max(tt.h,0);
					tt.step+=10;
				}
				}
			
				
				if(tt.step<dp[tt.down][tt.x][tt.y][tt.h])
				{
					dp[tt.down][tt.x][tt.y][tt.h]=tt.step;
					if(!in[tt.down][tt.x][tt.y][tt.h])
					{
						in[tt.down][tt.x][tt.y][tt.h]=true;
						q.push(tt);
					}
				}
			}
			
			
			
		}
		
		printf("Case #%d: %.7lf\n",cases++,ans);
			
	}
	
}