#include <stdio.h>

const int PROB_NUM=1;

long long f(long long a,long long b)
{
	return a?f(b%a,a):b;
}

void process()
{
	int c=0;
	long long a=0,b=0,t,p,q,g;
	scanf("%lld/%lld",&p,&q);
	g=f(p,q);
	p/=g;
	q/=g;
	t=q;
	while(t>1)
	{
		if(t%2)
		{
			printf("impossible\n");
			return;
		}
		b++;
		t/=2;
	}
	t=p;
	while(t>1)
	{
		a++;
		t/=2;
	}
	
	printf("%d\n",b-a);
}

int main()
{
	char in[10]="0.in";
	char out[10]="0.out";
	in[0]=PROB_NUM+'0';
	out[0]=PROB_NUM+'0';
	freopen(in,"r",stdin);
	freopen(out,"w",stdout);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}