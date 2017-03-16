#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double case1 (int a, int n,float* aa, double best){
    double ans;
    double pcor = 1;
    int i;
    for (i = 0;i<a;i++) pcor *= aa[i];
    ans = pcor*(n-a+1) + (1-pcor)*(2*n +2-a);
	return ans;
}
double case3 (int a, int n,float* aa, double best){
	return (best < (n+2)) ? best : (n+2);
}
double case2(int d,int a, int n,float* aa, double best) {
	double ans;
	double pcor = 1;
	int i;
	for (i = 0;i<a-d;i++) pcor *= aa[i];
	ans = pcor*(2*d + (n-a+1)) + (1-pcor)*(2*d + 2*n -a +2);
	return best < ans ? best : ans;

}
int main() {
	int test;
	scanf("%d", &test);
	int i,j;
	for (i=1;i<=test;i++) {
		int a,n;
		double best;
		scanf("%d %d", &a, &n);
		float* aa = malloc(sizeof(float)*a);
		for (j=0;j<a;j++) scanf("%f",&aa[j]);
		best = case1 (a, n,aa,best);
		best = case3 (a, n,aa,best);
		int k;
		for (k = 1;k<=a;k++){
			best = case2 (k,a, n,aa,best);
		}
		printf("Case #%d: %.6f\n",i,best);
		free(aa);
	}
	return 0;
}
