#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("garbled_email_dictionary.txt");
// ifstream fin("dict.txt");

int tot;
string dict[530000];
string s;
int f[60][60];

bool chk(int p, string m, int k, int &t, int &w)
{
	t = k;
	w = 0;
	for (int i = 0; i < (int)m.size(); ++i) {
		if (s[p + i] != m[i]) {
			if (p + i - t < 5) return false;
			t = p + i;
			++w;
		}
	}
	return true;
}

int dfs(int p, int k)
{
	if (p == (int)s.size()) return 0;
	if (f[p][k + 5] != -1) return f[p][k + 5];
	int ret = s.size();
	for (int i = 0; i < tot; ++i) {
		if (dict[i].size() > s.size() - p) break;
		int t, w;
		if (chk(p, dict[i], k, t, w)) {
			if (w > ret) continue;
			ret = min(ret, w + dfs(p + dict[i].size(), t));
		}
	}
	return f[p][k + 5] = ret;
}

int main()
{
	while (fin >> dict[tot++]);
	--tot;
	sort(dict, dict + tot, [](const string &lhs, const string &rhs) {
				return lhs.size() < rhs.size();
			});
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		cin >> s;
		for (int i = 0; i < 60; ++i) {
			for (int j = 0; j < 60; ++j) {
				f[i][j] = -1;
			}
		}
		cout << "Case #" << k << ": " << dfs(0, -5) << endl;
	}
}
