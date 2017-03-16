#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int compareDoub(const void *a, const void *b){
	double x = *((double*)a);
	double y = *((double*)b);
	if(x<y) return -1;
	else if(x>y) return 1;
	else return 0;
}

void go(void){
	int n;
	scanf("%d", &n);
	double k[n];
	double m[n];
	int i;
	for(i=0; i<n; i++){
		scanf("%lf",&(m[i]));
	}
	for(i=0; i<n; i++){
		scanf("%lf",&(k[i]));
	}
	qsort(k,n,sizeof(double),compareDoub);
	qsort(m,n,sizeof(double),compareDoub);
	int p = n-1;
	int ans1=0;
	int ans2=0;
	for(i=n-1; i>=0; i--){
		if(m[i] > k[p]){
			ans2++;
		} else {
			p--;
		}
	}
	p=0;
	for(i=0; i<n; i++){
		if(m[i] > k[p]){
			p++;
			ans1++;
		}
	}
	printf("%d %d\n",ans1,ans2);
}

int main(int argc, char** argv){
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++){
		printf("Case #%d: ",i);
		go();
	}
	return 0;
}
