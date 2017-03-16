#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int,int> mp;

int main() {
	int T, n;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		mp.clear();
		for (int i = 0 ; i < 2 * n - 1 ; i++) {
			for (int j = 0 ; j < n ; ++j) {
				int tmp;
				scanf("%d", &tmp);
				++mp[tmp];
			}
		}
		vector<int> ans;
		for (auto itr = mp.begin() ; itr != mp.end() ; ++itr) {
			if (itr->second % 2 == 1) {
				ans.push_back(itr->first);
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d:", ca);
		for (int i = 0 ; i < ans.size() ; ++i)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}