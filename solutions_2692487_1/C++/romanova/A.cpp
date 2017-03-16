#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

long long d[200][1000];
int mas[105];

int main()
{

	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, a, n;
	cin >> t;
	for(int tt = 0; tt < t; ++tt)
	{
		scanf("%d%d", &a, &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &mas[i]);
		sort(mas+1, mas+n+1);
		memset(d, -1, sizeof(d));

		d[0][0] = a;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j <= 100; ++j)
			{
				if(d[i][j] > 0)
				{
					long long q = d[i][j];
					for(int k = j; k <= 100; ++k)
					{
						if(q > mas[i+1])
						{
							d[i+1][k] = max(d[i+1][k], q+mas[i+1]);
							break;
						}
						else
							q += q-1;
					}
					d[i+1][j+1] = max(d[i+1][j+1], d[i][j]);
				}
			}
		}

		int ans = 0;
		for(int i = 0; i <= 100; ++i)
			if(d[n][i] >= 0)
			{
				printf("Case #%d: %d\n", tt+1, i); 
				break;
			}
	}
	



	return 0;
}