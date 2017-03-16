#include<stdio.h>
#include<stdlib.h>
int s[300];
int used[300];
double ans[300];
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1;ca <= T;ca++){
		int N;
		scanf("%d",&N);
		int sum = 0;
		for(int i=0;i<N;i++){
			scanf("%d",&s[i]);
			used[i] = 0;
			sum += s[i];
		}
		double minP = sum * 2.0 / N;
		int flag = 0;
		for(int i=0;i<N;i++){
			if(s[i] > minP){
				flag = 1;
				break;
			}
		}
		printf("Case #%d: ",ca);
		if(flag == 0){
			for(int i=0;i<N;i++){
				printf("%.6lf",(minP - s[i]) / sum * 100.0);
				if(i != N - 1)
					printf(" ");
				else
					printf("\n");
			}
			continue;
		}else{
			
			
			int count = 0;
			minP = sum * 2.0 / N;
			for(int i=0;i<N;i++){
				if(s[i] > minP){
					ans[i] = 0.0;
					used[i] = 1;
				}
			}
			int tmpSum = 0;
			for(int i=0;i<N;i++){
				if(used[i] == 0){
					tmpSum += s[i];
					count++;
				}
			}
			minP = (sum + tmpSum)  * 1.0/ count;
			for(int i=0;i<N;i++){
				if(used[i] == 0){
					ans[i] = (minP - s[i]) / sum;
			//		ans[i] = minP - s[i];
				}
			}
			//printf("sum = %d,tmpSum = %d\n",sum,tmpSum);
			//printf("minP = %lf count = %d\n",minP,count);
			for(int i=0;i<N;i++){
				printf("%.6lf",ans[i] * 100.0);
				if(i != N - 1)
					printf(" ");
				else
					printf("\n");
			}
			continue;
		}
	}
	return 0;
}
