#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

int hist[2505];

void solve ()
{
	int N;
	scanf("%d",&N);
	
	memset(hist,0,sizeof hist);
	for (int i = 0; i < 2*N-1; i += 1)
	{
		for (int j = 0; j < N; j += 1)
		{
			int a;
			scanf("%d",&a);
			
			hist[a] = (hist[a]+1)%2;
		}
	}
	
	for (int i = 0; i <= 2500; ++i)
	{
		if (hist[i])
			printf(" %d",i);
	}
	printf("\n");
}

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d:",t);
		solve();
	}
	
	return 0;
}
