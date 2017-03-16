#define DEBUG 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bff[10];
bool vis[10];

int n, ans = 0;

vector<int> v;

bool eval()
{
	if (v.size() == 1) return true;
	bool works = true;
	if (v[v.size() - 1] != bff[v[0]] && v[1] != bff[v[0]]) works = false;
	if (works) {
		for (int i = 1; i < v.size() - 1; ++i) {
			if (v[i - 1] != bff[v[i]] && v[i + 1] != bff[v[i]]) {
				works = false;
				break;
			}
		}
	}
	if (v[v.size() - 2] != bff[v[v.size() - 1]] && v[0] != bff[v[v.size() - 1]]) works = false;
	return works;
}

void dfs(int i)
{
	if (i == n) return;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			v.push_back(i);
			if (eval()) {
				ans = max(ans, static_cast<int>(v.size()));
			}
			dfs(i + 1);
			v.pop_back();
			vis[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << fixed << setprecision(0);

	if (!DEBUG) {
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	}

	int _c, _start = static_cast<int>(clock());
	cin >> _c;

	for(int _cc = 1; _cc <= _c; ++_cc) {
		int _t = static_cast<int>(clock());
		cout << "Case #" << _cc << ": ";

		v.clear();
		ans = 0; 

		cin >> n;

		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i) {
			int f;
			cin >> f;
			bff[i] = f - 1;
		}

		dfs(0);

		cout << ans << endl;

		cerr << "[Case #" << _cc << " complete, " << static_cast<int>(clock() - _t) << " ms, " << 100. * _cc / _c << "%]" << endl;
	}

	cerr << "Total time: " << static_cast<int>(clock() - _start) << " ms" << endl;

	return 0;
}


