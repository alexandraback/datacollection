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

int t, n;
string s;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	for (int ii = 1; ii <= t; ii++)
	{
		cin >> n >> s;
		int ans = 0, cur = 0;
		for (int i = 0; i <= n; i++)
		{
			int x = s[i] - '0';
			if (x == 0) continue;
			if (cur < i)
			{
				ans += i - cur;
				cur = i;
			}
			cur += x;
		}
		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}