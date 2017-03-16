#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
	int times;
	int m[60][60];
	int list[110][60];
	int used[110];
	int height[2600];
	scanf("%d\n", &times);
	for (int t=1; t<=times; t++){
		memset(height, 0, sizeof(height));
		int n = 0;
		scanf("%d", &n);
		for(int i=0; i<2 * n -1; i++){
			for (int j=0; j<n; j++){
				scanf("%d", &list[i][j]);
				height[list[i][j]]++;
			}
		}
		printf("Case #%d:", t);
		for (int j=0; j<2600; j++){
			if (height[j] & 1){
				printf(" %d", j);
			}
		}
		printf("\n");
	}
	return 0;
}
