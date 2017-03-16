#include <cstdio>

int tbl[10000005];

inline long long sqr(long long x) { return x * x; }

int isPal(long long x) {
	int l = 0;
	char tmp[101];
	while(x) {
		tmp[l++] = x % 10;
		x /= 10;
	}
	for(int i = l / 2; i >= 0; --i)
		if(tmp[i] != tmp[l - i - 1]) return 0;
	return 1;
}

void buildTable() {
	for(int i = 1; i <= 10000001; ++i) {
		long long tmp = i;
		tbl[i] = isPal(tmp * tmp) * isPal(tmp) + tbl[i - 1];
	}
}

int main() {
	buildTable();
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		long long bg = 1, ed = 10000001, mid;
		while(true) {
			mid = (bg + ed) / 2;
			if(sqr(mid) >= a) {
				if(sqr(mid - 1) < a) break;
				else ed = mid - 1;
			} else bg = mid + 1;
		}
		//puts("XD");
		a = mid - 1;
		bg = 1, ed = 10000000;
		while(true) {
			mid = (bg + ed) / 2;
			//printf("%lld %lld %lld\n", bg, ed, mid);
			if(sqr(mid) <= b) {
				if(sqr(mid + 1) > b) break;
				else bg = mid + 1;
			} else ed = mid - 1;
		}
		b = mid;
		//printf("%lld %lld\n", a, b);
		printf("Case #%d: %d\n", t, tbl[b] - tbl[a]);
	}
}
