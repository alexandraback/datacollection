#include <cstdio>
#include <cstring>

long t,i,a,b,m,ans,z[10];

bool g(long n)
{
	for(long i=1;i<=z[0];i++)
		if(z[i]==n)return 0;
	return 1;
}
long f(long m)
{
	long n,m1=m,k=0,i,j,j1=1,j2=1,answ=0;
	while(m1){m1/=10;k++;}
	z[0]=0;
	for(j=1;j<=k;j++)j2*=10;
	for(i=1;i<k;i++)
	{
		j1*=10;
		j2/=10;
		n=m%j1*j2+m/j1;
		if(n>m && n<=b)
		if(g(n))
		{
			z[++z[0]]=n;
			answ++;
		}
	}
	return answ;
}

int main ()
{
	//freopen("1.out","w",stdout);
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld%ld",&a,&b);
		ans=0;
		for(m=a;m<=b;m++)
			ans+=f(m);
		printf("Case #%ld: %ld\n",i,ans);
	}
	
	return 0;
}

