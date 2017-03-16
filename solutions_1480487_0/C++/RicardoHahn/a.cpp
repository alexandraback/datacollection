#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 210

int main()
{
	int t;

	scanf("%d",&t);
	for(int tcnt=1; tcnt<=t; ++tcnt)
	{
		int n;
		pair<int,int> v[MAX];
		int x;
	
		scanf("%d",&n);

		x=0;
		for(int i=0; i<n; ++i)
		{
			scanf("%d",&v[i].first);
			v[i].second = i;
			x+=v[i].first;
		}

		sort(v,v+n);
		double media;
		double y=0;

		int a;
		for(a=1; a<n; ++a)
		{
			double yneed = v[a].first - v[a-1].first;
			yneed *= a;
			yneed /= x;
			if(y+yneed > 1)
				break;
			y+=yneed;
		}
		media = v[a-1].first + (1-y)*x/(double)a;
		double resp[MAX];

		for(int i=0; i<n;++i)
		{
			double tresp = (media - v[i].first)/x;
			if(tresp < 0) tresp = 0;
			resp[v[i].second] = tresp;
		}

		printf("Case #%d:",tcnt);
		for(int i=0; i<n; ++i)
			printf(" %.6f",resp[i]*100);
		printf("\n");
	}
	return 0;
}
