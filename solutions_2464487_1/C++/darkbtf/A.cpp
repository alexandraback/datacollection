#include <cstdio>

inline long long min(long long a, long long b) { return a < b? a: b; }

long long V, R;

inline long long f(long long x) { return R * x * 2 + 2 * x * x - x; }

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%lld%lld", &R, &V);
		long long bg = 1, ed = min(V / R / 2, 1500000000), mid;
		while(true) {
			//printf("%lld %lld\n", bg, ed);
			mid = (bg + ed) / 2;
			if(f(mid) <= V) {
				if(f(mid + 1) > V) break;
				else bg = mid + 1;
			} else ed = mid - 1;
		}
		printf("Case #%d: %lld\n", t, mid);
	}
}

/*
(r+1)^2 - r^2 = 2r + 1
(r+3)^2 - (r+2)^2 = 2r + 5
2r + 9
....

2r * n + n(4 * (n - 1) + 2) / 2

2rn + 2n^2 - n 
*/