#include <cstdio>
#include <set>

using namespace std;

const int MAX_N = 1005;

int one_star[MAX_N];
int two_stars[MAX_N];

struct cmp1 {
	bool operator () (const int &a, const int &b) {
		if (one_star[a] != one_star[b])
			return one_star[a] < one_star[b];
		if (two_stars[a] != two_stars[b])
			return two_stars[a] > two_stars[b];
		return a < b;
	}
};

struct cmp2 {
	bool operator () (const int &a, const int &b) {
		if (two_stars[a] != two_stars[b])
			return two_stars[a] < two_stars[b];
		return a < b;
	}
};

set < int, cmp1 > one;
set < int, cmp2 > two, two_bad;

int main() {
	int tests; scanf("%d", &tests);
	for (int t = 1; t <= tests; t++) {
		one.clear();
		two.clear();
		two_bad.clear();

		printf("Case %d\n", t);

		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &one_star[i], &two_stars[i]);
			printf("vals %d %d\n", one_star[i], two_stars[i]);
			one.insert(i);
			two.insert(i);
		}

		int curr = 0;
		int ans = 0;
		while (!two.empty() || !two_bad.empty()) {
			ans++;

			if (!two.empty()) {
				int two_elem = *two.begin();
				if (curr >= two_stars[two_elem]) {
					curr += 2;

					one.erase(two_elem);
					two.erase(two_elem);

					continue;
				}
			}

			if (!two_bad.empty()) {
				int two_bad_elem = *two_bad.begin();
				if (curr >= two_stars[two_bad_elem]) {
					curr += 1;

					two_bad.erase(two_bad_elem);

					continue;
				}
			}

			if (!one.empty()) {
				int one_elem = *one.begin();
				if (curr >= one_star[one_elem]) {
					curr += 1;

					one.erase(one_elem);
					two.erase(one_elem);

					two_bad.insert(one_elem);

					continue;
				}
			}

			break;
		}

		if (two.empty() && two_bad.empty())
			printf("Case #%d: %d\n", t, ans);
		else
			printf("Case #%d: Too Bad\n", t);
	}

	return 0;
}
