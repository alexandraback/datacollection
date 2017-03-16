#include <stdio.h>
#include <string.h>
#include <math.h>
int s[35], div[15], N, J;
int mod(int x, int e, int p){
	int t;
	if (e == 1) return x%p;
	if (e == 0) return 1;
	t = x%p;
	if (e % 2 == 0){
		return mod(t*t, e/2,p);
	}
	else{
		return (t*mod(t*t, e / 2, p))%p;
	}
}
void pls(int x, int pl){
	s[x] += pl;
	if (s[x] == 2){
		s[x] = 0;
		pls(x - 1, 1);
	}
}
bool chkprime(int k){
	int i, j;
	long long int pr = 0;
	for (i = 2; i <= 1000; i++){
		pr = 0;
		for (j = 1; j <= N; j++){
			if (s[j] == 1) pr += mod(k, N-j, i);
		}
		if (pr%i == 0){
			div[k] = i;
			return false;
		}
	}
	return true;
}
int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C_large.out", "w", stdout);
	int tc, k, i;
	scanf("%d%d%d", &tc,&N,&J);
	s[1] = 1;
	s[N] = 1;
	printf("Case #1:\n");
	while (J > 0){
		memset(div, 0, sizeof(div));
		int sig = 0;
		for (k = 2; k <= 10; k++){
			if (chkprime(k)){
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