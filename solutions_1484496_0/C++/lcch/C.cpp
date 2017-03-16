#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

const int maxn = 30;
int a[maxn], n, S[maxn];
int A[maxn], B[maxn];
int gA, gB;

int ABS(int x) { return x>0?x:-x; }

bool dfs(int h, int SA, int SB)
{
	if (SA > 0 && SA == SB) {
		for (int i = 1; i <= gA; i++) printf("%d ", A[i]);
		printf("\n");
		for (int i = 1; i <= gB; i++) printf("%d ", B[i]);
		printf("\n");
		return true;
	}
	if (h > n) return false;
	if (ABS(SA-SB) > S[h]) return false;
	if (dfs(h+1, SA, SB)) return true;
	A[++gA] = a[h];
	if (dfs(h+1, SA+a[h], SB)) return true;
	--gA;
	B[++gB] = a[h];
	if (dfs(h+1, SA, SB + a[h])) return true;
	--gB;
	return false;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int TextN, TT = 0;
	scanf("%d", &TextN);
	while (TextN--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		S[n+1] = 0;
		for (int i = n; i >= 1; i--) {
			S[i] = S[i+1] + a[i];
		}
		gA = gB = 0;
		printf("Case #%d:\n", ++TT);
		if (!dfs(1, 0, 0)) {
			printf("Impossible\n");
		}
	}
	return 0;
}