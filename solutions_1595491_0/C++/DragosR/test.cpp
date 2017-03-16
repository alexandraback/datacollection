#include <cstdio>
#include <cstring>

const int maxn = 110;

using namespace std;

int T, N, S, P, v[maxn];

inline int max(int a, int b) {
	if(a > b) return a;
	return b;
}
inline int abs(int a) {
	if(a < 0) return -a;
	return a;
}
int main() {

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	scanf("%d\n", &T);

	for(int test = 1; test <= T; ++test) {

		scanf("%d %d %d", &N, &S, &P);
		
		int sol = 0;
		for(int i = 1; i <= N; ++i) {
			scanf("%d", &v[i]);
		}
		int l1, l2, l3;
		for(int i = 1; i <= N; ++i) {

			int havesol = 0, backup = 0;
			
			for(int l1 = P - 2; l1 <= 10; ++l1)
				for(int i2 = -2; i2 <= 2; i2++) {
					for(int i3 = -2; i3 <= 2; i3++) {
					
						l2 = l1 + i2; 
						l3 = l1 + i3;
					
						if(l1 < 0 || l2 < 0 || l3 < 0 || l2 > 10 || l3 > 10) continue;
						
						//printf("%d %d %d", l1, l2, l3);

						int k = max( abs(l3 - l1), max(abs(l2 - l1),  abs(l3 - l2)) ) ; 
						int q = max(l1, max(l2, l3)); 
						if(q < P || k > 2) continue;
						
						if(k <= 1 && l1 + l2 + l3 == v[i]) {
							++havesol;// printf("%d %d %d\n", l1, l2, l3);
							i2 = 3; i3 = 3; l1 = 11;
						} else if(k == 2 && l1 + l2 + l3 == v[i]) {
							backup = 1; 
						}
			//			printf("\n");
					}
				}
			//printf("\n");
			if(havesol) sol += 1; else {
				if(backup && S) sol += 1, S -= 1;
			}
		}
		printf("Case #%d: %d\n", test, sol);
	}
	return 0;
}
