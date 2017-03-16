#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
char str[maxn];
char ans[maxn*2];

int main(){
	int T, kase = 0;
	freopen("Alarge.txt", "r", stdin);
	freopen("Alout.txt", "a", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%s", str);
		printf("Case #%d: ", ++kase);
		int n = strlen(str), l = n-1, r = n-1;
		ans[l] = str[0];
		for(int i = 1; i < n; i++){
			if(str[i] >= ans[l]){
				ans[--l] = str[i];
			}
			else{
				ans[++r] = str[i];
			}
		}
		for(int i = l; i <= r; i++){
			printf("%c", ans[i]);
		}
		printf("\n");
	}
}
