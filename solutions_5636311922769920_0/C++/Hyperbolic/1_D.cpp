#include <stdio.h>
#include <math.h>
void solve(int);
int main()
{
	freopen("D-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}
int a,b,c;
void func(int depth,int row,long long int state)
{
	//depth번째 위치에서 row번째 node를 살펴본다, 누적 = state
	if(depth==0)
	{
		printf("%lld ",state);
		return;
	}
	if(row>=a)
	{
		printf("%lld ",state);
		return;
	}
	func(depth-1,row+1,state+(long long int)row*pow(a,depth-1)); 
}
void solve(int T)
{
	
	scanf("%d%d%d",&a,&b,&c);
	/*if(a>b*c)
	{
		printf("Case #%d: IMPOSSIBLE\n",T);
		return;
	}
	else
	{
		printf("Case #%d: ",T);
		for(int i=0;i<c;i++)
		{
			if(b*i>=a) break;
			func(b,b*i,1);
		}
	}
	printf("\n");*/
	printf("Case #%d: ",T);
	for(int i=1;i<=a;i++) printf("%d ",i);
	printf("\n");
}
