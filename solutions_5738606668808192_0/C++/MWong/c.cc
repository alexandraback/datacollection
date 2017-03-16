#include<cstdio>
#include<cmath>
#define MAX 100000005
#define LL long long

int p[MAX], count = 50;
int pl[MAX], len = 0;
LL ans[15];

int printb(LL x){
	int max = 0;
	while (x >= (1 << max)) max++;
	max--;

	while (max >= 0){
		printf("%d", (bool)(x & (1 << max)));
		max--;
	}
}

int main(){

	for (int i = 0; i < MAX; i++) p[i] = i;
	for (int i = 2; i < MAX; i++){
		if (p[i] == i){
			pl[len++] = i;
			for (int j = i << 1; j < MAX; j += i) p[j] = i;
		}
	}

	printf("Case #1:\n");
	for (int i = (1 << 15) + 1; i < (1 << 16) && count; i += 2){
		bool corr = true;
		for (int j = 2; j <= 10 && corr; j++){
			LL tmp = 0, b = 1, ti = i;
			while (ti){
				tmp += (ti & 1) * b;
				ti >>= 1; b *= j;
			}

			if (tmp < MAX){
				if (p[tmp] == tmp) corr = false;
				else ans[j] = p[tmp];
			}else {
				LL bound = (int) sqrt(tmp) + 1;
				ans[j] = 2;

				for (int k = 0; k < len && pl[k] <= bound; k++){
					if (tmp % pl[k] == 0){
						ans[j] = pl[k];
						break;
					}
				}
				if (tmp % ans[j] != 0) corr = false;
			}
		}

		if (corr){
			count--;
			printb(i);
			for (int j = 2; j <= 10; j++){
				printf(" %lld", ans[j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
