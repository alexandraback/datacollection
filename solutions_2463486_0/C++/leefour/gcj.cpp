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

vector <int64> v;

bool check(int64 m)
{
	int64 res = 0, n = m;
	while (n) {
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	return (res == m);
}

void solve()
{
	int64 a, b;
	int res = 0;
	scanf("%lld%lld", &a, &b);
	for (int i = 0; i < v.size(); ++i) {
		if (a <= v[i] && v[i] <= b)
			res++;
	}
	printf("%d\n", res);
}

int main()
{
	for (int64 i = 1; i < 10000010; ++i)
		if (check(i) && check(i * i))
			v.push_back(i * i);
	sort(v.begin(), v.end());
	int ncase;
	scanf("%d", &ncase);
	for (int icase = 1; icase <= ncase; ++icase) {
		printf("Case #%d: ", icase);
		solve();
	}
}
