#include <cstdio>

int t,i,a,b,m,ans;

int f(int m)
{
	int n,m1=m,k=0,i,j,j1,j2,answ=0;
	bool u[3001]={0};
	while(m1){m1/=10;k++;}
	for(i=1;i<k;i++)
	{
		j1=j2=1;
		for(j=1;j<=i;j++)j1*=10;
		for(j=1;j<=k-i;j++)j2*=10;
		n=m%j1*j2+m/j1;
		if(n>m && n<=b)
		if(! u[n])
		{
			u[n]=1;
			answ++;
		}
	}
	return answ;
}

int main ()
{
	//freopen("1.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&a,&b);
		ans=0;
		for(m=a;m<=b;m++)
			ans+=f(m);
		printf("Case #%d: %d\n",i,ans);
	}
	
	return 0;
}

