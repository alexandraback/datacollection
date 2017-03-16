#include<stdio.h>
#include<string.h>

int a[300], b[300];
double v[300];

int main(){
	freopen("x.txt", "r", stdin);
	freopen("w.txt", "w", stdout);
	int i, j, k, m, n;
	int T;
	scanf("%d", &T);
	for(int re = 1; re <= T; re++){
		int sum = 0;
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d", a + i);
			sum += a[i];
		}
		sum *= 2;
		double u = sum * 1.0 / n;
		printf("Case #%d:", re);
		double s = 0;
		bool flag = 1;
		k = n;
		memset(b, 0, sizeof(b));
		while(flag){
			flag = 0;
			for(i = 0; i < n; i++){
				if(u < a[i] && !b[i]){
					sum -= a[i];
					k--;
					u = sum * 1.0 / k;
					b[i] = flag = 1;
				}
			}
		}
		for(i = 0; i < n; i++){
			if(u - a[i] > 0){
				v[i] = u - a[i];
				s += v[i];
			}else
				v[i] = 0;
		}
		for(i = 0; i < n; i++){
			printf(" %.10lf", v[i] * 100 / s);
		}
		puts("");
	}
}
