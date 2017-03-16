#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

int matrix[55][55];
long long deg[55];

void solve ()
{
	int B;
	long long M;
	cin >> B >> M;

	memset(matrix,0,sizeof matrix);
	memset(deg,0,sizeof deg);
	
	--M;
	matrix[0][B-1] = 1;
	deg[0] = 1;
	
	int curV = 1;
	while (M && curV < B-1)
	{
		int curMx = -1;
		for (int i = 0; i < curV; i += 1)
		{
			if (!matrix[i][curV] && deg[i] <= M && deg[i] > deg[curMx])
				curMx = i;
		}
		
		if (curMx == -1)
			++curV;
		else
		{
			M -= deg[curMx];
			deg[curV] += deg[curMx];
			matrix[curMx][curV] = 1;
			matrix[curV][B-1] = 1;
		}
	}
	
	if (M)
		printf("IMPOSSIBLE\n");
	else
	{
		printf("POSSIBLE\n");
		for (int i = 0; i < B; i += 1)
		{
			for (int j = 0; j < B; j += 1)
			{
				printf("%d",matrix[i][j]);
			}
			printf("\n");
		}
	}
}

int main ()
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ",t);
		solve();
	}
	
	return 0;
}
