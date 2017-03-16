#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
	static const unsigned int maxvlue = 1000;
	static const unsigned int maxn = 1000;
	unsigned int data[maxn] = { 0 };
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)					// 1 <= nCases <= 100
	{
		unsigned int n = 0;scanf("%d",&n);
		for(unsigned int i = 0;i < n;++i) scanf("%d",&data[i]);				// 1 <= n <= 1000
		unsigned int ans = 0xffffffff;
		for(unsigned int imax = 1;imax <= maxvlue;++imax)					// 1 <= maxvalue <= 1000
		{
			unsigned int count = 0;
			for(unsigned int i = 0;i < n;++i)
			{
				count += (data[i]+imax-1)/imax - 1;
			}
			unsigned int cost = count + imax;
			if(cost < ans) ans = cost;
		}
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}