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
int n;
double a[1000], b[1000];
bool used[1000];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%lf", &a[i]);
		for(int i = 0; i < n; i++) scanf("%lf", &b[i]);

		sort(a, a + n);
		sort(b, b + n);

		int res1 = 0, res2 = 0;

		int pa = 0, pb = 0;
		while(pb < n)
		{
			while(pa < n && a[pa] < b[pb]) pa++;
			if (pa == n) break;
			res1++;
			pa++;
			pb++;
		}

		fill(used, used + n, false);
		for(int i = 0; i < n; i++)
		{
			int pick = -1;
			for(int j = 0; j < n; j++) if (b[j] > a[i] && !used[j]) { pick = j; break; }
			if (pick == -1)
			{
				for(int j = 0; j < n; j++) if (!used[j]) { pick = j; break; }
			}
			assert(pick != -1);
			if (a[i] > b[pick]) res2++;
			used[pick] = true;
		}

		assert(res1 >= res2);
		printf("%d %d\n", res1, res2);
	}
	return 0;
}