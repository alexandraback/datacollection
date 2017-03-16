#include <cstdio>
#include <algorithm>

using namespace std;

int trix[100][100];
int buf[100][100];
int is[100];
int js[100];

int main()
{
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; ++k)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			int maxI = 0;
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &trix[i][j]);
				buf[i][j] = 100;
				maxI = max(trix[i][j], maxI);
			}
			is[i] = maxI;
		}
		for (int j = 0; j < m; ++j)
		{
			int maxJ = 0;
			for (int i = 0; i < n; ++i)
			{
				maxJ = max(trix[i][j], maxJ);
			}
			js[j] = maxJ;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				buf[i][j] = min(buf[i][j], is[i]);
			}
		}
		for (int j = 0; j < m; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				buf[i][j] = min(buf[i][j], js[j]);
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				ok = ok && buf[i][j] == trix[i][j];
			}
		}
		
		printf("Case #%d: ", k + 1);
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
