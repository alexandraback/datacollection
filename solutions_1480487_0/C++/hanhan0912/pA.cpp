#include <cstdio>
#include <math.h>
#include <algorithm> 

const int N = 300;
const double eps = 1e-12;

int n;
double s, x[N];

bool ok(int a, double p){
	double v = x[a] + s * p, tmp = p;
	for (int i = 0; i < n; i++){
		if (i != a && x[i] < v){
			tmp += (v - x[i]) / s;
		}
	}
	return tmp <= 1.0;
}
void solve(int nCase){
	printf("Case #%d:", nCase);
	
	s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lf", &x[i]);
		s += x[i];
	}
	double l, r, mid;
	for (int i = 0; i < n; i++){
		l = 0; r = 1.0;
		while (l + eps < r){
			mid = (l + r) * 0.5;
			if (ok(i, mid)) l = mid;
			else r = mid;
		}
		printf(" %f", l * 100.0);
	}
	puts("");
}
int main(){
	int nT;
	scanf("%d", &nT);
	for (int i = 0; i < nT; i++)
		solve(i+1);
	//while(1);
	return 0;
}
