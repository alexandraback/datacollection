#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/home/ahmed/Desktop/D-large.in", "r", stdin);
	freopen("/home/ahmed/Desktop/D-large.out", "w", stdout);
	int t; scanf("%d", &t);
	int id = 1;
	while (t--) {
		int k, c, s; scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d:", id++);
		vector<long long> ans;
		for (int i = 0; i < k;) {
			int take = 1;
			long long index = i;
			while (take < c && i + take < k) {
				index *= k;
				index += i + take;
				take++;
			}
			ans.push_back(index);
			i += take;
		}
		if (int(ans.size()) > s)
			puts(" IMPOSSIBLE");
		else {
			for (int i = 0; i < int(ans.size()); i++)
				printf(" %lld", ans[i] + 1);
			puts("");
		}
	}
	return 0;
}
