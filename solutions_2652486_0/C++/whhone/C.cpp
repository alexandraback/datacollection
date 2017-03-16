#include <cstdio>
int T, p[10], R, N, M, K;


bool check(int a, int b, int c, int d) {
	return (
	(1 == d) ||
	(a == d) ||
	(b == d) ||
	(c == d) ||
	(a*b == d) ||
	(a*c == d) ||
	(b*c == d) ||
	(a*b*c == d));
}

int main() {
	scanf("%d", &T);
	scanf("%d%d%d%d", &R, &N, &M, &K);
	printf("Case #1:\n");
	while (R--) {
		for (int i=0;i<K;++i) {
			scanf("%d", &p[i]);
		}
		bool done = false;
		for (int a = 2; a<=5;++a) {
			for (int b = 2; b<= 5; ++b) {
				for (int c = 2; c<= 5;++c) {
					//printf("%d%d%d - \n", a, b, c);
					if (done) continue;
					bool ok = true;
					for (int i=0;i<K;++i) {
						if (!check(a, b, c, p[i])) {
							ok = false;
						}
					}
					if (ok) {
						printf("%d%d%d\n", a, b, c);
						done = true;
					}
				}
			}
		}
	}
	return 0;
}