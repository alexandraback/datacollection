//pA
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 100010;

double p[N], ac[N];

void solve(int t){
	int a, b;
	double dtmp = 1.0, ans, t1, t2;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++){
		scanf("%lf", &p[i]);
		dtmp *= p[i];
		ac[i] = dtmp;
		//if (i) ac[i] += ac[i-1];
	}
	ans = 1 + b + 1;
	for (int i = 0; i < a; i++){
		t1 = t2 = i + (b-(a-i)) + 1;
		t2 += b + 1;
	//	printf("#%d %.0f %f: ", i, t1, ac[a-i-1]);
		t1 *= ac[a-i-1];
		t2 *= 1.0-ac[a-i-1];
		//printf("%f %f ", t1, t2);
		dtmp = t1 + t2;
		if (dtmp < ans) ans = dtmp;
	//	printf("%f\n", dtmp);
	}
	printf("Case #%d: %f\n", t, ans);
}
int main(){
	int nT;
	scanf("%d", &nT);
	for (int i = 1; i <= nT; i++)
		solve(i);
//	while(1);
	return 0;
}
