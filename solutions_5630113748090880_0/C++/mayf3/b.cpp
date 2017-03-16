#include <cstdio>

const int N = 55;
const int M = 2555;
const int INF = 0x3f3f3f3f;

int n;
bool used[N * 2];
int a[N * 2][N];
int graph[N][N];
int cnt[M];

int main(){
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		for(int i = 0; i < M; i++) cnt[i] = 0;
		for(int i = 0; i < 2 * n - 1; i++){
			used[i] = false;
			for(int j = 0; j < n; j++){
				scanf("%d", &a[i][j]);
				cnt[a[i][j]]++;
			}
		}
		bool first = true;
		for(int i = 0; i < M; i++){
			if (cnt[i] != 0 && (cnt[i] % 2 == 1)){
				if (first) first = false;
				else putchar(' ');
				printf("%d", i);
			}
		}
		puts("");
	}
}
