#include <cstdio>


int solve() {
	int n, s, p;
	scanf("%d %d %d", &n, &s, &p);
	int res = 0;

	while(n--) {
		int t;
		scanf("%d", &t);
		int a = t/3;
		int b = a;

		if(t%3 == 0) {
			if(a > 0) b++;
		} else if(t%3 == 1) {
			a++; b++;
		} else {
			a++; b++;
			if(b < 10) b++;
		}

		if(a >= p) res++;
		else if(b >= p && s > 0) {
			res++;
			s--;
		}
	}

	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) printf("Case #%d: %d\n", i, solve());

}