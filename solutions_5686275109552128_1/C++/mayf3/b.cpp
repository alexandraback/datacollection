#include <cstdio>

const int N = 1001;

int n;
int a[N];

int pre(int x){
	while(a[x] == 0) x--;
	return x;
}

int main(){
	int test;
	scanf("%d", &test);
	for(int cas = 1; cas <= test; cas++){
		scanf("%d", &n);
		for(int i = 0; i < N; i++) a[i] = 0;
		int ans = 0;
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			a[x]++;
			if (x > ans) ans = x;
		}
		for(int i = 2; i < N; i++){
			int tot = i;
			for(int j = i + 1; j < N; j++){
				tot += a[j] * ((j - 1) / i);
			}
			if (tot < ans) ans = tot;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}
