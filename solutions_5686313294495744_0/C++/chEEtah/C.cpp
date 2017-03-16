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

char a[100], b[100];
map<string, int> dict;
int sizeDict;

int x[1000], y[1000];

int lookup(string s)
{
	if (dict.count(s)) return dict[s];
	sizeDict++;
	dict[s] = sizeDict - 1;
	return sizeDict - 1;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		dict.clear();
		sizeDict = 0;

		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
		{
			scanf("%s %s", a, b);
			x[i] = lookup(a);
			y[i] = lookup(b);
		}

		int all = 1 << n;
		int best = 0;
		for(int mask = 0; mask < all; mask++)
		{
			int cur = 0;
			for(int j = 0; j < n; j++) if (mask & (1 << j)) cur++;
			if (cur <= best) continue;

			set<int> X, Y;

			for(int j = 0; j < n; j++)
				if (!(mask & (1 << j)))
				{
					X.insert(x[j]);
					Y.insert(y[j]);
				}

			bool ok = true;
			for(int j = 0; j < n; j++)
				if (mask & (1 << j))
				if (!X.count(x[j]) || !Y.count(y[j]))
				{
					ok = false;
					break;
				}
			if (ok) best = cur;
		}
		printf("%d\n", best);
	}
	return 0;
}