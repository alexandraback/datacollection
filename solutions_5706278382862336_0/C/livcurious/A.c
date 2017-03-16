#include<stdio.h>
unsigned long gcd(unsigned long u, unsigned long v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
 
    return gcd((v - u) >> 1, u);
} 
int main()
{
	//freopen("asm.in",'r',stdin);
	//freopen("asm.ot",'w',stdout);
	unsigned long t,t1,p,q,qc,gen=0,g;
	scanf("%lu",&t1);
	for(t=1;t<=t1;t++)
	{
		scanf("%lu/%lu",&p,&q);
		g=gcd(p,q);
		p/=g;
		q/=g;
		gen=0;
		qc=q;
		if(p>q)
		{
			printf("Case #%lu: impossible\n",t);
			goto end;
		}
		while(qc!=1)
		{
			if(qc/2!=(qc+1)/2)	//q is odd
			{
				printf("Case #%lu: impossible\n",t);
				goto end;
			}
		qc/=2;
		}
		while(p<q)
		{
			q/=2;
			gen++;
		}		
		printf("Case #%lu: %lu\n",t,gen);
		end:;
	}
	return 0;
}

