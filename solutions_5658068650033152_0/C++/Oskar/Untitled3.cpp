#include <cstdio>

int c, n, m, k;

inline int min(int x, int y){
	return x > y ? y : x;
}

int main(){
	freopen("dd.txt", "w", stdout);
	scanf("%d", &c);
	for(int i = 1; i <= c; i++){
		int ans = 2e9;
		scanf("%d %d %d", &n, &m, &k);
		if(n <= 2 || m <= 2 ){
			printf("Case #%d: %d\n", i, k);
			continue;
		}
		if(k <= 2 * m) ans = k;
		if(k <= 2 * n) ans = k;
		
		
		for(int i = (k - 1) / m + 1; i <= min(n, k); i++){
			//if(i <= 1) continue;
			int x = (k - 1) / i + 1;
			int y = x * 2 + i * 2 - 4;
			if(i == 1 || x == 1) y += 2;
			y -= min(4, x * i - k);
			if(y < ans) ans = y;
			//printf("%d ", y);
			if(x >= m || i <= 2) continue;
			x++;
			y = 2 * x + 2 * i - 4;
			y -= min(4, x * i - k);
			if(y < ans) ans = y;
			//printf("%d\n", y);
		}
		printf("Case #%d: %d\n", i, ans);
	}
	scanf("\n");
}
