#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 100
#define MAXM 100
int main()
{
	int T;
	scanf("%d", &T);
	int map[MAXN][MAXM];
	char State[][5] = {"YES", "NO"};
	for (int t = 0; t < T; t++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &map[i][j]);
		bool ok = true;
		for (int i = 0; i < n && ok; i++)
			for (int j = 0; j < m && ok; j++)
			{
				bool okc = true;
				for (int kj = 0; kj < m && okc; kj++)
					if (map[i][kj] > map[i][j])
						okc = false;
				if (!okc)
				{
					okc = true;
					for (int ki = 0; ki < n && okc; ki++)
						if (map[ki][j] > map[i][j])
							okc = false;
				}
				ok = ok && okc;
			}
		char* ans = NULL;
		if (ok)
			ans = State[0];
		else
			ans = State[1];
		printf("Case #%d: %s\n", t+1, ans);
	}
	return 0;
}

