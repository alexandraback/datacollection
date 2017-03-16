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

int a[100][100];

bool good[100][100];


int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		int n, m;
		scanf("%d %d", &n, &m);
		
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);

		while(1)
		{
			int low = 100;
			for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) low = min(low, a[i][j]);

			if (low == 100)
			{
				puts("YES");
				break;
			}

			memset(good, 0, sizeof good);

			for(int i = 0; i < n; i++)
			if (a[i][0] == low)
			{
				bool ok = true;
				for(int j = 0; j < m; j++) if (a[i][j] != low) ok = false;
				if (ok) for(int j = 0; j < m; j++) good[i][j] = true;
			}

			for(int j = 0; j < m; j++)
			if (a[0][j] == low)
			{
				bool ok = true;
				for(int i = 0; i < n; i++) if (a[i][j] != low) ok = false;
				if (ok) for(int i = 0; i < n; i++) good[i][j] = true;
			}

			for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if (a[i][j] == low && !good[i][j]) { puts("NO"); goto qq;}

			for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if (a[i][j] == low) a[i][j]++;
		}

		qq: ;
	}
	return 0;
}