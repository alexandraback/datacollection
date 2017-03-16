#include <cstdio>
#define DIFF 0.0000001
int judge_scores[200];
int amount[101];
double needed[101];
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int total=0;
		for(int j = 0; j < 101; ++j)
			amount[j]=0;
		for(int j = 0; j < n; ++j){
			scanf("%d", &judge_scores[j]);
			total += judge_scores[j];
			++amount[judge_scores[j]];
		}
		//int amount_prev=0;
		//for(int j = 0; j < 101; ++j){
		//	double used=0.0;
		//	for(int k = 0; k < 101; ++k){

		//	}
			//amount_prev += amount[j];
		//}
		double used=0.0;
		int amount_prev=0;
		for(int s = 0; s < 101; ++s){
			needed[s]=0.0;
			double need=used+(double)(amount_prev+amount[s])/(double)(total);
			if(need>1.0+DIFF){
				for(int k = 0; k <= s; ++k){
					needed[k]+=(1.0-used)/(double)(amount_prev+amount[s]);
				}
				for(int k = s+1; k < 101; ++k){
					needed[k]=0.0;
				}
				used=1.0;
				break;
			}else{
				for(int k = 0; k <= s; ++k){
					needed[k] += 1.0/(double)total;
				}
			}
			used = need;
			amount_prev += amount[s];
		}
		if(needed[100]>DIFF){
			for(int k = 0; k < 101; ++k){
				needed[k] += (1.0-used)/(double)n;
			}
		}
		printf("Case #%d: ", i+1);
		for(int j = 0; j < n; ++j){
			printf("%lf ", needed[judge_scores[j]]*100.0);
		}
		printf("\n");
	}
}
