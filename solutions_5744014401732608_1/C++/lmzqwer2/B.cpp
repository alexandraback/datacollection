#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int m[100][100];

int main(){
	int times, n;
	LL cnt;
	scanf("%d", &times);
	for (int t=1; t<=times; t++){
		memset(m, 0, sizeof(m));
		scanf("%d %lld", &n, &cnt);
		assert(cnt >= 0);
		printf("Case #%d: ", t);
		LL max = 1ll << (n-2);
		if (cnt > max){
			printf("IMPOSSIBLE\n");
			continue;
		}
		for (int i=1; i<n; i++){
			for (int j=i+1; j<n; j++){
				m[i][j] = 1;
			}
		}
		if (cnt == max){
			for (int i=1; i<n; i++){
				m[i][n] = 1;
			}
		}else{
			while (cnt > 0){
				LL lb = cnt & (-cnt);
				cnt -= lb;
				int index = 0;
				while (lb > 0){
					index++;
					lb >>= 1;
				}
				m[index + 1][n] = 1;
			}
		}
		printf("POSSIBLE\n");
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (m[i][j]){
					putchar('1');
				}else{
					putchar('0');
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
