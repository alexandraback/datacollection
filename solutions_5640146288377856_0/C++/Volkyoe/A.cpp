#include"stdio.h"
#include"stdlib.h"
#include"algorithm"
using namespace std;
int t, T, R, C, W, Ans;
int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.txt", "w", stdout);
	scanf("%d", &T);
	while (t < T) {
		scanf("%d%d%d", &R, &C, &W);
		Ans = (C/W) * R + W - 1;
		if (C % W != 0) Ans++;
		printf("Case #%d: %d\n", ++t, Ans);
	}
}
