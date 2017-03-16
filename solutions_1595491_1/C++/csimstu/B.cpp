#include <cstdio>

int eval(int x) {
	if ( x % 3 == 0 )
		return x / 3;
	else 
		return x / 3 + 1;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int TST;
	scanf("%d", &TST);

	for ( int tst = 1; tst <= TST; tst ++ ) {
		printf("Case #%d: ", tst);
		int N, S, P;
		scanf("%d%d%d", &N, &S, &P);

		int ans = 0;
		for ( int i = 0; i < N; i ++ ) {
			int t;
			scanf("%d", &t);
			if ( eval(t) >= P )
				ans ++;
			else if ( 2 <= t && t <= 28 && S && t % 3 != 1 && eval(t) + 1 >= P )
				S --, ans ++;
		}
		printf("%d\n", ans);
	}
}
