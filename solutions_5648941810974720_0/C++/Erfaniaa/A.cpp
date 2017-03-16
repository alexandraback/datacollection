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

int cntStr[256], cnt[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		memset(cnt, 0, sizeof cnt);
		memset(cntStr, 0, sizeof cntStr);
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
			cntStr[s[i]]++;
		cnt[0] = cntStr['Z'];
		cnt[2] = cntStr['W'];
		cnt[6] = cntStr['X'];
		cnt[8] = cntStr['G'];
		cnt[4] = cntStr['U'];
		cnt[3] = cntStr['H'] - cntStr['G'];
		cnt[5] = cntStr['F'] - cntStr['U'];
		cnt[7] = cntStr['S'] - cntStr['X'];
		cnt[1] = cntStr['O'] - cntStr['W'] - cntStr['U'] - cntStr['Z'];
		cnt[9] = (cntStr['N'] - cnt[7] - cnt[1]) / 2;
		cout << "Case #" << tt << ": ";
		for (int i = 0; i < 10; i++)
			for (int j = 1; j <= cnt[i]; j++)
				cout << i;
		cout << endl;
	}
	return 0;
}