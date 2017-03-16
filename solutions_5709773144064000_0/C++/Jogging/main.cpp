#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-7;
int T;
FILE *in, *out;
double c, f, x, ans;

void solve(int cs) {
	ans = x/2;
	for (int k=1; ; k++) {
		double tmp = k*f;
		double val = ans - x/(tmp-f+2);
		val += x/(tmp+2);
		val += c/(tmp-f+2);
		if (ans > val) ans = val;
		else break;
	}
	fprintf(out, "Case #%d: %.7lf\n", cs, ans);
}

int main()
{
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &T);
	for (int cs=1; cs <= T; cs++) {
		fscanf(in, "%lf%lf%lf", &c, &f, &x);
		solve(cs);
	}
	return 0;
}
