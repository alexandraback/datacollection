#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define all(v) v.begin(), v.end()

int t, n; pair <int, int> s[201];
int x = 0;

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &t);
	cout << fixed << setprecision(6);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		scanf("%d", &n);
		x = 0;
		for (int j = 0; j < n; ++j)
			scanf("%d", &s[j].first), x+= s[j].first, s[j].second = j;
		ld y[201];int k = 1, x1 = x, x2 = x;
		sort (s, s+n, greater <pair <int, int> > ());
		for (int j = 0; j < n; ++j)
		{
			int xx = x1-s[j].first;
			int m = n - k;
			if (xx+x-m*s[j].first < 0) y[s[j].second] = 0.0, x1 -= s[j].first, k++;
			else y[s[j].second] = (xx+x-m*s[j].first)/((ld)((m+1)*x));
		}
		for (int j = 0; j < n; ++j) 
		{
			char delim = j == n - 1 ? '\n' : ' ';
			cout << y[j] * 100 << delim;
		}
	}
	return 0;
}