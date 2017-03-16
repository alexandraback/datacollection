#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T, t[110], f[110][110], n, s, p;
bool b[110][2];

int main()
{
	scanf("%d", &T);
	int ca = 0;
	while (T--)
	{
		ca++;
		memset(b, false, sizeof(b));
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 1; i <= n; i++)
			scanf("%d", &t[i]);
		printf("Case #%d: ", ca);
		for (int i = 1; i <= n; i++)
		{
			if (t[i] <= 28 && t[i] >= 2)
				if (t[i] >= p + 2 * (p - 2))
					b[i][0] = true;
				else b[i][0] = false;
			else b[i][0] = false;
			if (t[i] >= p + 2 * (p - 1))
				b[i][1] = true;
			else b[i][1] = false;
		}
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= s; j++)
				f[i][j] = f[i - 1][j] + b[i][1];
			for (int j = 1; j <= s; j++)
				if (f[i][j] < f[i - 1][j - 1] + b[i][0])
					f[i][j] = f[i - 1][j - 1] + b[i][0];
		}
		printf("%d\n", f[n][s]);
	}
	return 0;
}
