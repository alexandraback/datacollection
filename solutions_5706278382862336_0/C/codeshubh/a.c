#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef unsigned long long int ulint;
typedef long long int lint;
ulint gcd(ulint u, ulint v) {
return (v != 0)?gcd(v, u%v):u;
}
int main()
{
int t,tt;
ulint i,j,n,p,k,m,s;
scanf("%d",&tt);
for(t=1;t<=tt;++t)
{
	k=0;
	s=0;
	scanf("%lld",&i);
	getchar();
	scanf("%lld",&j);
	printf("Case #%d: ",t);	
//	printf("fdd%d %d\n",i,j);
//	p=gcd(i,j);
//	i=i/p;
//	j=j/p;
	/*if(j%2==1)
	{
		printf("impossible\n");
		continue;
	}*/
	m=j;
	p=0;
	for(n=0;n<40;++n)
	{
		if(m%2ULL==0)
		{
			m=m/2ULL;
			k+=1ULL;
			if((i/m)>=1)
			{
				if(!s)
					p=k;
				s=1;
//				m=1ULL;
//				break;
			}
		}
		else
			break;
	}
	if(m==1ULL)
	{
		printf("%lld\n",p);
	}
	else
		printf("impossible\n");
}
return 0;
}
