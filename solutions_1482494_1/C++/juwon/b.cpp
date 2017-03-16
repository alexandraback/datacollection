#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int> > v;

int solve() {
	int clear = 0;
	int chk[1000][2] = {0};
	int stars = 0;
	int turn = 0;

	while (clear != n) {
		int flag = 0, flag2 = 0, flag3 = 0;
		int k, k2, k3;
		for (int i = 0; i < n; ++i) {
			if (!chk[i][0] && !chk[i][1] && v[i].second <= stars) {
				flag = 1;
				k = i;
				break;
			}
			if (chk[i][0] && !chk[i][1] && v[i].second <= stars) {
				flag2 = 1;
				k2 = i;
			}
			if (!flag3 && !chk[i][0] && !chk[i][1] && v[i].first <= stars) {
				flag3 = 1;
				k3 = i;
			}
		}
		if (flag) {
			stars += 2;
			chk[k][1] = 1;
			clear++;
		}
		else if (flag2) {
			stars += 1;
			chk[k2][1] = 1;
			clear++;
		}
		else if (flag3) {
			stars += 1;
			chk[k3][0] = 1;
		}
		else {
			return -1;
		}
		turn++;
	}
	return turn;
}

int main() {
	int r, cs = 0;
	scanf("%d", &r);
	while (r--) {
		v.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
		}
		sort(v.rbegin(), v.rend());
		printf("Case #%d: ", ++cs);

//		for (int i = 0; i < n; ++i) printf("%d %d\n", v[i].first, v[i].second);
		int sol = solve();
		if (sol == -1) printf("Too Bad\n");
		else printf("%d\n", sol);
	}
	return 0;
}
