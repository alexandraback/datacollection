#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void run(){
	int T;
	int N;
	int vote[200000];
	int allvote;
	int minvote;
	double result;
	double newresult;
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		scanf("%d",&N);
		allvote=0;

		for(int j=0;j<N;j++){
			scanf("%d",&(vote[j]));
			allvote+=vote[j];
		}

		printf("Case #%d:",i+1);
		for(int j=0;j<N;j++){
			newresult=100*(double(allvote)*2/N-vote[j])/double(allvote);
			do{
				result=newresult;
				int gt=0;
				int gtsum=0;
				for(int k=0;k<N;k++){
					if(vote[k]<=result/100*allvote+vote[j]){
						gt++;
						gtsum+=vote[k];
					}
				}
				newresult=100*(double(gtsum+allvote)/gt-vote[j])/double(allvote);
				//printf("gt :%d gtsum %d %lf\n",gt,gtsum,newresult);
			}while((fabs(newresult-result)>1e-9)&&(result>=0));

			if(result>=0)
				printf(" %.6lf",result);
			else printf(" 0.000000",result);
		}
		printf("\n");
	}
}


int main(int argc,char** argv){
	run();
	return 0;
}
