#pragma comment (linker, "/STACK:268435456")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;
template <class T> T sqr(T a) { return a * a; }

int n, m;
int a[110][110];

int check(int r, int c, int dr, int dc, int value)
{
	if (r < 0 || c < 0 || r >= n || c >= m)
		return 1;
	if (a[r][c] > value)
		return 0;
	return check(r + dr, c + dc, dr, dc, value);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tn;
	cin >> tn;
	for (int tc = 0; tc < tn; tc++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		int ok = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ok &= check(i, j, 0, -1, a[i][j]) && check(i, j, 0, 1, a[i][j]) || check(i, j, 1, 0, a[i][j]) && check(i, j, -1, 0, a[i][j]);
		cout << "Case #" << tc + 1 << ": " << (ok ? "YES" : "NO");
		cout << endl;
	}
	return 0;
}