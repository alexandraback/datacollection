#include<stdio.h>
#include<limits.h>
long a[1000006];

long rev (long n)
{
	long r=0;
	while(n!=0)
	{
		r=10*r+n%10;
		n=n/10;
	}
	return r;
}

int main()
{
	FILE *fp,*fp1;
	
	fp=freopen("A-small-attempt0 (1).in","r",stdin);
	fp1=freopen("ab.text","w+",stdout);
	
	long n,i,j;
	int t,c=0;
	unsigned long count;
	scanf("%d",&t);
	a[0]=0;
	for(i=1;i<1000002;i++)
		a[i]=INT_MAX-1;
	
	for(j=0;j<t;j++)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			if(i%10!=0)
			{
				count=a[rev(i)]+1;
			//printf("%d %d\n",i,a[i-1]);
			if(count<(a[i-1]+1))
				a[i]=count;
			else
				a[i]=a[i-1]+1;	
			}
			else
				a[i]=a[i-1]+1;
		}
		printf("Case #%d: %ld\n",j+1,a[n]);
	}
	
	fclose(fp);
	fclose(fp1);
	
	return 0;	
}
