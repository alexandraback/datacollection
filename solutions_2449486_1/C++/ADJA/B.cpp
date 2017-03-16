#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

int t, n, m;
int a[105][105], d[105][105];

int main() {
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
				d[i][j] = 100;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			int mx = -1;
			for (int j = 1; j <= m; j++) 
				mx = max(mx, a[i][j]);
			for (int j = 1; j <= m; j++) 
				d[i][j] = min(d[i][j], mx);
		}

		for (int j = 1; j <= m; j++) {
			int mx = -1;
			for (int i = 1; i <= n; i++) 
				mx = max(mx, a[i][j]);
			for (int i = 1; i <= n; i++) 
				d[i][j] = min(d[i][j], mx);
		}

		bool same = true;

		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				if (d[i][j] != a[i][j]) 
					same = false;

		if (same) 
			printf("Case #%d: YES\n", test);
		else
			printf("Case #%d: NO\n", test);
	}

	return 0;
}