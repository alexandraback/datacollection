#include <functional>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstdio>
#include <complex>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

#define int64 long long
#define mp make_pair

const int inf = 1e9;

#ifdef _DEBUG
    const int N = 3010;
#else
    const int N = 300010;
#endif

int t, n, a[N];
multiset <int> st;
string s;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = inf;
		for (int i = 1; i <= 1000; i++)
		{
			int cur = i;
			for (int j = 1; j <= n; j++)
				if (a[j] > i)
				{
					int val;
					if (a[j] % i == 0) val = a[j] / i - 1;
					else val = a[j] / i;
					cur += val;
				}
			ans = min(ans, cur);
		}
		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}