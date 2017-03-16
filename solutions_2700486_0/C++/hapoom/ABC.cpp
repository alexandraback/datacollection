#include<stdio.h>
#include<algorithm>
#include<memory.h>
FILE *in = fopen("B-small-attempt0.in", "r");
FILE *out= fopen("output.txt", "w");

int main()
{
	int T, cn, X, Y, N, s;
	int i, j, k;
	double ans, tmp;	
	fscanf(in, "%d", &T);
	for(cn = 1; cn <= T; cn++){
		fscanf(in, "%d%d%d", &N, &X, &Y);
		for(i = 0;; i++){
			if(2 * i * i - i >= N)break;
		}
		if(X >= 0){
			if((2 * i * i - i == N && X + Y <= (i - 1) * 2) || X + Y <= (i - 2) * 2){
				ans = 1.0;
				fprintf(out, "Case #%d: %f\n", cn, ans);
				continue;
			}
			if(X == 0){
				if(2 * i * i - i != N && X == 0){
				ans = 0.0;
				fprintf(out, "Case #%d: %f\n", cn, ans);
				continue;

				}
			}
		}
		else{
			if((2 * i * i - i == N && Y - X <= (i - 1) * 2) || Y - X <= (i - 2) * 2){
				ans = 1.0;
				fprintf(out, "Case #%d: %f\n", cn, ans);
				continue;
			}
		}
		ans = 0.0;
		i--;
		s = N - (2 * i * i - i);
		for(j = 0; j <= 2 * i; j++){
			if(X == i * 2 - j && Y == j){
				break;
			}
			if(X == (-1)*(i * 2 - j) && Y == j){
				break;
			}
		}
		if(j == 2 * i + 1) ans = 0.0;
		else if(j == 2 * i - 1){
			tmp = 1.0;
			for(k = 1; k <= 2*i; k++)
				tmp /= 2;
			for(k = 1; k <= j; k++)
				tmp *= ((s - k + 1)/(double)k);
			ans += tmp;
		}
		else{
			for(; j < s; j++){
				tmp = 1.0;
				for(k = 1; k <= s; k++)
					tmp /= 2;
				for(k = 1; k <= j + 1; k++)
					tmp *= ((s - k + 1)/(double)k);
				ans += tmp;
			}
		}
		
		fprintf(out, "Case #%d: %f\n", cn, ans);
	}
}