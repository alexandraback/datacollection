#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1010;

int main() {
	int cas;
	scanf("%d", &cas);
	for (int re = 1; re <= cas; re++) {
		int n;
		scanf("%d", &n);
		map<int, int> mp;
		for (int i = 0; i < 2*n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int k;
				scanf("%d", &k);
				mp[k]++;
			}
		}
		vector<int> ans;
		for (auto& it : mp) {
			if (it.second % 2 == 1) {
				ans.push_back(it.first);
			}
		}
		printf("Case #%d:", re);
		for (int i = 0; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
}