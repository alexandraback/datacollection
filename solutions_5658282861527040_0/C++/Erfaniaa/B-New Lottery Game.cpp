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
#define MAXN 110

int t, a, b, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> a >> b >> k;
		cout << "Case #" << tt << ": ";
		int ans = 0;
		for (int x = 0; x < a; x++)
			for (int y = 0; y < b; y++)
				if ((x & y) < k)
					ans++;
		cout << ans << endl;
	}
	return 0;
}