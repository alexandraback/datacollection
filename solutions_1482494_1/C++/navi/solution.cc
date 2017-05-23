#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int T, n;
int a[1000][2];
int comp[1000];

struct Cmp {
	bool operator ()(const int lhs, const int rhs) {
		return a[lhs][1] < a[rhs][1];
	}
};

inline int gao() {
	multiset<int, Cmp> sec;
	for (int i = 0; i < n; ++i) {
		sec.insert(i);
	}
	int ret = 0, stars = 0;
	memset(comp, -1, sizeof(comp));
	for (int i = 0; i < 4 * n; ++i) {
		while (!sec.empty() && a[*sec.begin()][1] <= stars) {
			++ret;
			stars += 1 - comp[*sec.begin()];
			comp[*sec.begin()] = 1;
			sec.erase(sec.begin());
		}
		int idx = -1;
		for (int j = 0; j < n; ++j) {
			if (comp[j] == -1 && a[j][0] <= stars) {
				if (idx == -1 || a[j][1] > a[idx][1]) {
					idx = j;
				}
			}
		}
		if (idx == -1) {
			break;
		}
		++ret;
		stars += 0 - comp[idx];
		comp[idx] = 0;
	}
	return stars == 2 * n ? ret : -1;
}

int main() {
	scanf("%d", &T);
	for (int caseNum = 1; caseNum <= T; ++caseNum) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i][0], &a[i][1]);
		}
		int res = gao();
		if (res == -1) {
			printf("Case #%d: Too Bad\n", caseNum);
		} else {
			printf("Case #%d: %d\n", caseNum, res);
		}
	}
	return 0;
}
