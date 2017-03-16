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

int tn, ans;
int e, r, n;
int v[100000];
int d[100][50];

int main() {
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &tn);

	for (int test = 1; test <= tn; test++) {
		ans = 0;

		scanf("%d %d %d", &e, &r, &n);
		for (int i = 1; i <= n; i++) 
			scanf("%d", &v[i]);

		for (int i = 1; i <= n + 5; i++) 
			for (int j = 0; j <= e; j++) 
				d[i][j] = -1;

		d[1][e] = 0;

		for (int i = 1; i <= n; i++) 
			for (int j = 0; j <= e; j++) {
				if (d[i][j] == -1)
					continue;
				for (int k = 0; k <= j; k++) {
					d[i + 1][min(j - k + r, e)] = max(d[i + 1][min(j - k + r, e)], d[i][j] + v[i] * k);
				}
			}

		for (int i = 0; i <= e; i++) 
			ans = max(ans, d[n + 1][i]);

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}