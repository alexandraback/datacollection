#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int A, n;
int x[100];

int main()
{
	//freopen("in", "r", stdin);

	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d %d", &A, &n);

		for(int i = 0; i < n; i++) scanf("%d", &x[i]);

		sort(x, x + n);
		
		int best = n;

		for(int add = 0; add < n; add++)
		{
			int k = 0;
			int cur = A;
			int to_add = add;

			while(k < n)
			{
				if (x[k] < cur)
				{
					cur += x[k];
					k++;
					continue;
				}

				if (!to_add) break;
				cur += cur - 1;
				to_add--;
			}

			best = min(best, add + n - k);
		}

		printf("%d\n", best);
	}
	return 0;
}