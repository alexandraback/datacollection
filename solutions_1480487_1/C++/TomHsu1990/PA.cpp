#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
double p[SIZE], q[SIZE];
int main(){
	int t;
	double n;
	scanf("%d", &t);
	for(int c=1;c<=t;++c){
		scanf("%lf", &n);
		double total = 0;
		for(int i=0;i<n;++i){
			scanf("%lf", &p[i]);
			total += p[i];
		}
		double cnt = 0, ave = 2.0*total/n, sum = 0, tt = total;
		for(int i=0;i<n;++i){
			if(p[i] <= ave){
				++cnt;
				q[i] = p[i];
			}
			else{
				q[i] = -1;
				sum += p[i];
			}
		}
		total = 2.0*total - sum;
		ave = total/cnt;
		printf("Case #%d:", c);
		for(int i=0;i<n;++i){
			if(q[i] == -1) printf(" %.6lf", 0.0);
			else{
				double tmp = 100.0*(ave-q[i])/tt;
				if(tmp < 0) tmp = 0;
				printf(" %.6lf", tmp);
			}
		}
		printf("\n");
	}
	
	return 0;
}
