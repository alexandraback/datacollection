#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

int const size = 200;

long long a[size], A[size], b[size], B[size];
long long oldb[size];

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, it, n, m, t, j;

	scanf("%d", &it);
	for (t = 1; t <= it; t++)
	{
		printf("Case #%d: ", t);
		scanf("%d %d", &n, &m);
		for (i = 0; i < 3; i++)
			A[i] = 0;
		for (i = 0; i < n; i++)
			cin >> a[i] >> A[i];
		for (i = 0; i < m; i++)
			cin >> oldb[i] >> B[i];
		long long ans = 0;
		for (i = 0; i <= m; i++)
			for (j = i; j < m; j++)
			{
				long long locans = 0;
				for (int k = 0; k < m; k++)
					b[k] = oldb[k];
				long long x = a[0], y = a[1], z = a[2];
				long long dif;
				for (int k = 0; k <= i; k++)
					if (B[k] == A[0])
					{
						dif = min(x, b[k]);
						x -= dif;
						b[k] -= dif;
						locans += dif;
					}
				for (int k = i; k <= j; k++)
					if (B[k] == A[1])
					{
						dif = min(y, b[k]);
						y -= dif;
						b[k] -= dif;
						locans += dif;
					}
				for (int k = j; k < m; k++)
					if (B[k] == A[2])
					{
						dif = min(z, b[k]);
						z -= dif;
						b[k] -= dif;
						locans += dif;
					}
				if (locans > ans)
					ans = locans;
			}
			cout << ans << endl;
	}

	return 0;
}