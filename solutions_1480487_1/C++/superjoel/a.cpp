#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int s[256];

void run(int fall){
	int N;
	int X=0;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%d", &s[i]);
		X += s[i];
	}
	printf("Case #%d:", fall);
	for(int i=0;i<N;i++){
		double lo = 0;
		double hi = 1;
		while(hi-lo > 1e-9){
			double mid = (hi+lo)/2;
			double myScore = s[i] + X*mid;
			double kvar = 1-mid;
			for(int j=0;j<N;j++){
				if(i==j)continue;
				if(s[j]>myScore)continue;
				double behover = (myScore - s[j])/X;
				kvar -= behover;
			}
			if(kvar<0){
				hi = mid;
			} else {
				lo = mid;
			}
		}
		printf(" %0.6lf", (lo+hi)/2*100);
	}
	printf("\n");
}


int main(){
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		run(i+1);
	}	
}