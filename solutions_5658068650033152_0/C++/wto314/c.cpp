#include<cstdio>

int main(){
//	freopen("c.in","r", stdin);
//	freopen("c.out", "w", stdout);
	int T;
	int N, M, K;
	scanf("%d", &T);
	int tab[20];
	int arr1[20] = {0, 1, 2, 3, 5, 6, 8,10, 12, 13, 14, 15, 16};
	int arr2[20] = {0, 1, 2, 3, 5, 6, 8,10, 12, 14, 16, 17, 18, 19, 20};
	for(int i = 1;i <= T;i++){
		int ans;
		scanf("%d %d %d", &N, &M, &K);
		if(M < N){int temp = N; N = M; M = temp;}
		if(N <= 2) ans = K;
		if(N == 3){
			for(int j = 1; j <= 3; j++){
				tab[j] = j;
			}
			for(int j = 4; j <= 2*M-2; j++){
				tab[j] = tab[j-1]+1;
				if(j % 2 == 0)tab[j]++;
			}
			for(int j = 2*M - 1; j <= 2*(M+N-2);j++){
				tab[j] = tab[j-1]+1;
			}
			for(int j = 1; j <= 2*(M+N-2);j++){
				if(K <= tab[j]){
					ans = j;
					break;
				}
			}
		}
		if(N == 4){
			if(M == 4){
				for(int j = 1;j <= 2*(M+N-2);j++){
					if(K <= arr1[j]){
						ans = j;
						break;
					}
				}
			}
			if(M == 5){
				for(int j = 1;j <= 2*(M+N-2);j++){
					if(K <= arr2[j]){
						ans = j;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
} 
