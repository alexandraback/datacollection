#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = 3.1415926535;
const double eps = 1e-6;

int a[1100], f[110][110], n, s, p;
void update(int &a, int b)
{
	if (a == -1 || a < b) a = b;
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		memset(f, -1, sizeof f); f[0][0] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= s; j++)
				if (f[i - 1][j] != -1) {
					int tmp = a[i] / 3;
					if (a[i] % 3 == 0) {
						update(f[i][j], f[i - 1][j] + (int)(tmp >= p));
						if (j < s && tmp + 1 <= 10 && tmp - 1 >= 0)
							update(f[i][j + 1], f[i - 1][j] + (int)(tmp + 1 >= p));
					} else if (a[i] % 3 == 1) {
						update(f[i][j], f[i - 1][j] + (int)(tmp + 1 >= p));
						if (j < s && tmp + 1 <= 10 && tmp - 1 >= 0)
							update(f[i][j + 1], f[i - 1][j] + (int)(tmp + 1 >= p));
					} else {
						if (j < s && tmp + 2 <= 10)
							update(f[i][j + 1], f[i - 1][j] + (int)(tmp + 2 >= p));
						if (tmp + 1 <= 10)
							update(f[i][j], f[i - 1][j] + (int)(tmp + 1 >= p));
					}
				}
		printf("Case #%d: %d\n", ++ca, f[n][s]);
	}
}
