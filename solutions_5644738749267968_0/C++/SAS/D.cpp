#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
double a[1000], b[1000];
bool com(double a,double b){return (a > b);}
int orderWin(double *aa, double *bb, int N){
	for(int i=0;i<N;i++){
		if(aa[i] > bb[i]){
			continue;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ca++){
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;i++) scanf("%lf",&a[i]);
		for(int i=0;i<N;i++) scanf("%lf",&b[i]);
		sort(a, a + N, com);
		sort(b, b + N, com);

		int y = 0;
		for(int i=0;i<N;i++){
			if(orderWin(a , b + i , N - i)){
				y = N - i;
				break;
			}
		}
		int z = 0;
		double *bp = b;
		for(int iter=0;iter<N;iter++){
			if(a[iter] > *bp){
				z++;
			}else{
				bp++;
			}
		}

		printf("Case #%d: %d %d\n",ca, y,z);
	}
	return 0;
}
