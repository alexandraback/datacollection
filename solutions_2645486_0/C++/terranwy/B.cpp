#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 11000;

int cases, casei, n;
long long E, R;
int idx[maxn];
long long v[maxn];
long long ending[maxn];

inline bool idx_cmp(int i1, int i2) {
	if (v[i1] > v[i2]) return true;
	return false;
}

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%I64d%I64d%d", &E, &R, &n);
		for (int i = 0; i < n; ++i) scanf("%I64d", v + i);
		for (int i = 0; i < n; ++i) idx[i] = i;
		sort(idx, idx + n, idx_cmp);
		
		memset(ending, 0, sizeof ending);
		
		if (R < E) {
			for (int i = 0; i < n; ++i) {
				long long e = E - R;
				int now = idx[i];
				for (int j = now - 1; j >= 0 && e > 0LL && v[j] < v[now]; --j) {
					ending[j] = e;
					e -= R;
				}
			}
		}
		
		/*printf("ending:\n");
		for (int i = 0; i < n; ++i) printf("\t%I64d", ending[i]);
		printf("\n");*/
		
		long long ans = 0LL;
		for (int i = 0; i < n; ++i) {
			if (E > ending[i]) {
				ans += (E - ending[i]) * v[i];
				E = ending[i];
			}
			E += R;
			//printf("%d: %I64d\t", i, ans);
		}
		//printf("\n");
		
		printf("Case #%d: %I64d\n", casei, ans);
	}

	return 0;
}
