#include <stdio.h>
#include <string.h>

int main()
{
	static const unsigned int maxsize = 1000;
	char buff[maxsize+1] = { 0 };
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int smax = 0;scanf("%d%s",&smax,buff);
		unsigned int count = 0,ans = 0,p = 0;
		for(size_t len = strlen(buff);p < len;++p)
		{
			unsigned int v = buff[p] - '0';
			if(p > count) { ans += p - count;count = p; }
			count += v;
		}
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}