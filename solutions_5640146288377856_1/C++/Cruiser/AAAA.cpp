#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;
	forn(ttt, tc) {
		int n, m, w;
		cin >> n >> m >> w;
		int c = m / w;
		if (m % w == 0)
			c += w - 1;
		else
			c += w;
		printf("Case #%d: %d\n", ttt + 1, (m / w) * (n - 1) + c);
	}
}