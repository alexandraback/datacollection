#include <cstdio>
int T, D, P[1000], total, high, cut;
int main (){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		high = 0;
		scanf("%d", &D);
		for (int j = 0; j < D; j++){
			scanf("%d", &P[j]);
			if (high < P[j])
				high = P[j];
		}
		total = high;
		cut = 0;
		while (high >= 1 && cut <= total){
			cut = 0;
			for (int j = 0; j < D; j++)
				cut += (P[j] - 1) / high;
			if (high + cut < total)
				total = high + cut;
			high--;
		}
		printf("Case #%d: %d\n", i, total);
	}
	return 0;
}
