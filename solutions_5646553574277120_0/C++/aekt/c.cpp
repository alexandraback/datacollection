#include <cstdio>

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int c, d, v;
		scanf("%d%d%d", &c, &d, &v);
		int D[d];
		for (int i = 0; i < d; i++) {
			scanf("%d", &D[i]);
		}
		bool V[v+1];
		for (int i = 0; i <= v; V[i++] = 0);
		V[0] = 1;
		for (int i = 0; i < d; i++) {
			for (int j = v; j >= 0; j--) {
				if (V[j] && j+D[i] <= v) {
					V[j+D[i]] = 1;
				}
			}
		}
		
		int M = 0;
		for (int i = 0; i <= v; i++) {
			if (V[i] == 0) {
				M++;
				for (int j = v; j >= 0; j--) {
					if (V[j] && j+i <= v) {
						V[j+i] = 1;
					}
				}
			}
		}
		printf("Case #%d: %d\n", t, M);
	}
	return 0;
}
