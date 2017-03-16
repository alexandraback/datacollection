#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int n,ans,f;
long long x;
bool v1,v2;
char s[10010];
int a[6][6];
int v[10010];
int calc(int x,long long n)
{
	int ans=1,f=0;
	while(n>0)
	{
	   if(n&1){
	   	f=1;
	   	if(ans<0)f*=-1;
	   	if(x<0)f*=-1;
	   	ans=f*a[abs(ans)][abs(x)];
	   }
	   x=a[abs(x)][abs(x)];
	   n/=2;
	}
	return ans;
}
void pre()
{
	a[1][1]=1;a[1][2]=2;a[1][3]=3;a[1][4]=4;
	a[2][1]=2;a[2][2]=-1;a[2][3]=4;a[2][4]=-3;
	a[3][1]=3;a[3][2]=-4;a[3][3]=-1;a[3][4]=2;
	a[4][1]=4;a[4][2]=3;a[4][3]=-2;a[4][4]=-1;
}
void task()
{
	scanf("%d %I64d",&n,&x);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') v[i]=1;
		if(s[i]=='i') v[i]=2;
		if(s[i]=='j') v[i]=3;
		if(s[i]=='k') v[i]=4;
	}
	ans=1;
	for(int i=1;i<=n;i++)
	{
		if(ans<0)f=-1;else f=1;
		ans=f*a[abs(ans)][v[i]];
	}
	ans=calc(ans,x);
	if(ans!=-1) {printf("NO\n");return;}
	ans=1;v1=v2=false;
	for(int i=1;i<=min(x,(long long)8);i++)
	for(int j=1;j<=n;j++)
	{
		if(ans<0)f=-1;else f=1;
		ans=f*a[abs(ans)][v[j]];
		if(ans==2)v1=true;
		if(v1)if(ans==4)v2=true;
	}
	if(v2)printf("YES\n");else printf("NO\n");
}
	
int main()
{
	int T;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	pre();
	for(int ti=1;ti<=T;ti++)
	{
		printf("Case #%d: ",ti);
		task();
	}
}
