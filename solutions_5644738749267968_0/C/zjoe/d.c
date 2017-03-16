#include <stdio.h>

int cmp(const void *x, const void *y);
int main(){
	int i, j, k, tot, n, ans1, ans2;
	double a[1005], b[1005];

	scanf("%d", &tot);
	for(i = 1; i <= tot; i++){
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%lf", &a[j]);
		}
		for(j = 0; j < n; j++){
			scanf("%lf", &b[j]);
		}
		qsort(a, n, sizeof(double), cmp);
		qsort(b, n, sizeof(double), cmp);
		
				ans1 = 0;
		k = 0;
		for(j = 0; j < n; j++){
			while(k < n && b[k] >= a[j]){
				k++;
			}
			if(k < n){
				ans1++;
				k++;
			}
			else{
				break;
			}
		}
		ans2 = n;
		k = n - 1;
		for(j = n - 1; j >= 0; j--){
			while(k >= 0 && b[k] <= a[j]){
				k--;
			}
			if(k >= 0){
				ans2--;
				k--;
			}
			else{
				break;
			}
		}
		printf("Case #%d: %d %d\n", i, ans1, ans2);
	}
	return 0;
}
int cmp(const void *x, const void *y){
	double t;
	t = *(double *)y - *(double *)x;
	return t > 0 ? 1 : (t == 0 ? 0 : -1);
}
