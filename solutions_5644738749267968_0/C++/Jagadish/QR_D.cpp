#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

#define MEM(v,i) memset(v,i,sizeof(v))

typedef long long int LL;

double naomi[1010],ken[1010];

int main(){
	int test = 0, N = 0;
	int i = 0, j = 0, count_w = 0, count_dw = 0, low_k = 0, high_k = 0;
	int flag_n[1010], flag_k[1010];
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		scanf("%d",&N);
		MEM(naomi,0);
		MEM(ken,0);
		MEM(flag_n,0);
		MEM(flag_k,0);
		count_w = 0, count_dw = 0, low_k = 0;
		for(i = 0; i<N; i++){
			scanf("%lf",&naomi[i]);
		}
		for(i = 0; i<N; i++){
			scanf("%lf",&ken[i]);
		}
		sort(naomi,naomi+N);
		sort(ken,ken+N);
//		cout<<"---naomi---"<<endl<<flush;
//		for(i = 0; i<N; i++){
//			printf("%d %f\n",i,naomi[i]);
//		}
//		cout<<"---KEN---"<<endl<<flush;
//		for(i = 0; i<N; i++){
//			printf("%d %f\n",i,ken[i]);
//		}
		for(i = 0; i<N; i++){
			double temp = naomi[i];
			int pos = low_k;
			for(j = low_k; j<N; j++){
				if(flag_k[j]==0){
					if(temp<ken[j]){
						pos = j;
						flag_k[j] = 1;
						break;
					}
					else if(temp==ken[j]){
						pos = j;
					}
				}
			}
			if(temp>ken[pos]){
				flag_k[pos] = 1;
				count_w++;
			}
			if(low_k == pos){
				for(j = 0; j<N; j++){
					if(flag_k[j]==0){
						low_k = pos;
						break;
					}
				}
			}
		}
		low_k = 0, high_k = N-1;
		MEM(flag_k,0);
		for(i = 0; i<N; i++){
			int pos = low_k;
			if(naomi[i]> ken[pos]){
				if(low_k != high_k){
					if(naomi[i]<ken[high_k]){
						pos = low_k;
					}
					else if(naomi[i] == ken[high_k]){
						pos = high_k;
					}
				}
				else{
					pos = low_k;
				}
			}
			else if(naomi[i]==ken[pos]){
				for(j = pos+1; j<N; j++){
					if(flag_k[j] == 0){
						if(naomi[i]<ken[j]){
							pos = j;
							break;
						}
					}
				}
			}
			else if(naomi[i] < ken[pos]){
				pos = high_k;
			}
			if(naomi[i] > ken[pos]){
				count_dw++;
			}
			flag_k[pos] = 1;
			if(pos == low_k){
				for(j = low_k; j<N; j++){
					if(flag_k[j] == 0){
						low_k = j;
						break;
					}
				}
			}
			if(pos == high_k){
				for(j = high_k-1; j>= 0; j--){
					if(flag_k[j] == 0){
						high_k = j;
						break;
					}
				}
			}
		}
				
		printf("Case #%d: %d %d\n",x_test,count_dw,count_w);
	}
	return(0);
}
