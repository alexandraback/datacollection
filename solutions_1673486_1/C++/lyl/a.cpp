#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1000010;

int a, b;
double prob[maxn], pc[maxn];


int main() {
	int ca;
	cin >> ca;
	for (int tt = 1; tt <= ca; tt++) {
		cin >> a >> b;
		for (int i = 0; i < a; i++) {
			scanf("%lf", prob + i);
		}

		double ans = 2 + b;
		pc[0] = 1;
		for (int i = 1; i <= a; i++)
			pc[i] = pc[i - 1] * prob[i - 1];

		
		for (int i = 0; i <= a; i++) {
			double tmp = pc[i] * (a - i + b - i + 1) + (1 - pc[i]) * (a - i + b - i + 2 + b);
			ans = min(ans, tmp);
		}
		printf("Case #%d: %.6lf\n", tt, ans);
	}
}
