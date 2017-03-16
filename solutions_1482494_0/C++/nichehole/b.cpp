#include<cstdio>
#include<algorithm>
#include <cstring>
using namespace std;

int one[10000];
int two[10000];
int id[10000];
int id2[10000];
bool v[10000];
bool v2[10000];
int n;

bool cmp2(int x, int y) {
	return two[x] < two[y];
}
bool cmp(int x, int y) {
	if (one[x] == one[y]) return two[x] > two[y];
	return one[x] < one[y];
}
int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while (T--) {
		memset(v, 0 ,sizeof(v));
		memset(v2, 0, sizeof(v2));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			id[i] = id2[i] = i;
			scanf("%d%d", &one[i], &two[i]);
			//if (cas == 17) printf("%d %d\n", one[i], two[i]);
		}
		sort(id, id + n, cmp);
		sort(id2, id2 + n, cmp2);
		//for (int i = 0; i < n; ++i) printf("%d %d\n", id2[i], two[id2[i]]);
		//for (int i = 0; i < n; ++i) printf("%d %d\n", id[i], two[id[i]]);
		//puts("");
		int s = 0, t = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n && s < two[id2[i]]; ++j) {
				if (!v2[id[j]] && !v[id[j]] && s >= one[id[j]]) {
					v[id[j]] = 1;
					++s;
					++t;
					//printf("stars1: %d\n", s);
				}
			}
			if (s >= two[id2[i]]) {
				if (!v[id2[i]]) ++s;
				++s;
				v2[id2[i]] = 1;
				++t;
				//printf("stars2: %d\n", s);
			} else {
				break;
			}
		}
		printf("Case #%d: ", ++cas);
		if (s < 2*n) puts("Too Bad");
		else printf("%d\n", t);
		//puts("");
	}
	return 0;
}
