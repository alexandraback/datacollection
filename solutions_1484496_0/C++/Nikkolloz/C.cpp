#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int ts, n;
int a[555];
map <int, vector <int> > w;

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &ts);
	for (int t = 1; t <= ts; t++) {
		w.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Case #%d:\n", t);
		bool g = 1;
		for (int m = 1; m < (1<<n); m++) {
			int s = 0;
			for (int i = 0; i < n; i++) {
				if (m & (1<<i))
					s += a[i];
			}
			w[s].push_back(m);
			if (w[s].size() > 1) {
				bool q = 0;
				for (int k = 0; k < n; k++) {
					if (w[s][0] & (1<<k)) {
						if (q)
							printf(" ");
						printf("%d", a[k]);
						q = 1;
					}
				}
				puts("");
				q = 0;
				for (int k = 0; k < n; k++) {
					if (w[s][1] & (1<<k)) {
						if (q)
							printf(" ");
						printf("%d", a[k]);
						q = 1;
					}
				}
				g = 0;
				break;
			}
		}
		if (g)
			printf("Impossible");
		puts("");
	}
	return 0;
}