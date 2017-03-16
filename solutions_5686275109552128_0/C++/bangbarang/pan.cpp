
#include <bits/stdc++.h>
using namespace std;
int N, num;
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in", "r", stdin);
		freopen("b.out","w", stdout);
	#endif
	int nCase;
	scanf("%d", &nCase);
	for (int cs = 1; cs <= nCase; cs++) {
		scanf("%d", &N);
		vector<int> dinner, dinner2;
		int res = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			res = max(res, num);
			dinner.push_back(num);
			dinner2.push_back(num);
		}

		int tm = 0;
		while (true) {
			if (dinner.size() == 0) break;
			sort(dinner.begin(), dinner.end(), cmp);
			int cur = dinner[0];
			int tt = tm + cur;
			res = min(res, tt);
			if (cur <= 3)
				break;
			if (cur == 6) {
				dinner[0] = 3;
				dinner.push_back(3);
			} else if (cur == 9) {
				dinner[0] = 3;
				dinner.push_back(6);
			} else if (cur % 2 == 0) {
				dinner[0] = cur / 2;
				dinner.push_back(cur / 2);
			} else {
				dinner[0] = cur / 2 + 1;
				dinner.push_back(cur / 2);
			}
			tm++;
		}

		tm = 0;
		while (true) {
			if (dinner2.size() == 0) break;
			sort(dinner2.begin(), dinner2.end(), cmp);
			int cur = dinner2[0];
			int tt = tm + cur;
			res = min(res, tt);
			if (cur <= 3)
				break;
			if (cur % 2 == 0) {
				dinner2[0] = cur / 2;
				dinner2.push_back(cur / 2);
			} else {
				dinner2[0] = cur / 2 + 1;
				dinner2.push_back(cur / 2);
			}
			tm++;
		}

		printf("Case #%d: %d\n", cs, res);
	}
}

