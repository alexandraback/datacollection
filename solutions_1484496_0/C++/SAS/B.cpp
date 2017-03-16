#include<stdio.h>
#include<stdlib.h>
int used[3000000];
int a[600];
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1;ca <= T;ca++){
		int N;
		scanf("%d",&N);
		int sum = 0;
		for(int i=0;i<N;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		for(int i=0;i<sum + 10;i++)used[i] = 0;
		int up = 1 << N;
		int ts = 0;
		for(int i=1;i<=up;i++){
			ts = 0;
			for(int j=0;j<N;j++){
				if((i & (1 << j)) != 0){
					ts += a[j];
				}
			}
			used[ts]++;
			if(used[ts] > 1){
				break;
			}
		}
		int count = 0;
		printf("Case #%d:\n",ca);
		for(int i=1;i<=up;i++){
			int tts = 0;
			for(int j=0;j<N;j++){
				if((i & (1 << j)) != 0){
					tts += a[j];
				}
			}
			if(ts == tts){
				for(int j=0;j<N;j++){
					if((i & (1 << j)) != 0){
						printf("%d ",a[j]);
					}
				}
				printf("\n");
				count++;
			}
			if(count >= 2)break;
		}
	}
	return 0;
}
