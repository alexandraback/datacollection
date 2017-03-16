#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
ll d[501];
int main() {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%lld", &d[i]);

		sort(d, d+n);
		ll sum=0;
		for (int i=0; i<n; i++) sum += d[i];
		for (int i=n-1; i>=0; i--) {
			if (sum - d[i] < d[i]) {
				n--;
				sum -= d[i];
			}
		}


		vector<pair<int, int>> lst[2];
		lst[1].push_back(make_pair(0, 0));
		bool found = false;
		printf("Case #%d:\n", t);
		for (int i=0; i<n && !found; i++) {
			vector<pair<int, int> >& cur = lst[i&1];
			vector<pair<int, int> >& prev = lst[(i-1)&1];
			cur.clear();
			for (vector<pair<int, int> >::iterator it = prev.begin(); it != prev.end(); it++) {
				cur.push_back(*it);
				cur.push_back(make_pair(it->first + d[i], it->second | (1<<i)));
			}
			sort(cur.begin(), cur.end());
			for (int i=1; i<cur.size() && !found; i++)
				if (cur[i-1].first == cur[i].first) {
					found = true;
					int first_set = cur[i-1].second;
					int second_set = cur[i].second;
					int intersect = first_set & second_set;
					first_set = first_set & (~intersect);
					second_set = second_set & (~intersect);

					for (int j=0; j<n; j++)
						if ((1<<j)&first_set) printf("%d ", d[j]);
					printf("\n");
					for (int j=0; j<n; j++)
						if ((1<<j)&second_set) printf("%d ", d[j]);
					printf("\n");
				}
		}
		if (!found)
			printf("Impossible\n");
	}
	return 0;
}