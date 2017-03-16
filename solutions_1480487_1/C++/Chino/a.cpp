#include <cstdlib>
#include <cstdio>


int main(){
	int T,cases;
	
	
	int N, X;
	int i,j,k;
	int op;
	int scores[1000];
	double perc[1000];
	int M;
	
	scanf("%d\n",&T);
	cases = 0;
	while(cases < T){
		scanf("%d\n",&N);
		X=0;
		for(i=0; i<N; i++){
			scanf("%d\n",&scores[i]);
			X+=scores[i];
		}
		M=N;
		int X2=0;
		for(i=0; i<N; i++){
			double p;
			p = ((double)(2*X)/N - scores[i])/(double)X;
			if(p<0){
				perc[i]=0.0;
				M--;
			}else{
				X2+=scores[i];
				perc[i]=-10.0;
			}
		}
		for(i=0; i<N; i++){
			if(perc[i]<0.0){
				double p;
				p = ((double)(X + X2)/M - scores[i])/(double)X;
				perc[i]=p;
			}
			
		}
		printf("Case #%d:",++cases );
		for(i=0; i<N; i++){
			printf(" %lf",100*perc[i]);
		}
		
		printf("\n");
	}
}
