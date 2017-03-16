#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long int64;
const double pi = acos (-1.0);
const double eps = 1.0e-10;

void solve()
{
	int a, n, f[110];
	int ans = 0;
	int now = 0;
	scanf("%d%d", &a, &n);
	ans = n;
	for (int i = 0; i < n; ++i)
		scanf("%d", &f[i]);
	sort(f, f + n);
	for (int i = 0; i < n; ++i) {
		while (a <= f[i]) {
			a += a - 1;
			now++;
			if (now > ans)
				break;
		}
		a += f[i];
		ans = min(ans, now + n - i - 1);
	}
	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int icase = 1; icase <= ncase; ++icase) {
		printf("Case #%d: ", icase);
		solve();
	}
}
