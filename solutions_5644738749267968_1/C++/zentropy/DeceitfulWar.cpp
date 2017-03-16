#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);						// 1 <= nCases <= 50
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0;scanf("%d",&n);
		vector<float> naomi(n),ken(n);
		for(unsigned int i = 0;i < n;++i) scanf("%f",&naomi[i]);
		for(unsigned int i = 0;i < n;++i) scanf("%f",&ken[i]);
		std::sort(naomi.begin(),naomi.end());
		std::sort(ken.begin(),ken.end());

		unsigned int deceitful = 0,war = 0; 
		for(unsigned int i = 0,k = 0;i < n && k < n;)
		{
			if(naomi[i] < ken[k]) ++war,++i,++k;
			else ++k;
		}

		unsigned int lower = n - war,upper = n + 1;
		for(;lower + 1 < upper;)
		{
			unsigned int mid = (lower + upper)/2;
			bool allok = true;
			for(unsigned int i = n - mid,k = 0;k < mid && allok;++i,++k)
			{
				if(naomi[i] < ken[k]) allok = false;
			}
			if(allok) lower = mid;
			else upper = mid;
		}
		deceitful = lower;

		printf("Case #%u: %u %u\n",iCases,deceitful,n - war);
	}
	return 0;
}