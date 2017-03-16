#include<stdio.h>
#include<math.h>
void reduce(long long &P,long long &Q)
{
	long long p,q,r;
	p=P>Q?P:Q;
	q=P>Q?Q:P;
	r=1;
	while(r)
	{
		r=p%q;
		p=q;
		q=r;
	}
	P/=p;
	Q/=p;
}
int main()
{
	int T;
	long long P,Q;
	long long R,S[41];
	int n;
	int m;
	long long i;
	R=1;
	for(i=0;i<41;i++)
	{
		S[i]=R;
		R*=2;
	}
	scanf("%d",&T);
	for(n=1;n<=T;n++)
	{
		scanf("%lld/%lld",&P,&Q);
		reduce(P,Q);
		m=(int)(log((double)Q)/log(2.0));
		if(S[m]!=Q)
		{
			printf("Case #%d: impossible\n",n);
		}
		else
		{
			for(i=0;i<m;i++)
			{
				if((P*S[i])/Q>0)
				{
					break;
				}
			}
			printf("Case #%d: %d\n",n,i);
		}
	}
	return 0;
}