#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int T, N, M, D, sx, sy, ans;
char	line[999], map[100][100], Hash[200][200];

inline bool	check(int x, int d1, int d2)
{
	if (x == 0) return 1;
	if (x < 0) return check(-x, d2, d1);
	for (; x > 0; x -= d1 + d2)
		if (x - d1 == 0)	return 1;
	if (x == 0) return 1;
	return 0;
}

inline int	gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}

inline bool	get_hash(int x, int y)
{
	if (x == 0)
	{
		if (y != 0) y = y / abs(y);
	}	else
	if (y == 0)
	{
		x = x / abs(x);
	}	else
	{
		int d = gcd(abs(x), abs(y));
		x /= d; y /= d;
	}
	if (Hash[x + 50][y + 50]) return 0;
	Hash[x + 50][y + 50] = 1;
	return 1;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t)
	{
		printf("Case #%d: ", t);
		scanf("%d%d%d", &N, &M, &D); gets(line);
		for (int i = 1; i <= N; ++ i)
		{
			for (int j = 1; j <= M; ++ j)
			{
				map[i][j] = getchar();
				if (map[i][j] == 'X')
				{
					sx = i; sy = j;
				}
			}
			gets(line);
		}
		
		ans = 0;
		memset(Hash, 0, sizeof(Hash));
		for (int i = -D; i <= D; ++ i)	if (check(i, 2 * N - 2 * sx - 1, sx * 2 - 3))
			for (int j = -D; j <= D; ++ j)
				if (i * i + j * j <= D * D)
					if (check(j, 2 * M - 2 * sy - 1, sy * 2 - 3))
						if (get_hash(i, j))
							++ ans;
		printf("%d\n", ans - 1);
	}
	return 0;
}
		
