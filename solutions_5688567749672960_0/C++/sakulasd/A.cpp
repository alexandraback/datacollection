#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1000010];
int queue[1000010][2];
int RE(int a)
{
	int res=0;
	while (a)
	{
		res*=10;
		res=res+a%10;
		a/=10;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int head=1,tail=1;
	queue[1][0]=1;
	queue[1][1]=1;
	memset(a,0,sizeof(a));
	a[1]=1;
	while (head<=tail)
	{
		
		if (queue[head][0]+1<=1000000 && a[queue[head][0]+1]==0)
		{
			tail++;
			queue[tail][0]=queue[head][0]+1;
			queue[tail][1]=queue[head][1]+1;
			a[queue[head][0]+1]=queue[tail][1];
			
		}
		if (RE(queue[head][0])<=1000000 && a[RE(queue[head][0])]==0)
		{
			tail++;
			queue[tail][0]=RE(queue[head][0]);
			queue[tail][1]=queue[head][1]+1;
			a[RE(queue[head][0])]=queue[tail][1];
			
		}
		head++;
	}
	int t,n;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n",TT,a[n] );
	}
	return 0;
}