#include<iostream>
#include<cmath>
using namespace std;
#define  llong long long
struct node
{
	llong num;
	llong val;
}a[100],b[100];
llong solve(int i,int j)
{
	if(i<0||j<0)return 0;
	if(a[i].val==b[j].val)
	{
		if(a[i].num>b[j].num)
		{
			a[i].num-=b[j].num;
			llong tmp=solve(i,j-1);
			a[i].num+=b[j].num;
			return b[j].num+tmp;
		}
		else
		{
			b[j].num-=a[i].num;
			llong tmp=solve(i-1,j);
			b[j].num+=a[i].num;
			return a[i].num+tmp;
		}
	}
	return max(solve(i,j-1),solve(i-1,j));
}
int main()
{
	int t,N,M;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		scanf("%d%d",&N,&M);
		for(int j=0;j<N;j++)
			scanf("%lld %lld",&a[j].num,&a[j].val);
		for(int j=0;j<M;j++)
			scanf("%lld%lld",&b[j].num,&b[j].val);
		printf("%lld\n",solve(N-1,M-1));
	}
	return 0;
}