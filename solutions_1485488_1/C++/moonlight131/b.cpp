#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

using namespace std;

#define maxn 1100
#define maxm 1100000
#define eps 1e-10
#define inf 1000000000

struct In
{
	int x,y;
	double t;
	friend bool operator <(In a,In b)
	{
		return a.t>b.t;
	}
};
double dp[maxn][maxn];
int c[maxn][maxn],f[maxn][maxn];
priority_queue<In>q;
int addx[]={0,0,1,-1};
int addy[]={1,-1,0,0};
int main()
{
	int i,j,t,ca,n,m,k;
	double x,h;
	In s1,s2,s3;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%lf%d%d",&h,&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&c[i][j]);
			}
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&f[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				dp[i][j]=1e20;
		dp[0][0]=0.0;
		while(!q.empty())q.pop();
		s1.x=s1.y=0;
		s1.t=0.0;
		q.push(s1);
		while(!q.empty())
		{
			s1=q.top();
			s3=s1;
			//cout<<s1.x<<" "<<s1.y<<" "<<s1.t<<endl;
			q.pop();
			if(fabs(s1.t-dp[s1.x][s1.y])>eps)continue;
			for(k=0;k<4;k++)
			{
				s1=s3;
				s2.x=s1.x+addx[k];
				s2.y=s1.y+addy[k];
				if(s2.x<0||s2.y<0||s2.x>=n||s2.y>=m)continue;
				if(c[s1.x][s1.y]-f[s2.x][s2.y]<50)continue;
				if(c[s2.x][s2.y]-f[s2.x][s2.y]<50)continue;
				if(c[s1.x][s1.y]-f[s1.x][s1.y]<50)continue;
				if(c[s2.x][s2.y]-f[s1.x][s1.y]<50)continue;
				x=c[s1.x][s1.y]-(h-s1.t*10.0);
				if(x<50.0)s1.t+=(50.0-x)/10.0;
			//	cout<<s1.t<<endl;
				x=c[s2.x][s2.y]-(h-s1.t*10.0);
				if(x<50.0)s1.t+=(50.0-x)/10.0;
			//	cout<<s1.t<<endl;
				if(s1.t<eps)s2.t=0.0;
				else if(h-10.0*s1.t-f[s1.x][s1.y]+eps>=20.0)s2.t=s1.t+1.0;
				else s2.t=s1.t+10.0;
				if(s2.t+eps<dp[s2.x][s2.y])
				{
					dp[s2.x][s2.y]=s2.t;
					q.push(s2);
				}
			}
		}
		printf("%.6lf\n",dp[n-1][m-1]);
	}
}
