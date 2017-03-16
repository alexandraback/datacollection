#include<stdio.h>
unsigned long long gcd(unsigned long long u, unsigned long long v)
{
    if (u == v)  return u;
    if (u == 0)  return v;
    if (v == 0)  return u;
    if (~u & 1) 
    {
        if (v & 1) return gcd(u >> 1, v);
        else return gcd(u >> 1, v >> 1) << 1;
    }
    if (~v & 1) return gcd(u, v >> 1);
    if (u > v)  return gcd((u - v) >> 1, v);
	return gcd((v - u) >> 1, u);
} 
int main()
{
	//freopen("asm.in",'r',stdin);
	//freopen("asm.ot",'w',stdout);
	unsigned long long t,t1,p,q,qc,gen=0,g;
	scanf("%llu",&t1);
	for(t=1;t<=t1;t++)
	{
		scanf("%llu/%llu",&p,&q);
		g=gcd(p,q);
		p/=g;
		q/=g;
		gen=0;
		qc=q;
		if(p>q)
		{
			printf("Case #%llu: impossible\n",t);
			goto end;
		}
		while(qc!=1)
		{
			if(qc/2!=(qc+1)/2)	//q is odd
			{
				printf("Case #%llu: impossible\n",t);
				goto end;
			}
		qc/=2;
		}
		while(p<q)
		{
			q/=2;
			gen++;
		}		
		printf("Case #%llu: %llu\n",t,gen);
		end:;
	}
	return 0;
}

