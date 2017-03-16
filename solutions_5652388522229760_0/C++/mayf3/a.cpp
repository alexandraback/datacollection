#include <cstdio>

bool vis[10];

int main(){
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		int x;
		scanf("%d", &x);
		if (x == 0) puts("INSOMNIA");
		else{
			for(int i = 0; i < 10; i++) vis[i] = false;
			int i = 1, cnt = 0, num;
			while(true){
				num = x * i;
				while(num){
					if (!vis[num % 10]) vis[num % 10] = true, cnt++;
					num /= 10;
				}
				if (cnt == 10) break;
				i++;
			}
			printf("%d\n", i * x);
		}
	}
}
