#include <stdio.h>


int main() {
	int T;
	scanf("%d", &T);
	for(int nc=1; nc<=T; nc++) {
		int N, S, p;
		scanf("%d %d %d", &N, &S, &p);
		int cnt = 0;
		while(N--) {
			int t;
			scanf("%d", &t);
			int n = t/3;
			if(t%3!=0) n++;
			if(n>=p) cnt++;
			else if(S and t%3!=1 and t!=0) {
				if(n+1>=p) {
					cnt++;
					S--;
				}
			}
		}
		printf("Case #%d: %d\n", nc, cnt);
	}
}
