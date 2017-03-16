#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
bool meet[10];int meetcount;
void count(int in)
{
	while(in)
	{
		if(!meet[in%10])
		{
			meet[in%10]=true;
			++meetcount;
		}
		in/=10;
	}
}
void task()
{
	int n;scanf("%d",&n);
	meetcount=0;
	memset(meet,0,sizeof meet);
	if(n==0)
	{
		printf("INSOMNIA\n");
		return;
	}
	int tn=n;
	while(true)
	{
		count(tn);
		if(meetcount==10)
		{
			printf("%d\n",tn);
			return;
		}
		tn+=n;
	}
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d: ",i);
		task();
	}
}
	
