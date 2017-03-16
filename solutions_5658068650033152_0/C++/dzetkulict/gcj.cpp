#include <stdio.h>

inline int f(int x)
{
	return (x*(x+1))/2;
}

int main()
{
	long long tc,t;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		int r,c,k,a,b,m,q,w,e,rr;
		scanf("%d %d %d",&r,&c,&k);
		m=k;
		for (a=3;a<=r;++a) for (b=3;b<=c;++b)
			for (q=0;q<a && q<b;++q) for (w=0;q+w<a && w<b;++w)
				for (e=0;e<a && q+e<b;++e) for (rr=0;rr+e<a && rr+w<b;++rr)
		{
			int x=2*a+2*b-4-q-w-e-rr;
			int y=a*b-f(q)-f(w)-f(e)-f(rr);
			if (y>=k && x<m) m=x;
		}
		printf("Case #%lld: %d\n",tc+1,m);
	}
	return 0;
}
