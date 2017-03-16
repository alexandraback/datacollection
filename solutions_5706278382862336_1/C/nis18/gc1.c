#include<stdio.h>

long long int gcd(long long int p,long long int q)
{
	if(q==0)
	{
		return p;
	}
	return gcd(q,p%q);
}

long long int powr(long long int m,long long int n)
{
	long long int i=0,t=1;
	while(!(m/n))
	{
		i++;
		n/=2;
	}
	return i;
}

long long int check(long long int m,long long int n)
{
	long long int i=0,t=1;
	while(i<40)
	{
		m*=2;
		i++;
	}
	if(m%n!=0)
	{
		return 0;
	}
	return 1;
}

int main()
{
	FILE* f1;
	FILE* f2;
	f1=fopen("input1.txt","r");
	f2=fopen("output1.txt","w");
	int t,cn=1;
	fscanf(f1,"%d",&t);
	while(cn<=t)
	{
		long long int p,q,m,n,tmp,a=0,fg=0;
		fscanf(f1,"%lld/%lld",&p,&q);
		tmp=gcd(p,q);
		m=p/tmp;
		n=q/tmp;
		a=powr(m,n);
		fg=check(m,n);
		fprintf(f2,"Case #%d: ",cn);
		if(fg)
		{
			fprintf(f2,"%lld\n",a);
		}
		else
		{
			fprintf(f2,"impossible\n");
		}
		cn++;
	}
	fclose(f1);
	fclose(f2);
}
