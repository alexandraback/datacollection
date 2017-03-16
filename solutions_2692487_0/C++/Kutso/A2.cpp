#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

const int NMAX = 1000001;

long long M[NMAX], sz, n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++)
	{
		cin>>sz>>n;
		for (int i = 0; i < n; i++)
			cin>>M[i];

		sort(M, M + n);
		int ans = n, cur = 0;
		for (int i = 0; i < n; i++)
			if (sz > M[i])
			{
				sz += M[i];
				if (cur + n - i - 1 < ans)
					ans = cur + n - i - 1;
			}
			else
			{
				if (cur + n - i < ans)
					ans = cur + n - i;
				

				if (sz == 1)
					break;

				while (sz <= M[i])
				{
					sz += sz - 1;
					cur++;
				}

				sz += M[i];

				if (cur + n - i - 1 < ans)
					ans = cur + n - i - 1;
			}



		printf("Case #%d: %d\n", test + 1, ans);
	}


	return 0;
}