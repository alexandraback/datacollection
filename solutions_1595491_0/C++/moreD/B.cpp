#include <cstdio>
#include <cstring>

int T, n, s, p, t, ans;

int main(){
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++){
		scanf("%d%d%d", &n, &s, &p);
		ans = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &t);
			int m = t / 3;
			if (t % 3) m++;
			if (m >= p) ans++;
			else if (s && t >= p * 3 - 4 && t > 1){
				s--; ans++;
			}
		}
		printf("Case #%d: %d\n", ca, ans);
	}
}
