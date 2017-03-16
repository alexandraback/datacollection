#include<cstdio>

int n,s,p;
int a[110];

void init()
{
	scanf("%d%d%d",&n,&s,&p);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
}

int work()
{
	int ret=0;
	if(p==0) return n;
	if(p==1)
	{
		for(int i=0;i<n;i++) ret+=(a[i]>0);
		return ret;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>=p*3-2) ret++;
		else if(s && a[i]>=p*3-4)
		{
			s--;
			ret++;
		}
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		init();
		printf("Case #%d: %d\n",i,work());
	}
	return 0;
}

