/*	In the name of God	*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

using namespace std;

int n, a[10001];
int main(){

	freopen("B-large.in", "r", stdin);
	freopen("program.out", "w", stdout);

	int tc, r, m;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++)
	{
		scanf("%d", &n);
		m = 0;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			m = max(m, a[i]);
		}
		r = m;
		for (size_t x = 2; x < m; x++)
		{
			int ans = x;
			for (size_t i = 0; i < n; i++)
			{
				ans += (a[i] - 1) / x;
			}
			r = min(ans, r);
		}
		printf("Case #%d: %d\n", ti, r);
	}

	return 0;
}