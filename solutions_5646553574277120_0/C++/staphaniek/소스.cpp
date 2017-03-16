#include<stdio.h>
int T, C, D, V, coin[3000], Dy[3000], sum[3000],i, j;
int main(){
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		scanf("%d %d %d", &C, &D, &V);
		for (i = 1; i <= D; i++)scanf("%d", &coin[i]);
		Dy[0] = 0;
		if (coin[1] != 1){
			for (i = D; i >= 1; i--)coin[i + 1] = coin[i];
			coin[1] = 1;
			Dy[0] = 1;
			D++;
		}
		coin[++D] = V;
		for (i = 1; i < D; i++){
			sum[i] = sum[i - 1] + coin[i];
			Dy[i] = Dy[i - 1];
			if (i == D - 1){
				if (sum[i] * C < coin[i + 1]){
					Dy[i]++;
					for (j = D; j>i; j--)coin[j + 1] = coin[j];
					coin[i + 1] = sum[i] * C + 1;
					D++;
				}
			}
			else if (sum[i] * C < coin[i + 1] - 1){
				Dy[i]++;
				for (j = D; j>i; j--)coin[j + 1] = coin[j];
				coin[i + 1] = sum[i] * C + 1;
				D++;
			}
		}
		printf("Case #%d: %d\n", t, Dy[D - 1]);
	}
	return 0;
}