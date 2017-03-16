#include <stdio.h>

int main(){
	int N;
	int n;
	int votes[300];
	int min;
	int nummin;
	scanf("%d",&N);
	for(int c = 1;c<=N;c++){
		scanf("%d",&n);
		min = 300;
		int secmin = 300;
		int sum = 0;
		nummin = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",votes+i);
			if(votes[i] == min){
				nummin++;
			} else {
				secmin = min;
				nummin = 1;
			}
			min = (votes[i]>min)?min:votes[i];
			sum+= votes[i];
		}
		double sum2 = (double)sum*2.0/(double)n;
		/*
		
		for(int i = 0;i<n;i++){
			if(min != votes[i] || nummin > 1)
				sum2+=(((double)(min-votes[i])/(double)sum)+1.0)/2;
			else
				sum2+=(((double)(secmin-votes[i])/(double)sum)+1.0)/2;
		}
		*/
		double second[300];
		for(int i = 0;i<n;i++)
			second[i] = 1.0;
	
		double sum3;
		double sum4;
		int neg = 0;
		do {
			sum3 = 0.0;
			neg = 0;
			sum4=0.0;
			int nn = 0;
			for(int i = 0;i<n;i++){
				if(second[i] < -0.1)
					continue;
				sum4+= votes[i];
				nn++;
			}

			sum2 = (double)(sum+sum4)/(double)nn;
		

			for(int i = 0;i<n;i++){
				if(second[i] < -0.1)
					continue;
				second[i] = (sum2-(double)votes[i])/((double)sum);
				if(second[i] < 0){
					neg++;
					second[i] = -1.0;
				}else{
					sum3+=second[i];
				}
			}	
		}while(neg >0);
		for(int i = 0;i<n;i++)
				if(second[i] < -0.1)
					second[i] = 0.0;
			
		printf("Case #%d: ",c);
		for(int i = 0;i<n;i++){
		/*	if(min != votes[i] || nummin > 1)
				printf("%f",(((double)(min-votes[i])/(double)sum)+1.0)/(0.02));
			else
				printf("%f",(((double)(secmin-votes[i])/(double)sum)+1.0)/(0.02));
				*/
			printf("%f",100.0*second[i]/sum3);
			printf("%s",(i==n-1)?"\n":" ");
		}
	}
	return 0;
}
