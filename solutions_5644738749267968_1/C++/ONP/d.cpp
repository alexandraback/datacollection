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

const double pi = acos(-1.);
const double eps = 1e-6;

int n;
double a[11000], b[11000];
int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf", a + i);
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			scanf("%lf", b + i);
		sort(b, b + n);
		int h, t = 0, ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++) {
			while (t < n && b[t] < a[i]) t++;
			if (t == n) break;
			ans2++;
			t++;
		}
		h = 0, t = n - 1;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[h]) {
				h++;
			} else t--, ans1++;
		}
		printf("Case #%d: %d %d\n", ++ca, n - ans1, n - ans2);
	}
}
