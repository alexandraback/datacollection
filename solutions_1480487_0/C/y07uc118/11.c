#include<stdio.h>
#include<string.h>
int main()
{
	
	int t,i,n,c;
	long long int max,q;
	double a[300],b[300],s,p,k;
	freopen("1.in","r",stdin);
	freopen("2.txt","w",stdout);
	scanf("%d",&t);
	q=1;
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		for(i=0;i<n;i++)
		{scanf("%lf",&a[i]);
			s=s+a[i];
		}
		max=0;
		p=2*s;
		p=(p*1.0)/n;
		k=2*s;
		c=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>=p) { b[i]=0.0;c++;k=k-a[i];}
			
		}
		for(i=0;i<n;i++)
		{
			if(a[i]<p){b[i]=((k)/(n-c))-a[i];}
		}
		printf("Case #%d:",q);
		for(i=0;i<n;i++)
		printf("% lf",b[i]*100/(s));
		printf("\n");
		q++;
	}
	return 0;
}
