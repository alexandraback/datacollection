#include <cstdio>
#include <algorithm>

using namespace std;

bool done_s(int x, int p) {
	return (x>=2 && (x-2)%3==0 && (x-2)/3+2>=p)
				|| (x>=3 && (x-3)%3==0 && (x-3)/3+2>=p);
}

bool done_ns(int x, int p) {
	return (x>=2 && (x-2)%3==0 && (x-2)/3+1>=p)
				|| (x>=1 && (x-1)%3==0 && (x-1)/3+1>=p)
				|| (x%3==0 && x/3>=p); 
}

int main() {
	int tst, s1, s2, n, s, p, x;
	scanf("%d", &tst);

	for (int t=0; t<tst; t++) {
		scanf("%d%d%d", &n, &s, &p);
		s1 = s2 = 0;

		for (int i=0; i<n; i++) {
			scanf("%d", &x);

			if (done_ns(x, p)) s1++; //{ s1++; printf("%d: 1\n", x); }
			else if (done_s(x, p)) s2++; //{ s2++; printf("%d: 2\n", x); }
			//else printf("%d: 3\n", x);
		}

		printf("Case #%d: %d\n", t+1, s1 + min(s2, s));
	}
	return 0;
}
