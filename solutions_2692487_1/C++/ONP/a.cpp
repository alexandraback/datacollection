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

int n, a[1100000];
long long A;
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		cin >> A >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		int best = n;
		int total = 0;
		if (A != 1)
			for (int i = 0; i < n; i++) {
				while (A <= a[i]) {
					total++;
					A += A - 1;
				}
				A += a[i];
				best = min(best, total + n - i - 1);
			}
		printf("Case #%d: %d\n", ++ca, best);
	}
}
