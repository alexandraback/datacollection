#include"stdio.h"
#include"stdlib.h"
#include"algorithm"
using namespace std;
int t, T, C, D, V;
void solveSmall() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.txt", "w", stdout);
	int arr[40];
	scanf("%d", &T);
	while (t < T) {
		int ans = 0;
		for (int i = 0; i < 35; i++) arr[i] = 0;
		arr[0] = 1;
		scanf("%d%d%d", &C, &D, &V);
		for (int i = 0; i < D; i++) {
			int X = 0;
			scanf("%d", &X);
			for (int j = V - X; j >= 0; j--)
				if (arr[j] == 1) arr[j + X] = 1;
		}
		for (int i = 0; i <= V; i++) {
			if (arr[i] == 1) continue;
			ans++;
			for (int j = V - i; j >= 0; j--)
				if (arr[j] == 1) arr[j + i] = 1;
		}
		printf("Case #%d: %d\n", ++t, ans);
	}
}
void solveLarge() {
	//freopen(".in", "r", stdin);
	//freopen(".txt", "w", stdout);
}
int main() {
	solveSmall();
	//solveLarge();
}
