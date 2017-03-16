#include<stdio.h>
int T, n, D[1010000], Q[1010000], t, h, TC;
int rev(int a){
	int r = 0;
	while (a){
		r *= 10;
		r += a % 10;
		a /= 10;
	}
	return r;
}
void Do(int a){
	if (a > 1000000)return;
	int tp = rev(a);
	if (!D[tp]){
		D[tp] = D[a] + 1;
		Q[++t] = tp;
	}
	tp = a + 1;
	if (!D[tp]){
		D[tp] = D[a] + 1;
		Q[++t] = tp;
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	D[1] = 1; Q[++t] = 1;
	while (h < t){
		Do(Q[++h]);
	}
	for (T = 1; T <= TC;T++){
		scanf("%d", &n);
		printf("Case #%d: %d\n",T, D[n]);
	}
}