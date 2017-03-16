//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
using namespace std;

inline int read() {
	static int r;
	static char c;
	r = 0, c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (c - '0'), c = getchar();
	return r;
}

typedef long long ll;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

int T, n, m, k, a[100];

int main() {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%*d%d%d%d%d", &T, &n, &m, &k);
	printf("Case #1:\n");
	while (T--) {
		for (int i = 1; i <= k; ++i) scanf("%d", a + i);
		
		bool ok = false;
		for (int x = 2; !ok && x <= m; ++x)
			for (int y = 2; !ok && y <= m; ++y)
				for (int z = 2; !ok && z <= m; ++z) {
					ok = true;
					for (int i = 1; ok && i <= k; ++i) {
						if (a[i] == 1) continue;
						if (a[i] == x || a[i] == y || a[i] == z) continue;
						if (a[i] == x * y || a[i] == x * z || a[i] == y * z) continue;
						if (a[i] == x * y * z) continue;
						ok = false;
					}
					if (ok) {
						printf("%d%d%d\n", x, y, z);
						break;
					}
				}
		
	}
	
	return 0;
}

