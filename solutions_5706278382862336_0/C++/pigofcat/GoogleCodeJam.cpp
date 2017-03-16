#include<stdio.h>

__int64 gcd(__int64 a,__int64 b)
{
	__int64 r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int calc(__int64 p, __int64 q)
{
	int ret=0;
	if(q==0||(q&(q-1)))
		return -1;
	while(p<q)
	{
		++ret;
		q>>=1;
	}
	if(ret>40)return -1;
	return ret;
}

int main()
{
	int t,mm,ans;
	__int64 p,q,g;
	freopen("E:\\A-small-attempt0.in","r",stdin);
	freopen("E:\\A-small.out","w",stdout);
	scanf("%d",&t);
	for(mm=1;mm<=t;++mm)
	{
		scanf("%I64d/%I64d",&p,&q);
		g=gcd(p,q);
		p/=g;
		q/=g;
		ans=calc(p,q);
		if(ans==-1)printf("Case #%d: impossible\n",mm);
		else printf("Case #%d: %d\n",mm,ans);
	}
	return 0;
}