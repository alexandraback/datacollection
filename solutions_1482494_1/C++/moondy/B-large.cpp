#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000;

bool done[100000], done1[100000];

int solve() {
	set<pair<int, int> > two;
	//set<pair<pair<int, int>, int> > one;
	vector<pair<int, pair<int, int> > > one;
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		one.push_back(make_pair(b, make_pair(a, i)));
		//one.insert(make_pair(make_pair(a, -b), i));
		two.insert(make_pair(b, i));
	}
	sort(one.begin(), one.end());
	memset(done, false, sizeof(done));
	memset(done1, false, sizeof(done1));
	int tot = 0, round = 0;
	while (!two.empty()) {
		while (!two.empty() && tot >= two.begin()->first) {
			if (!done1[two.begin()->second]) tot += 2;
			else tot++;
			round++;
//printf("%d 2 %d\n", two.begin()->second, tot);
			done[two.begin()->second] = true;
			two.erase(two.begin());
		}
		if (two.empty()) return round;

		bool yes = false;
		for (int i = n - 1; i >= 0; i--) {
			if (done[one[i].second.second]) continue;
			if (done1[one[i].second.second]) continue;
			if (tot < one[i].second.first) continue;
			tot++; round++; yes = true;
			done1[one[i].second.second] = true;
			break;
		}
		if (!yes) return -1;
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		int res = solve();
		if (res < 0) puts("Too Bad");
		else printf("%d\n", res);
	}
	return 0;
}
