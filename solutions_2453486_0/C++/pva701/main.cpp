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
char a[5][5];
int n = 4;
string solve()
{
	bool has = false;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
			has |= a[i][j] == '.';
		}
	bool winx[12] = {0}, wino[12] = {0};
	for (int i = 0; i < 12; ++i) wino[i] = winx[i] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			winx[i] &= a[i][j] == 'X' || a[i][j] == 'T';
			wino[i] &= a[i][j] == 'O' || a[i][j] == 'T';
			winx[i + n] &= a[j][i] == 'X' || a[j][i] == 'T';
			wino[i + n] &= a[j][i] == 'O' || a[j][i] == 'T';
		}
		winx[2 * n] &= a[i][i] == 'X' || a[i][i] == 'T';
		winx[2 * n + 1] &= a[i][n - i - 1] == 'X' || a[i][n - i - 1] == 'T';
		wino[2 * n] &= a[i][i] == 'O' || a[i][i] == 'T';
		wino[2 * n + 1] &= a[i][n - i - 1] == 'O' || a[i][n - i - 1] == 'T';
	}
	bool wx = false, wo = false;
	for (int i = 0; i <= 2 * n + 1; ++i)
	{
		wx |= winx[i];
		wo |= wino[i];
	}
	assert(wx && wo);
	if (wx) return "X won";
	if (wo) return "O won";
	if (has) return "Game has not completed";
	return "Draw";
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
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
