#include <stdio.h>
#include <assert.h>
#include <math.h>

unsigned long long calc_func(unsigned long long r,unsigned long long k)
{
	unsigned long long x = 2*r+1+2*k;
	unsigned long long y = k + 1;
	return x*y;
}

unsigned int binary_find(unsigned long long r,unsigned long long t)
{
	unsigned long long hi1 = t/(2*r)+1;
	unsigned long long hi2 = (unsigned long long)(sqrt((t+1)/2*1.0)) + 1;

	unsigned long long lo = 0,hi = (hi1 < hi2?hi1:hi2);
	for(;lo < hi;)
	{
		unsigned long long mid = (lo+hi)/2;
		unsigned long long v = calc_func(r,mid);
		if(v == t) return (unsigned int)(mid);
		if(v > t) hi = mid;
		else lo = mid + 1;
	}
	assert(0 != lo);
	unsigned long long xtest = calc_func(r,lo-1);
	unsigned long long ytest = calc_func(r,lo);
	assert(xtest <= t && t < ytest);
	return (unsigned int)(lo - 1);
}

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned long long r = 0,t = 0;scanf("%I64d%I64d",&r,&t);
		// 第i个黑环需要 (r+2*i+1)^2-(r+2*i)^2 = 2*r+4*i+1	(0 <= i)
		// 前k个黑环需要的总和: s(k) = (2r+1+2k)*(k+1)
		// 显然 s(k) > 2*r*k 且s(k) >= 2*k*k
		// 求k使得, s(k) <= t < s(k+1)
		// s(k) <= t => t >= s(k) > 2*r*k => k <= t/(2*r)
		//
		unsigned int ans = (unsigned int)(binary_find(r,t)) + 1;
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}