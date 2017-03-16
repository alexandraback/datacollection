#include <cstdio>

int main(){
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		printf("Case #%d:", cas);
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		for(int i = 1; i <= c; i++){
			printf(" %d", i);
		}
		puts("");
	}
}
