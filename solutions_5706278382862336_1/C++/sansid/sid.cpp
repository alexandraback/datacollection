#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
  if (b == 0) {
    return a;
  }
  else {
    return gcd(b, a % b);
  }
}

int main()
{
	FILE *fi,*fo;
	fo = fopen("test.txt", "w+");
	fi = fopen("abc.txt", "r");
	long long int bin[43],b,ans,a,c,flg,i,f,k=1;
	bin[0]=1;
	for(i=1;i<=40;i++)
	{
		bin[i]=bin[i-1]*2;
	}
	fscanf(fi,"%lld",&f);
	while(f--)
	{
		fscanf(fi,"%lld/%lld",&a,&b);
		c=gcd(a,b);
		a=a/c;
		b=b/c;
		flg=0;
		for(i=0;i<=40;i++)
		{
			if(b==bin[i])
			flg=1;
		}
		if(flg==0 || a==0)
		fprintf(fo,"Case #%lld: impossible\n",k);
		else
		{
			if(b==1 && a==1)
			fprintf(fo,"Case #%lld: 0\n",k);
			else
			{
				ans=0;
				while(a<b)
				{
					ans++;
					b=b/2;
				}
				fprintf(fo,"Case #%lld: %lld\n",k,ans);
			}
		}
		k++;
	}
	return 0;
}
