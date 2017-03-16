#include <bits/stdc++.h>
using namespace std;

int T, n;
bool ok[10];

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d: ", t);
		scanf("%d", &n);
		if(n == 0) { printf("INSOMNIA\n"); continue; }
		memset(ok, 0, sizeof(ok)); int cnt = 0, num = 0, j;
		for(j = 1; ; j++){
			num = j * n;
			while(num){
				cnt += !ok[num % 10];
				ok[num % 10] = 1;
				num /= 10;
			}
			if(cnt == 10) break;
		}
		printf("%d\n", j * n);
	}
	return 0;
}
