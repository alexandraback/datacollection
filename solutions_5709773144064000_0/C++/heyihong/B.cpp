#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int c, ca;
double C, F, X;

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &ca);
	for (int c = 1; c <= ca; ++c) {
		scanf("%lf%lf%lf", &C, &F, &X);
		double ans = X / 2;
		double tmp = 0;
		for (int i = 0; ; ++i) {
			tmp += C / (2 + i * F);
			if (ans <= tmp + X / (2 + (i + 1) * F)) break;
			ans = tmp + X / (2 + (i + 1) * F);
		}
		printf("Case #%d: %.7lf\n", c, ans);
	}
	return 0;
}