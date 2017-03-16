#include <cstdio>
int T, S_max, cnt, low;
char c;
int main (){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d ", &S_max);
		low = 0;
		cnt = 0;
		for (int j = 0; j <= S_max; j++){
			scanf("%c", &c);
			if (low < j - cnt)
				low = j - cnt;
			cnt += c - '0';
		}
		printf("Case #%d: %d\n", i, low);
	}
	return 0;
}
