#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

string s[100];
int g[26], count[26], f[26];
const long long mo = 1000000007;

bool check(string& s)
{
	string rtn(1, s[0]);
	for (int i = 1; i < s.size(); ++i)
		if (s[i] != s[i - 1]) rtn.push_back(s[i]);
	for (int i = 0; i < rtn.size(); ++i)
		for (int j = i + 1; j < rtn.size(); ++j)
			if (rtn[i] == rtn[j]) return false;
	s = rtn;
	return true;
}

int main()
{
	ifstream fin("b.in");
	ofstream fout("b.out");
	
	int T;
	fin >> T;
	
	for (int t = 1; t <= T; ++t) {
		fout << "Case #" << t << ": ";
		int n; fin >> n;
		bool flag = true;
		for (int i = 0; i < n; ++i)
			fin >> s[i];
		for (int i = 0; i < n; ++i)
			if (!check(s[i])) {
				flag = false;
			}
		
		for (int i = 0; i < 26; ++i) {
			g[i] = f[i] = -1;
			count[i] = 0;
		}
		
		for (int i = 0; i < n; ++i) {
			if (s[i].size() == 1) {
				int id = s[i][0] - 'a';
				if (count[id] == -1) {
					flag = false;
					break;
				}
				++count[id];
			}
			else {
				for (int j = 1; j < s[i].size() - 1; ++j) {
					int id = s[i][j] - 'a';
					if (count[id] > 0 || g[id] >= 0) {
						flag = false;
						break;
					}
					count[id] = -1;
				}
				int v1 = s[i][0] - 'a', v2 = s[i][s[i].size() - 1] - 'a';
				if (count[v1] == -1 || count[v2] == -1 || g[v1] != -1 || f[v2] != -1) {
					flag = false;
				}
				if (!flag) break;
				g[v1] = v2;
				f[v2] = v1;
			}
		}
		
		cout << "edges: " << endl;
		for (int i = 0; i < 26; ++i)
			if (g[i] >= 0)
				cout << i << " " << g[i] << endl;
		cout << "chain: " << endl;;
				
		if (flag) {
			bool vis[26];
			for (int i = 0; i < 26; ++i) vis[i] = false;
			int len = 0;
			long long ans = 1;
			for (int i = 0; i < 26; ++i)
				if (!vis[i]) {
					int k = i;
					while (f[k] != -1) {
						k = f[k];
						if (k == i) {
							ans = 0;
							break;
						}
					}
					if (count[k] > 0 || g[k] >= 0) {
						++len;
						ans = ans * len % mo;
					}
					else continue;
					long long tmp = 1;
					for (int p = 0; p < count[k]; ++p)
						tmp = tmp * (p + 1) % mo;
					vis[k] = true;
					cout << k << " ";
					while (g[k] != -1) {
						k = g[k];
						cout << k << " ";
						if (vis[k] == true) {
							ans = 0;
							break;
						}
						vis[k] = true;
						for (int p = 0; p < count[k]; ++p)
							tmp = tmp * (p + 1) % mo;
					}
					cout << endl;
					ans = ans * tmp % mo;
				}
			fout << ans << endl;
		}
		else fout << 0 << endl;
	}
	return 0;
}
