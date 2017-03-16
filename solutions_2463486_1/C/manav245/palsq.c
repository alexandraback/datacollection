#include<stdio.h>
int chck(long long int b)
	{
	char a[100];
	long long int i=0,l;
	while(b)
		{
		a[i++]=b%10;
		b/=10;
		}
	l=--i;
	for(i=0;i<l;i++,l--)
		{
		if(a[i]!=a[l])
		break;
		}
	if(i<l)
	return 0;
	return 1;
	}
int main()
{
long long int T,i,j,k=0;
long long int a,b,ans;
long long int an[150000];
scanf("%lld",&T);
for(i=0;i<=10000000;i++)
		{
		if(chck(i))
				{
				if(chck(i*i))
				an[k++]=i*i;
				}
		}
for(i=0;i<T;i++)
	{
	ans=0;
	scanf("%lld %lld",&a,&b);
	for(j=0;j<k;j++)
		{
		if(an[j]>b)
			break;
		if(an[j]>=a)
			{
			ans++;	
			}
		}
	
	printf("Case #%lld: %lld\n",i+1,ans);
	}
return 0;
}
