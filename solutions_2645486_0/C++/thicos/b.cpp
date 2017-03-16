#include <cstdio>
#include <cstring>
int tab[100][100];
bool used[100][100];
int maxe;
int R;
int V[100];
int taskn;

int mymin(int a, int b){
	return a<b?a:b;
}

int solve(int t, int e){
	if (t == taskn) return 0;
	if (used[t][e]) return tab[t][e];
	used[t][e] = true;
	int max = 0;
	for (int i = 0; i <= e; i++){
		int tmp = V[t]*i + solve(t+1, mymin(maxe, e-i+R));
		if (tmp > max) max = tmp;
	}
	//printf("%d %d %d\n", t, e, max);
	tab[t][e] = max;
	return max;
}


int main(){
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		scanf("%d %d %d", &maxe, &R, &taskn);
		for (int i = 0; i < taskn; i++) scanf("%d", &V[i]);
		memset(used, 0, sizeof(used));
		printf("Case #%d: %d\n", t+1, solve(0, maxe));
	}
	return 0;
}