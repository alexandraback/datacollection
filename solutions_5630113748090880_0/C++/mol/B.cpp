#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int tt=0; tt<T; tt++){
		int N;
		scanf("%d",&N);
		int c[2*N-1][N];
		for(int i=0; i<2*N-1; i++)
			for(int j=0; j<N; j++)
				scanf("%d",&c[i][j]);
		int cnt[2600];
		for(int k=0; k<2600; k++)
			cnt[k] = 0;
		for(int i=0; i<2*N-1; i++)
			for(int j=0; j<N; j++)
				cnt[c[i][j]]++;
		int ans[N];
		int kk=0;
		for(int k=0; k<2600; k++)
			if(cnt[k]%2){
				ans[kk] = k;
				kk++;
			}
		printf("Case #%d: ",tt+1);
		for(int i=0; i<N; i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
