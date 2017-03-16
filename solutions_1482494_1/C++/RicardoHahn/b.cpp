#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1100

typedef pair<int,int> pii;

int main()
{
	pii level[MAX];
	pii star1[MAX];
	pii star2[MAX];
	int played[MAX];

	int t;
	scanf("%d",&t);

	for(int tcnt=1; tcnt<=t; ++tcnt)
	{
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d %d",&level[i].first,&level[i].second);
			star1[i].first = level[i].first;
			star2[i].first = level[i].second;
			star1[i].second = star2[i].second = i;
			played[i] = 0;
		}

		sort(star1,star1+n);
		sort(star2,star2+n);

		int resp = 0;
		int nstars = 0;

		while(nstars < 2*n)
		{
			int found = 0;
			// look for star2 level first
			for(int i=0; i<n && star2[i].first <= nstars; ++i)
			{
				if(played[star2[i].second] < 2)
				{
					nstars += 2 - played[star2[i].second];
					played[star2[i].second] = 2;
					found = 1;
					resp++;
				}
			}
			if(found)
				continue;
			int mdist, mi; 
			mdist = 0;
			mi = -1;
			for(int i=0; i<n && star1[i].first <=nstars; ++i)
			{
				int idx = star1[i].second;
				if(played[idx] < 1)
				{
					if(level[idx].second - level[idx].first > mdist)
					{
						mdist = level[idx].second - level[idx].first;
						mi = idx;
					}
				}
			}
			if(mi <0) break;
			nstars += 1;
			played[mi] = 1;
			resp++;
		}

		if(nstars == 2*n)
			printf("Case #%d: %d\n",tcnt,resp);
		else
			printf("Case #%d: Too Bad\n",tcnt);
	}
	return 0;
}
