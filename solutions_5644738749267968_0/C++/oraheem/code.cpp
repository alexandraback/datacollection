#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

void printarray(double *arr, int n){
	for(int i = 0; i < n;i++){
		printf("%0.3lf ", arr[i]);
	}
	printf("\n");
}

int process(double *arr1, double *arr2, int b){
	int p1 = 0;
	int p2 = 0;
	int cnt = 0;
	while(p1 < b && p2 < b){
		if (arr1[p1] > arr2[p2]){
			cnt ++;
			p1 ++;
			p2 ++;
		}
		else p1 ++;
	}
	return cnt;
}

int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int c = 1; c <= n; c++){
		int b;
		scanf("%d", &b);
		double w1[1005];
		for(int i = 0; i < b;i++){
			scanf("%lf", &w1[i]);
		}
		double w2[1005];
		for(int i = 0; i < b;i++){
			scanf("%lf", &w2[i]);
		}

		sort(w1, w1 + b);
		sort(w2, w2 + b);
		
		int v1 = process(w1, w2, b);
		int v2 = process(w2, w1, b);

		printf("Case #%d: %d %d\n", c,  v1, b - v2);
	}
}