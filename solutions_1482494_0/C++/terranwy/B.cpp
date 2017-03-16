#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;

struct TLevel {
	int s1, s2;
	bool done;
};

int casei, cases, n, ans, stars;
TLevel lv[maxn];

bool lv_cmp(TLevel l1, TLevel l2) {
	return l1.s2 < l2.s2;
}

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &lv[i].s1, &lv[i].s2);
			lv[i].done = false;
		}
		sort(lv, lv + n, lv_cmp);
		//for (int i = 0; i < n; ++i) printf("(%d %d); ", lv[i].s1, lv[i].s2);
		//printf("\n");
		
		ans = 0; stars = 0;
		for (int i = 0; i < n; ++i) {
			bool changed = true;
			while (changed && stars < lv[i].s2) {
				changed = false;
				for (int j = n - 1; j >= i && stars < lv[i].s2; --j)
					if (!lv[j].done && stars >= lv[j].s1) {
						++ans;
						++stars;
						lv[j].done = true;
						changed = true;
						//printf("\"(%d %d)\": ans:%d stars:%d\n", lv[j].s1, lv[j].s2, ans, stars);
						break;
					}
			}
			
			if (stars < lv[i].s2) {
				ans = -1;
				break;
			}
			++ans;
			if (lv[i].done) ++stars;
			else stars += 2;
			//printf("\"(%d %d)\": ans:%d stars:%d\n", lv[i].s1, lv[i].s2, ans, stars);
		}
		
		if (ans == -1) printf("Case #%d: Too Bad\n", casei);
		else printf("Case #%d: %d\n", casei, ans);
	}
	
}
