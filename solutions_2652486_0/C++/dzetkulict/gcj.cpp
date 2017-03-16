#include <stdio.h>

using namespace std;

long long x[1000];

int main()
{
	long long tc,t,r,n,m,k,i,j,ii;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		scanf("%lld %lld %lld %lld\n",&r,&n,&m,&k);
		printf("Case #%lld:\n",tc+1);
		for (i=0;i<r;++i)
		{
			int _2=0,_3=0,_5=0,_7=0,p=0,w=0;
			for (j=0;j<k;++j)
			{
				scanf("%lld",x+j);
				while ((x[j]%2)==0) { x[j]/=2; ++_2; }
				while ((x[j]%3)==0) { x[j]/=3; ++_3; }
				while ((x[j]%5)==0) { x[j]/=5; ++_5; }
				while ((x[j]%7)==0) { x[j]/=7; ++_7; }
			}
			if (_2==0 && _3==0) printf("555\n"); else
			if (_2==0 && _5==0) printf("333\n"); else
			{
				p=w=0;
				if (_5>0) p=1;
				if (_5>5) p=2;
				if (_3>0) w=1;
				if (_3>5) w=2;
				int r=3-p-w,d=0,s=0;
				while (r<0) { if (_5>_3) --w; else --p; ++r;}
				while (_2>0 && r<=0) { if (_5*w>_3*p) --w; else --p; ++r;}
				_2*=2;
				while (r)
				{
					if (_2/r>10) { ++s; _2-=14; } else { ++d; _2-=7; }
					--r;
				}
				for (ii=0;ii<d;++ii) printf("2");
				for (ii=0;ii<s;++ii) printf("4");
				for (ii=0;ii<w;++ii) printf("3");
				for (ii=0;ii<p;++ii) printf("5");
				printf("\n");
			}
		}
	}
	return 0;
}
