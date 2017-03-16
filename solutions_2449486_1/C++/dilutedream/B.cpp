#include <cstdio>

using namespace std;

const int MAXN = 101;

int n, m;
int a [MAXN][MAXN];

int main () {
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);
	
	int task; scanf ("%d\n", &task);
	for (int t = 1; t <= task; ++t) {
		scanf ("%d %d\n", &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf ("%d", &a [i][j]);
	
		bool yes = true;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				int x = a [i][j];
				
				bool yes1 = true;
				for (int k = 1; k <= n; ++k)
					if (a [k][j] > x)
						yes1 = false;
				
				bool yes2 = true;
				for (int k = 1; k <= m; ++k)
					if (a [i][k] > x)
						yes2 = false;
				
				if (!yes1 && !yes2)
					yes = false;
			}
		
		printf ("Case #%d: %s\n", t, (yes) ? "YES" : "NO");
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
