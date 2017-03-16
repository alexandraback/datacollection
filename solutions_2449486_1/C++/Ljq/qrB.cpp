#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 120;

int r, c;
int m[MAXN][MAXN];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

inline bool Outside(int x, int y)
{
	return x < 0 || y < 0 || x >= r || y >= c;
}

bool Work()
{
	cin >> r >> c;
	for (int i = 0; i < r; i ++)
		for (int j = 0; j < c; j ++)
			cin >> m[i][j];

	for (int k = 99; k; k --)
		for (int i = 0; i < r; i ++)
			for (int j = 0; j < c; j ++) if (m[i][j] == k)
			{
				bool ok = true;
				for (int l = 0; l < r && ok; l ++)
					if (m[l][j] > k)  ok = false;
				if (ok)  continue;
				ok = true;
				for (int l = 0; l < c && ok; l ++)
					if (m[i][l] > k)  ok = false;
				if (ok)  continue;
				return false;
			}

	return true;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin.sync_with_stdio(false);

	int T;
	cin >>T;
	for (int tt = 1; tt <= T; tt ++)
		cout << "Case #" << tt << ": " << (Work()? "YES": "NO") << endl;

	return 0;
}