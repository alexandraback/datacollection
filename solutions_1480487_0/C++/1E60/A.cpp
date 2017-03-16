#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include <map>
#include <vector>
using namespace std;

void test(void)
{
	int N;
	int n;
	scanf("%d ",&N);
	int s[N];
	int X=0;
	for (n=0;n<N;n++){
		scanf("%d ",&s[n]);
		X+=s[n];
	}
	double avg;
	int over_avg[N];
	int N_over_avg=0;
	memset(over_avg,0,sizeof(int)*N);
	while (1){
		avg=X;
		for (n=0;n<N;n++){
			if (!over_avg[n]){
				avg+=s[n];
			}
		}
		avg/=N-N_over_avg;
		int break_flag=1;
		for (n=0;n<N;n++){
			if (avg<s[n] && (!over_avg[n])){
				over_avg[n]=1;
				N_over_avg++;
				break_flag=0;
			}
		}
		if (break_flag)break;
	}
	//fprintf(stderr,"avg=%lf,X=%d,%d\n",avg,X,N_over_avg);
	for (n=0;n<N;n++){
		double ret;
		if (over_avg[n])ret=0.0;
		else{
			ret=(avg-s[n])/(double)X;
			assert(ret>=0);
		}
		ret*=100.0;
		printf(" %.8lf",ret);
	}
}

int main(void)
{
	int T;
	int t;
	scanf("%d\n",&T);
	for (t=0;t<T;t++){
		printf("Case #%d:",t+1);
		test();
		printf("\n");
	}
	return 0;
}
