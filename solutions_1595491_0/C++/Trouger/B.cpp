#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ttt++){
		int N, S, p;
		scanf("%d%d%d", &N, &S, &p);
		int t, OK = 0, WARNING = 0;
		for (int i = 0; i < N; i++){
			scanf("%d", &t);
			if (t >= 3 * p - 2)
				OK++;
			else if (t > 3 * p - 5)
				if (p != 1)
					WARNING++;
		}
		printf("Case #%d: %d\n", ttt, OK + (WARNING > S ? S : WARNING));
	}
	return 0;
}