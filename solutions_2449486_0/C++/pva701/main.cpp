#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;
typedef long double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define y1 djeudyw92
const int MOD = 1e9 + 7;
const int N = 105;
int a[N][N], n, m;
string solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			bool h1 = true, h2 = true;
			for (int k = 0; k < m; ++k)
				h1 &= a[i][j] >= a[i][k];
			for (int k = 0; k < n; ++k)
				h2 &= a[i][j] >= a[k][j];
			if (!h1 && !h2) return "NO";
		}
	return "YES";
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout); 
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) 
	{
		string ans = solve();
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
