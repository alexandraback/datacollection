#include<stdio.h>
#include<math.h>
long long ar[105];
int br[105];
int is_palin(long long x)
{
	long long j=0,i;
	i=x;
	while(i)
	{
		j=j*10+(i%10);
		i/=10;
	}
	//printf("j=%lld x=%lld\n",j,x);
	if(j==x)
		return 1;
	return 0;
}
int main()
{
	int t,k=1;
	long long a,b,x,y,i;
	for(i=1;i<=100;i++)
	{
		x=(i*i);
		ar[i]=x;
		//printf("x=%lld\n",x);
		if(is_palin(x) && is_palin(i))
			br[i]=br[i-1]+1;
		else
			br[i]=br[i-1];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		printf("Case #%d: ",k++);
		x=sqrt(a-1);
		y=sqrt(b);
		printf("%d\n",br[y]-br[x]);
	}
	return 0;
}