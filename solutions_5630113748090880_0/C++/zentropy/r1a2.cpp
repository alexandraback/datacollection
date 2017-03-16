#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <assert.h>

using std::vector;
using std::map;
using std::string;
using std::set;

#include <stdlib.h>

struct info_t
{
	unsigned int v;
	unsigned int r;
	unsigned int c;
};

void slove()
{
}

int main()
{
	freopen("F:\\GCJ2016\\R1A2\\B-small-attempt0.in","r",stdin);
	freopen("F:\\GCJ2016\\R1A2\\B-small-attempt0","w+",stdout);
	static const size_t buff_size = 1200;
	static const size_t maxv = 2500;
	char buff[buff_size] = { 0 };
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0,v = 0;scanf("%d",&n);
		size_t counts[maxv+1] = { 0 };
		for(unsigned int i = 0;i < 2*n - 1;++i)
		{
			for(unsigned int k = 0;k < n;++k)
			{
				scanf("%d",&v);
				++counts[v];
			}
		}
		vector<unsigned int> ans;
		for(unsigned int iv = 0;iv <= maxv;++iv)
		{
			if(0 == (counts[iv]%2)) continue;
			ans.push_back(iv);
		}
		assert(ans.size() == n);
		std::sort(ans.begin(),ans.end());

		printf("Case #%u:",iCases);
		for(size_t i = 0;i < ans.size();++i) printf(" %u",ans[i]);
		printf("\n");
	}
	return 0;
}