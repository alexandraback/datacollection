#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int norm[40], surp[40];

void precompute()
{
	for(int i=0; i<=30; ++i)
	{
		int k = i/3;
		if(i%3 == 0){ surp[i] = k + 1; norm[i] = k; }
		else if(i%3 == 1){ surp[i] = k + 1; norm[i] = k + 1; }
		else if(i%3 == 2){ surp[i] = k + 2; norm[i] = k + 1; }
	}
	surp[0] = 0;
}

int main()
{
	precompute();
	int cases;
	scanf("%d", &cases);
	for(int icases = 1; icases <= cases; ++icases)
	{
		int n, s, p;
		scanf("%d%d%d", &n, &s, &p);
		int res = 0, pl = 0;
		for(int i=0; i<n; ++i)
		{
			int a;
			scanf("%d", &a);
			if(norm[a] >= p) res++;
			else if(surp[a] >= p) pl++;
		}
		res += min(pl, s);
		printf("Case #%d: %d\n", icases, res);
	}
	return 0;
}