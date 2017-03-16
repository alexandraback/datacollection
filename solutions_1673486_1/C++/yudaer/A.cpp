#include<cstdio>
#include<cstring>

double p[200000];

int main(){
//	freopen("in.txt" , "r" , stdin);
//	freopen("out.txt" , "w" , stdout);

	int t;
	scanf("%d" , &t);

	for(int ii = 1;ii <= t;ii++){
		int A, B;
		scanf("%d%d" , &A, &B);
		int i;
		for(i = 0;i < A;i++){
			scanf("%lf" , &p[i]);
		}

		double ret = B + 2 < A + B + 1 ? B + 2 : A + B + 1;
		double res = 1;
		for(i = 0;i < A;i++){
			res *= p[i];
			double temp = 0;
			temp += res * (A - i - 1 + B - i) + (1 - res) * (A - i - 1 + B - i + B + 1);
			ret = ret < temp ? ret : temp;
		}
		printf("Case #%d: %.8lf\n" , ii, ret);
	}

	return 0;
}