#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

struct Three
{
	int x, y, z;
	Three(int _x = 0, int _y = 0, int _z = 0)
	{
		x = _x;
		y = _y;
		z = _z;
	}
} outfits[110];

int t, sum[3][4][4];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		cout << "Case #" << tt << ": ";
		int cnt = 0;
		for (int i = 1; i <= a; i++)
			for (int j = 1; j <= b; j++)
				for (int k = 1; k <= c; k++)
					outfits[cnt++] = Three(i, j, k);
		int maxMask = 0;
		for (int mask = 1; mask < (1 << cnt); mask++)
		{
			memset(sum, 0, sizeof sum);
			bool valid = true;
			for (int i = 0; i < cnt; i++)
			{
				if (mask & (1 << i))
				{
					Three e = outfits[i];
					sum[0][e.x][e.y]++;
					sum[1][e.x][e.z]++;
					sum[2][e.y][e.z]++;
					if (sum[0][e.x][e.y] > k || sum[1][e.x][e.z] > k || sum[2][e.y][e.z] > k)
					{
						valid = false;
						break;
					}
				}
			}
			if (valid && __builtin_popcount(mask) > __builtin_popcount(maxMask))
				maxMask = mask;
		}
		cout << __builtin_popcount(maxMask) << endl;
		for (int i = 0; i < cnt; i++)
			if (maxMask & (1 << i))
				cout << outfits[i].x << " " << outfits[i].y << " " << outfits[i].z << endl;
	}
	return 0;
}