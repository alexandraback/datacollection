#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 1000
#define OFF 500

struct ev
{
	int w,e;
	int d;
	int s;
};

bool cmp (const ev & a, const ev&b)
{
	return a.d<b.d;
}

int main()
{
	int t;
	scanf("%d",&t);

	int wall[MAX];
	ev events[MAX];
	for(int ccnt=1; ccnt<=t; ++ccnt)
	{
		int resp=0;
		int nev = 0;
		for(int i=0; i<MAX; ++i)
			wall[i]=0;

		int N;

		scanf("%d",&N);

		for(int i=0; i<N; ++i)
		{
			int d,n,w,e,s,dd,dp,ds;

			scanf("%d %d %d %d %d %d %d %d", &d, &n, & w, &e, &s, &dd, &dp, &ds);

			for(int j=0; j<n; ++j)
			{
				events[nev+j].w = w+j*dp;
				events[nev+j].e = e+j*dp;
				events[nev+j].d = d+j*dd;
				events[nev+j].s = s+j*ds;
			}
			nev += n;
		}

		sort(events, events+nev, cmp);

		int pi=0;
		for(int i=0; i<nev; ++i)
		{
			for(;events[pi].d < events[i].d; ++pi)
				for(int j=events[pi].w; j<events[pi].e; ++j)
					wall[j+OFF] = events[pi].s > wall[j+OFF]? events[pi].s : wall[j+OFF];

			int j;
			for(j=events[i].w; j<events[i].e; ++j)
				if(events[i].s > wall[j+OFF])
					break;

			if(j<events[i].e)
				++resp;
		}

		printf("Case #%d: %d\n",ccnt,resp);
	}
	return 0;
}

