#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

unsigned long long slove_small(unsigned int a,unsigned int b,unsigned int k)
{
	unsigned long long ret = 0;
	for(unsigned int i = 0;i < a;++i)
	{
		for(unsigned int j = 0;j < b;++j)
		{
			unsigned int x = i&j;
			if(x < k) ++ ret;
		}
	}
	return ret;
}

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);					// 1 <= nCases <= 100
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int a = 0,b = 0,k = 0;scanf("%d%d%d",&a,&b,&k);
		unsigned long long ans = slove_small(a,b,k);
		printf("Case #%d: %I64u\n",iCases,ans);
	}
	return 0;
}
