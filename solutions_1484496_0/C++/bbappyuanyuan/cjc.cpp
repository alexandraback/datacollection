#include <cstdio>
#include <algorithm>
using namespace std;

struct data {
	int st, sa;
};

int n;
int a[30];
int t;
data list[(1 << 20) + 10];

bool cmp(const data &a, const data &b) {
	return a.sa < b.sa;
}

void print(int st) {
	bool first = true;
	for (int i = 0; i < n; ++i)
		if (st & (1 << i)) {
			if (!first) printf(" "); else first = false;
			printf("%d", a[i]);
		}
	printf("\n");
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		t = 0;
		for (int i = 1; i < 1 << n; ++i) {
			list[t].st = i;
			list[t].sa = 0;
			for (int j = 0; j < n; ++j)
				if (i & (1 << j))
					list[t].sa += a[j];
			++t;
		}
		
		printf("Case #%d:\n", cs);
		sort(list, list + t, cmp);
		list[t].sa = -1;
		bool found = false;
		for (int l = 0, r = 1; r <= t && !found; ++r)
			if (list[r].sa != list[l].sa) {
				for (int i = l; i < r && !found; ++i)
					for (int j = i + 1; j < r && !found; ++j)
						if ((list[i].st & list[j].st) == 0) {
							print(list[i].st);
							print(list[j].st);
							found = true;
						}
				l = r;
			}
		if (!found) puts("Impossible");
	}
	
	return 0;
}
