#include <cstdio>
#include <iostream>
using namespace std;
int n, m, arr[110][110], hi = 0;
void judge(){
	for(int i = 1; i <= hi; ++i){
		for(int j = 0; j < n; ++j){
			int cnt = 0;
			for(int k = 0; k < m; ++k){
				if(arr[j][k] == i || arr[j][k]==0) cnt++;
			}
			if(cnt == m)for(int k = 0; k < m; ++k){
				arr[j][k] = 0;
			}
		}

		for(int k = 0; k < m; ++k){
			int cnt = 0;
			for(int j = 0; j < n; ++j){
				if(arr[j][k] == i || arr[j][k]==0) cnt++;
			}
			if(cnt==n)for(int j = 0; j < n; ++j) arr[j][k]=0;
		}
	}

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(arr[i][j]){puts("NO"); return;}
	puts("YES");
}

int main(){
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j){
				scanf("%d", &arr[i][j]);
				hi = max(hi, arr[i][j]);
			}
		printf("Case #%d: ", kase);
		judge();
	}
	return 0;
}
