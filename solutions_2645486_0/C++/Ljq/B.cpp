#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 11000;

int e, r, n;
int v[MAXN];
int f[MAXN][12];

long long Work()
{
	cin >> e >> r >> n;
	for (int i = 0; i < n; i ++)
		cin >> v[i];
	memset(f, 0xff, sizeof(f));
	f[0][e] = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= e; j ++)  if (f[i][j] >= 0)
		{
			for (int k = 0; k <= j; k ++)
				f[i+1][min(j-k+r,e)] = max(f[i+1][min(j-k+r,e)], f[i][j] + k * v[i]);
		}
	return f[n][min(e, r)];
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-ans.txt", "w", stdout);

	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt ++)
		cout << "Case #" << tt << ": " << Work() << endl; 

	return 0;
}