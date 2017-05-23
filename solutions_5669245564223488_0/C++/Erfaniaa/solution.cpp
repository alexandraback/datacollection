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

int t, c[1010];
pair<string, int> s[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i].first;
			s[i].second = i;
		}
		do
		{
			bool valid = true;
			string tmp = "";
			for (int i = 1; i <= n; i++)
				tmp = tmp + s[i].first;
			tmp = tmp + "$";
			memset(c, -1, sizeof c);
			for (int i = 0; i <= SZ(tmp) - 2; i++)
				if (tmp[i] != tmp[i + 1])
				{
					if (c[tmp[i]] >= 0)
					{
						valid = false;
						break;
					}
					c[tmp[i]] = i;
				}
			if (valid)
				ans++;
		} while(next_permutation(s + 1, s + n + 1));
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}