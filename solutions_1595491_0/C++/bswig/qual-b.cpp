#include <algorithm>
#include <cstdio>

using namespace std;

int ntest;
int ngoogler, nsurprise, minscore;
int totalscore[105];

int main()
{
	scanf("%d", &ntest);
	for(int test = 1;test <= ntest;++test)
	{
		scanf("%d %d %d", &ngoogler, &nsurprise, &minscore);
		for(int i = 0;i < ngoogler;++i)
			scanf("%d", &totalscore[i]);
		sort(totalscore, totalscore + ngoogler);
		int maxi = 0;
		int unmo = 0;
		int nnotchosen = 0;
		for(int i = 0;i < ngoogler;++i)
		{
			int type = totalscore[i] % 3;
			int third = totalscore[i] / 3;
			if(type == 0)
			{
				if(third >= minscore)
					++maxi;
				else if(nsurprise > 0 && third > 0 && third + 1 >= minscore)
				{
					--nsurprise;
					++maxi;
				}
			}
			else if(type == 1)
			{
				if(third + 1 >= minscore)
					++maxi;
			}
			else if(type == 2)
			{
				if(third > 0 && third + 1 >= minscore)
				{
					++maxi;
					++unmo;
				}
				else if(nsurprise > 0 && third + 2 >= minscore)
				{
					--nsurprise;
					++maxi;
				}
			}
		}
		printf("Case #%d: %d\n", test, maxi);
	}
}
