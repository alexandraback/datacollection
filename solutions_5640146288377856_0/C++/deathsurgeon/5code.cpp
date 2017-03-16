/* [themighty] deathsurgeon (Rupesh Maity)
* 2nd year, B.Tech in IT
* IIIT - Allahabad
*/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef unsigned uint;
typedef pair<int, int> pii;

#define MOD 1000000007
#define MAX 1000000
#define pb push_back
#define yes puts("YES")
#define no puts("NO")
#define sd(x) scanf("%d", &x)
#define PI 3.14159265

int main() {
	freopen("5input.txt", "r", stdin);
	freopen("5output.txt", "w", stdout);
	int t;
	cin >> t;

	int sum[21][21];

	for (int i = 1; i < 21; i++) {
		sum[i][i] = i;
		for (int j = i + 1; j <= 2 * i && j<21; j++)
			sum[i][j] = i + 1;
		for (int j = 2*i + 1; j < 21; j++) {
			sum[i][j] = sum[i][j - i] + 1;
		}
	}

	for (int cas = 1; cas <= t; cas++) {
		printf("Case #%d: ", cas);
		LL ans = 0;
		int r, c, w;
		cin >> r >> c >> w;
		if (r != 1) {
			ans = r - 1;
			ans *= c / w;
			if (c%w)
				ans += r - 1;
		}
		cout << ans + sum[w][c] << endl;
	}

	return 0;
}
