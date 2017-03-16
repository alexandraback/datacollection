#include<cstdio>

int ct[3000], t, n;

int main(){
	scanf("%d", &t);
	for (int c = 1; c <= t; c++){
		scanf("%d", &n);
		for (int i = 0; i < 3000; i++){
			ct[i] = 0;
		}

		for (int i = 0; i < n * 2 - 1; i++){
			for (int j = 0; j < n; j++){
				int tmp;
				scanf("%d", &tmp);
				ct[tmp]++;
			}
		}

		printf("Case #%d:", c);
		for (int i = 0; i < 2600; i++){
			if (ct[i] & 1) printf(" %d", i);
		}
		printf("\n");
	}

	return 0;
}
