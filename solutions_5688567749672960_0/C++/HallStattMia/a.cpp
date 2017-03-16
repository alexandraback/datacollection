#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
int n;
int f[1000010],q[1000010];

void pre()
{
	for(int i=1;i<=1000000;i++)
	f[i]=1000000000;
	f[0]=0;
	int h=0,t=1;
	while(h<t)
	{
		int x=q[++h];
		if(f[x]+1<f[x+1])
		{
			q[++t]=x+1;
			f[x+1]=f[x]+1;
		}
		int y=0,x1=x;
		while(x1>0)
		{
			y=y*10+x1%10;
			x1/=10;
		}
		if(f[x]+1<f[y])
		{
			f[y]=f[x]+1;
			q[++t]=y;
		}
	}
		
}
void task()
{
	scanf("%d",&n);
	printf("%d\n",f[n]);
	
}
int main()
{

	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;pre();
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		task();
	}
	//for(int i=1;i<=20;i++)cout<<f[i]<<endl;
}
