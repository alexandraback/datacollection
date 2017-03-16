#include<stdio.h>
double st[100001];
double wrong[100001];
double right[100001];
double pow[100001];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.out","w",stdout);
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		double min=1e50,p=0;
		printf("Case #%d: ",++cas);
		int a,b;
		int i,j;
		scanf("%d %d",&a,&b);
		for(i=1;i<=a;i++)
			scanf("%lf",&st[i]);
		for(i=0;i<=a;i++)
			right[i]=1;
		for(i=1;i<=a;i++)
		{
			right[i]=right[i-1]*st[i];
			wrong[i]=right[i-1]*(1.0-st[i]);
		}
		for(i=1;i<=a;i++)
			p+=wrong[i]*(b+2);
		p+=right[a]*(b+2);
		if(p<min)
			min=p;
		for(i=0;i<=a;i++)
		{
			p=0;
			for(j=1;j<=a;j++)
			{
				if(j+i>a)
					p+=wrong[j]*(b-a+1+i*2);
				else
					p+=wrong[j]*(b-a+1+i*2+b+1);
			}
			p+=right[a]*(b-a+1+i*2);
			if(p<min)
				min=p;
		}
		printf("%lf\n",min);
	}
	return 0;
}

