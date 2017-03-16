#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxB 55

int main() {
	int test;
	scanf("%d", &test);
	for(int t=0; t<test; t++) {
		int b, m;
		scanf("%d %d", &b, &m);
		int sum[maxB];
		int slides[maxB][maxB];
		for(int i=0; i<=b; i++) {
			sum[i] = 0;
			for(int j=0; j<=b; j++)
				slides[i][j] = 0;
		}
		int temp = 1;
		sum[b] = 1;
		for(int i=b-1; i>=2; i--) {
			for(int j=i+1; j<=b; j++) {
				if((temp+sum[j]) <= m) {
					sum[i] += sum[j];
					temp += sum[j];
					slides[i][j] = 1;
				}
			}
		}
		int num = 0;
		for(int i=2; i<=b; i++) {
			if(sum[i]>0 && (num + sum[i]) <= m) {
				num += sum[i];
				slides[1][i] = 1;
			}
		}
		if(num!=m) 
			printf("Case #%d: IMPOSSIBLE\n", t+1);
		else {
			printf("Case #%d: POSSIBLE\n", t+1);
			for(int i=1; i<=b; i++) {
				for(int j=1; j<=b; j++) {
					printf("%d", slides[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
