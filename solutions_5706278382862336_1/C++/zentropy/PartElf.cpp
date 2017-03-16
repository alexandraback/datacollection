#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <assert.h>

using std::vector;
using std::queue;
using std::string;

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(a > b) return gcd(b,a);
	if(0 == a) return b;
	if(1 == a) return 1;
	return gcd(b%a,a);
}

int main()
{
	static const size_t buff_size = 0x100;
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		char buff[buff_size] = { 0 };
		scanf("%s",buff);

		bool bp = true;
		unsigned long long p = 0,q = 0;
		for(size_t i = 0,len = strlen(buff);i < len;++i)
		{
			if(buff[i] == '/') { bp = false;continue; }
			int v = buff[i] - '0';
			if(bp) { p *= 10;p += v; }
			else { q *= 10;q += v; }
		}

		unsigned long long d = gcd(p,q);p /= d;q /= d;
		assert(q >= 2);

		unsigned long long product = 1;
		unsigned int count = 0;
		for(;product < q;product *= 2,++count);

		int ans = -1;
		if(product == q)
		{
			ans = 0;
			for(;p < q;q /= 2,++ans);
		}

		if(-1 == ans) printf("Case #%d: impossible\n",iCases);
		else printf("Case #%d: %d\n",iCases,ans);
	}
	return 0;
}