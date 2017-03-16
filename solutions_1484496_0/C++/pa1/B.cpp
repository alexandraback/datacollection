#include<iostream>
#include <map>
using namespace std;
int main(){
	int T,A[509],t,N,i,ans=0,k=0,j;
	bool found = true;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		map<int,int> sum;
		for(i=0;i<N;i++){
			scanf("%d",&A[i]);
		}
		found = false;
		for(i=1;i<(1<<N);i++){
			j = i;
			ans = 0;
			k = 0;
			while(j>0){
				if((j&1) == 1){
					ans += A[k];
				}
				k++;
				j = j>>1;
			}
			//printf("ans = %d,j =%d\n",ans,j);
			if(ans > 0){
				if(sum[ans] > 0){
					found = true;
					break;
				}
				sum[ans] = i;
			}
		}
		
		printf("Case #%d:\n",t);
		if(found){
			k = 0;
			while(i>0){
				if(i&1 == 1)
					printf("%d ",A[k]);
				i = i >> 1;
				k++;
			}
			printf("\n");
			k = 0;
			i = sum[ans];
			while(i>0){
				if(i&1 == 1)
					printf("%d ",A[k]);
				i = i >> 1;
				k++;
			}
		} else {
			printf("Impossible");
		}
		printf("\n");
	}
}