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
	map <pair <int, int>, double> m;
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	m[make_pair(0, 0)] += 1.0 / 1;
	if (n == 1)
		goto out;

	m[make_pair(-2, 0)] += 1.0 / 2;
	m[make_pair(2, 0)] += 1.0 / 2;
	if (n == 2)
		goto out;

	m[make_pair(-2, 0)] += 1.0 / 4;
	m[make_pair(2, 0)] += 1.0 / 4;
	m[make_pair(-1, 1)] += 1.0 / 4;
	m[make_pair(1, 1)] += 1.0 / 4;
	if (n == 3)
		goto out;

	m[make_pair(-2, 0)] += 1.0 / 4;
	m[make_pair(2, 0)] += 1.0 / 4;
	m[make_pair(-1, 1)] += 1.0 / 4;
	m[make_pair(1, 1)] += 1.0 / 4;
	if (n == 4)
		goto out;

	m[make_pair(-1, 1)] += 1.0 / 2;
	m[make_pair(1, 1)] += 1.0 / 2;
	if (n == 5)
		goto out;

	m[make_pair(0, 2)] += 1.0 / 1;
	if (n == 6)
		goto out;

	m[make_pair(-4, 0)] += 1.0 / 2;
	m[make_pair(4, 0)] += 1.0 / 2;
	if (n == 7)
		goto out;

	m[make_pair(-4, 0)] += 1.0 / 4;
	m[make_pair(4, 0)] += 1.0 / 4;
	m[make_pair(-3, 1)] += 1.0 / 4;
	m[make_pair(3, 1)] += 1.0 / 4;
	if (n == 8)
		goto out;

	m[make_pair(-4, 0)] += 1.0 / 8;
	m[make_pair(4, 0)] += 1.0 / 8;
	m[make_pair(-3, 1)] += 1.0 / 4;
	m[make_pair(3, 1)] += 1.0 / 4;
	m[make_pair(-2, 2)] += 1.0 / 8;
	m[make_pair(2, 2)] += 1.0 / 8;
	if (n == 9)
		goto out;

	m[make_pair(-4, 0)] += 1.0 / 16;
	m[make_pair(4, 0)] += 1.0 / 16;
	m[make_pair(-3, 1)] += 3.0 / 16;
	m[make_pair(3, 1)] += 3.0 / 16;
	m[make_pair(-2, 2)] += 3.0 / 16;
	m[make_pair(2, 2)] += 3.0 / 16;
	m[make_pair(-1, 3)] += 1.0 / 16;
	m[make_pair(1, 3)] += 1.0 / 16;
	if (n == 10)
		goto out;

	m[make_pair(-4, 0)] += 1.0 / 16;
	m[make_pair(4, 0)] += 1.0 / 16;
	m[make_pair(-3, 1)] += 3.0 / 16;
	m[make_pair(3, 1)] += 3.0 / 16;
	m[make_pair(-2, 2)] += 3.0 / 16;
	m[make_pair(2, 2)] += 3.0 / 16;
	m[make_pair(-1, 3)] += 1.0 / 16;
	m[make_pair(1, 3)] += 1.0 / 16;
	if (n == 11)
		goto out;

	m[make_pair(-3, 1)] += 1.0 / 8;
	m[make_pair(3, 1)] += 1.0 / 8;
	m[make_pair(-2, 2)] += 1.0 / 4;
	m[make_pair(2, 2)] += 1.0 / 4;
	m[make_pair(-1, 3)] += 1.0 / 8;
	m[make_pair(1, 3)] += 1.0 / 8;
	if (n == 12)
		goto out;

	m[make_pair(-2, 2)] += 1.0 / 4;
	m[make_pair(2, 2)] += 1.0 / 4;
	m[make_pair(-1, 3)] += 1.0 / 4;
	m[make_pair(1, 3)] += 1.0 / 4;
	if (n == 13)
		goto out;

	m[make_pair(-1, 3)] += 1.0 / 2;
	m[make_pair(1, 3)] += 1.0 / 2;
	if (n == 14)
		goto out;

	m[make_pair(0, 4)] += 1.0 / 1;
	if (n == 15)
		goto out;

	m[make_pair(-6, 0)] += 1.0 / 2;
	m[make_pair(6, 0)] += 1.0 / 2;
	if (n == 16)
		goto out;

	m[make_pair(-6, 0)] += 1.0 / 4;
	m[make_pair(6, 0)] += 1.0 / 4;
	m[make_pair(-5, 1)] += 1.0 / 4;
	m[make_pair(5, 1)] += 1.0 / 4;
	if (n == 17)
		goto out;

	m[make_pair(-6, 0)] += 1.0 / 8;
	m[make_pair(6, 0)] += 1.0 / 8;
	m[make_pair(-5, 1)] += 1.0 / 4;
	m[make_pair(5, 1)] += 1.0 / 4;
	m[make_pair(-4, 2)] += 1.0 / 8;
	m[make_pair(4, 2)] += 1.0 / 8;
	if (n == 18)
		goto out;

	m[make_pair(-6, 0)] += 1.0 / 16;
	m[make_pair(6, 0)] += 1.0 / 16;
	m[make_pair(-5, 1)] += 3.0 / 16;
	m[make_pair(5, 1)] += 3.0 / 16;
	m[make_pair(-4, 2)] += 3.0 / 16;
	m[make_pair(4, 2)] += 3.0 / 16;
	m[make_pair(-3, 3)] += 1.0 / 16;
	m[make_pair(3, 3)] += 1.0 / 16;
	if (n == 19)
		goto out;

	m[make_pair(-6, 0)] += 1.0 / 32;
	m[make_pair(6, 0)] += 1.0 / 32;
	m[make_pair(-5, 1)] += 1.0 / 8;
	m[make_pair(5, 1)] += 1.0 / 8;
	m[make_pair(-4, 2)] += 3.0 / 16;
	m[make_pair(4, 2)] += 3.0 / 16;
	m[make_pair(-3, 3)] += 1.0 / 8;
	m[make_pair(3, 3)] += 1.0 / 8;
	m[make_pair(-2, 4)] += 1.0 / 32;
	m[make_pair(2, 4)] += 1.0 / 32;
	if (n == 20)
		goto out;

out:
	printf("%.6f\n", m[make_pair(x, y)]);
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
