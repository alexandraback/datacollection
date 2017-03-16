#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound

const double eps = 1e-8;
const double pi = acos(-1.0);

int n, a[2100], b[2100], bla[2100], blb[2100];
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", a + i, b + i);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (b[i] < b[j]) swap(b[i], b[j]), swap(a[i], a[j]);
		memset(bla, 0, sizeof bla);
		memset(blb, 0, sizeof blb);
		int two = 0, now = 0, ans = 0;
		while (two < n) {
			bool flag = 0;
			for (int i = n - 1; i >= 0; i--)
				if (!blb[i] && b[i] <= now) {
					if (bla[i]) now += 1;
					else now += 2;
					blb[i] = 1;
					bla[i] = 1;
					ans++;
					flag = 1;
					two++;
				}
			if (!flag)
				for (int i = 0; i < n; i++)
					if (!bla[i] && a[i] <= now) {
						bla[i] = 1;
						now += 1;
						ans++;
						flag = 1;
						break;
					}
			if (!flag)
				break;
		}
		printf("Case #%d: ", ++ca);
		if (two == n) printf("%d\n", ans);
		else puts("Too Bad");
	}
}
