#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
	static const size_t buff_size = 0x100;
	static const size_t hibound = 2000000;

	char buff[buff_size] = { 0 };
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int a = 0,b = 0;scanf("%d%d",&a,&b);
		std::vector<unsigned int> counts(hibound+1,-1);
		unsigned long long ans = 0;					// nCases*B*len < 10^9
		for(unsigned int x = a;x <= b;++x)
		{
			if(counts[x] == (unsigned int)(-1))
			{
				unsigned int product = 1,p = 0,z = x;
				for(;x >= product;product *= 10,++p);
				product /= 10;
				unsigned int xh = x/product;
				std::vector<unsigned int> cycles;cycles.reserve(p+1);
				cycles.push_back(z);
				for(unsigned int i = 0;i < p;++i)
				{
					unsigned int r = z%10,h = z/10;
					z = r*product+h;
					if(r < xh) continue;					// 最高位必须大于等于原来的最高位
					if(z > x && z <= b) cycles.push_back(z);
				}
				std::sort(cycles.begin(),cycles.end());
				unsigned int size = (unsigned int)(std::unique(cycles.begin(),cycles.end())-cycles.begin());
				for(unsigned int i = 0;i < size;++i)
				{
					counts[cycles[i]] = size - 1 - i;
				}
			}
			ans += counts[x];
		}
		printf("Case #%u: %I64u\n",iCases,ans);
	}
	return 0;
}