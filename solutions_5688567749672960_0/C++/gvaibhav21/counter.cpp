#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int dp[1000010];
bool mark[1000010];
void bfs(int st)
{
	int r,d,n1;
	pair<int,int> p;
	queue<pair<int,int> > q;
	q.push(MP(1,1));
	mark[1]=1;
	dp[1]=1;
	while(!q.empty())
	{
		//cout<<"yoyo";
		p=q.front();
		dp[p.F]=p.S;
		q.pop();
		if((!mark[p.F+1])&&p.F+1<=1000000)
		{
			mark[p.F+1]=1;
			q.push(MP(p.F+1,p.S+1));
		}
		r=0;
		n1=p.F;
		while(n1)
		{
			r=r*10+n1%10;
			n1/=10;
		}
		if(!mark[r])
		{
			mark[r]=1;
			q.push(MP(r,p.S+1));
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,t,i,j;
	for(j=0;j<=1000000;++j)
			mark[j]=0;
	bfs(1);
	sd(t);
	for(i=1;i<=t;++i)
	{
		sd(n);
		printf("Case #%d: %d\n",i,dp[n]);
	}
}