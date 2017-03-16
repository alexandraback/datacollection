#include <cstdio>

const int maxm=(1<<10)-1;
int m=0;

bool mark(int x)
{
	while(x>0)
	{
		m|=(1<<(x%10));
		x/=10;
	}
	return m==maxm;
}

int check(int x)
{
	m=0;
	int t=x;
	for(int i=1; i<=80; ++i)
	{
		if(mark(t))
			return i;
		t+=x;
	}
	return 0;
}

int main()
{
	int t,x;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&x);
		x*=check(x);
		if(x)printf("Case #%d: %d\n",i,x);
		else printf("Case #%d: INSOMNIA\n",i);
	}
	return 0;
}

