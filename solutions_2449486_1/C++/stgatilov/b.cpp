#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int m, n;
int matr[1024][1024];
int rows[1024], cols[1024];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d%d", &m, &n);
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				scanf("%d", &matr[i][j]);

		memset(rows, -63, sizeof(rows));
		memset(cols, -63, sizeof(cols));
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++) {
				rows[i] = max(rows[i], matr[i][j]);
				cols[j] = max(cols[j], matr[i][j]);
			}
		bool ok = true;
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				ok &= (matr[i][j] == min(rows[i], cols[j]));

		printf("Case #%d: ", tt);
		printf("%s", ok ? "YES" : "NO");
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
