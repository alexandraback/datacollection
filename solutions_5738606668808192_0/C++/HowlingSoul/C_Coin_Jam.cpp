#include <stdio.h>
#include <string.h>
#include <math.h>
int s[35], div[15];
void pls(int x, int pl){
	s[x] += pl;
	if (s[x] == 2){
		s[x] = 0;
		pls(x - 1, 1);
	}
}
bool chkprime(long long int p, int k){
	long long int sqrp;
	int i;
	sqrp = (long long int)sqrt((double)p);
	for (i = 2; i <= sqrp; i++){
		if (p%i == 0){
			div[k] = i;
			return false;
		}
	}
	return true;
}
int main(){
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C_small.out", "w", stdout);
	int tc, N, J, k, i;
	long long int pr;
	scanf("%d%d%d", &tc,&N,&J);
	s[1] = 1;
	s[N] = 1;
	printf("Case #1:\n");
	while (J > 0){
		memset(div, 0, sizeof(div));
		int sig = 0;
		for (k = 2; k <= 10; k++){
			pr = 0;
			for (i = 1; i <= N; i++) pr = pr*k + s[i];
			if (chkprime(pr, k)){
				sig = 1;
				break;
			}
		}
		if (sig == 0){
			for (i = 1; i <= N; i++) printf("%d", s[i]);
			for (i = 2; i <= 10; i++) printf(" %d", div[i]);
			printf("\n");
			J--;
		}
		pls(N - 1, 1);
	}
	return 0;
}