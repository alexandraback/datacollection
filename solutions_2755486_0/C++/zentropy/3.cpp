#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <assert.h>
#include <string>
#include <deque>
#include <algorithm>

using std::vector;
using std::map;
using std::multimap;
using std::set;
using std::string;
using std::deque;
using std::pair;

struct attack_t
{
	int w;
	int e;
	int s;
public:
	attack_t(int tw,int te,int ts):w(tw),e(te),s(ts) { ; }
};

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		vector< vector<attack_t> > attacks(676061);

		unsigned int n = 0;scanf("%d",&n);
		multimap<int,attack_t> table;
		for(unsigned int i = 0;i < n;++i)
		{
			int di = 0,ni = 0,wi = 0,ei = 0,si = 0,ddi = 0,dpi = 0,dsi = 0;
			scanf("%d%d%d%d%d%d%d%d",&di,&ni,&wi,&ei,&si,&ddi,&dpi,&dsi);
			for(int k = 0;k < ni;++k)
			{
				attacks[di].push_back(attack_t(wi,ei,si));
				//printf("%d %d %d %d\n",di,wi,ei,si);
				wi += dpi;ei += dpi;
				si += dsi;di += ddi;

			}
		}

		vector<size_t> heights(1200,0);

		size_t ans = 0;
		for(size_t i = 0;i < attacks.size();++i)
		{
			for(size_t k = 0,len = attacks[i].size();k < len;++k)
			{
				const attack_t& r = attacks[i][k];
				bool exist = false;
				for(int p = r.w*2;p <= r.e*2;++p)
				{
					if(heights[p+600] < r.s) exist = true;
				}
				if(exist) ++ ans;
			}

			for(size_t k = 0,len = attacks[i].size();k < len;++k)
			{
				const attack_t& r = attacks[i][k];
				for(int p = r.w*2;p <= r.e*2;++p)
				{
					if(heights[p+600] < r.s)
					{
						heights[p+600] = r.s;;
					}
				}
			}
		}

		//

		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}