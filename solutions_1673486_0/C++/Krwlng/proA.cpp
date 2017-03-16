#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define N 1010
double p[N];
int n, m;

double getmin(double x, double y) { 
//	printf("y:%.6f\n", y);
	return x < y ? x : y; 
}

void conduct()
{
	int i; double ans, tmp;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%lf", &p[i]);
	ans = m+2.0;
	for (i = 0, tmp = 1.0; i < n; ++i) tmp *= p[i];
	if (m == n) ans = (m+2) * (1.0-tmp) + tmp; 
	ans = getmin(ans, (2*m-n+2)*(1.0-tmp) + (m-n+1)*tmp);
	for (i = 0, tmp = 1.0; i < n; ++i) {
		ans = getmin(ans, (2*(n-i)+m-n+1)*tmp + (2*(n-i)+2*m-n+2)*(1-tmp));
		tmp *= p[i];
	} printf("%.6f\n", ans);
}

int main() {
	int time;
	scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	} return 0;
}
