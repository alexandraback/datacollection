#include <stdio.h>
#include <math.h>
long long int gcd(long long int c, long long int b)
{
	if(b%c!=0)
	{
		return gcd(b%c,c);
	}
	else
		return c;
}
int main()
{
	FILE *fp;
	fp=fopen("fout.out","w");
	int t,cnt=1;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,m,x,y,d;
		int power=0;
		char c;
		scanf("%lld%c%lld",&n,&c,&m);
		x=m;
		d=gcd(n,m);
		x=m/d;
		y=n/d;
		while((y/2)!=0&&x%2==0)
		{
			y=y/2;
			x=x/2;
			//power++;
		}
		while(x%2==0)
		{
			x=x/2;
			power++;
		}
		if(x==1)
		{
			fprintf(fp,"Case #%d: %d\n",cnt,power);
			cnt++;
		}
		else
		{
			fprintf(fp,"Case #%d: impossible\n",cnt);
			cnt++;	
		}
	}
	return 0;
}