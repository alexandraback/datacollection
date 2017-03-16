#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int a[500];

int main(){
	int i, j, k, m, n, S, p, N;
	int T;
	scanf("%d", &T);
	for(int re = 1; re <= T; re++){
		scanf("%d%d%d", &N, &S, &p);
		for(i = 0; i < N; i++){
			scanf("%d", a + i);
		}
		sort(a, a + N, cmp);
		for(int ans = N; ans >= 0; ans--){
			k = S;
			for(i = 0; i < ans; i++){
				if(a[i] == 0 && p) break;
				if(a[i] % 3 == 2){
					if(a[i] / 3 + 2 < p)
						break;
					else if(a[i] / 3 + 1 < p){
						if(k == 0)
							break;
						else
							k--;
					}
				}else if(a[i] % 3 == 1){
					if(a[i] / 3 + 1 < p)
						break;
				}else{
					if(a[i] / 3 + 1 < p)
						break;
					else if(a[i] / 3 < p){
						if(k == 0)
							break;
						else
							k--;
					}
				}
			}
			if(i == ans){
				printf("Case #%d: %d\n", re, ans);
				break;
			}
		}
	}
}
