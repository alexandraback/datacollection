#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int a[30], b[2000001];


int main(){
	int i, j, k, m, n;
	int T;
	freopen("x.txt", "r", stdin);
	freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for(int re = 1; re <= T; re++){
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d", a + i);
		int sum = 0;
		for(k = 1; k < (1 << n); k++){
			sum = 0;
			for(i = 0; i <= n;  i++){
				if((1 << i) & k){
					sum += a[i];
				}
			}
			if(b[sum]) break;
			b[sum] = k;
		}
		vector<int>ans1, ans2;
		printf("Case #%d:\n", re);
		if(k < (1<<n)){
			for(i = 0; i <= n;  i++){
				if((1 << i) & k){
					ans1.push_back(a[i]);
				}
			}
			for(i = 0; i <= n;  i++){
				if((1 << i) & b[sum]){
					ans2.push_back(a[i]);
				}
			}
			for(i = 0; i < ans1.size(); i++){
				printf("%d%c", ans1[i], i + 1 < ans1.size() ? ' ' : '\n');
			}
			for(i = 0; i < ans2.size(); i++){
				printf("%d%c", ans2[i], i + 1 < ans2.size() ? ' ' : '\n');
			}
		}
		else
			puts("Impossible");
	}
}
