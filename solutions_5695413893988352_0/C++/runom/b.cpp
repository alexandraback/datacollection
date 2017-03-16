#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

string s[2];
vector<int> t[2];

void dfs(int k, int i, int res)
{
	if(i == s[0].size()) {
//		cout << k << ' ' << i << ' ' << res << endl;
		t[k].push_back(res);
		return;
	}

	if(s[k][i] != '?') {
		dfs(k, i + 1, res * 10 + (s[k][i] - '0'));
	} else {
		for(int j = 0; j < 10; ++j) {
			dfs(k, i + 1, res * 10 + j);
		}
	}
}

int main()
{
	int T; 
	cin >> T;
	for(int k = 1; k <= T; ++k) {
		cout << "Case #" << k << ": ";
		cin >> s[0] >> s[1];
		t[0].clear();
		t[1].clear();
		int len = s[0].size();
		
		dfs(0, 0, 0);
		dfs(1, 0, 0);

		int dif = 1 << 26;
		int ans[2];

		for(int i = 0; i < t[0].size(); ++i) {
			for(int j = 0; j < t[1].size(); ++j) {
				int dif_ij = abs(t[0][i] - t[1][j]);
				if(dif_ij < dif) {
					dif = dif_ij;
					ans[0] = t[0][i];
					ans[1] = t[1][j];
				} else if(dif_ij == dif) {
					if(t[0][i] < ans[0]) {
						ans[0] = t[0][i];
						ans[1] = t[1][j];
					} else if(t[0][i] == ans[0] && t[1][j] < ans[1]){
						ans[0] = t[0][i];
						ans[1] = t[1][j];
					}
				}
			}
		}

		cout << setfill('0') << setw(s[0].size()) << ans[0] << ' ' << setfill('0') << setw(s[0].size()) <<  ans[1] << endl;
	}
}
