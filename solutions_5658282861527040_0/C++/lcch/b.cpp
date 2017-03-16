#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

const int maxn = 1000 + 10;
int bj[maxn];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
	int TextN, TT, A, B, K, ans;
	scanf("%d", &TextN);
	for (int TT = 1; TT <= TextN; TT++) {
		scanf("%d%d%d", &A, &B, &K);
		memset(bj, 0, sizeof(bj));
		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++)
				bj[a & b]++;
		ans = 0;
		for (int i = 0; i < K; i++) ans += bj[i];
		printf("Case #%d: %d\n", TT, ans);
	}
}