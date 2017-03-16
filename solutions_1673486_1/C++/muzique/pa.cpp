#include <cstdio>
#include <iostream>

using namespace std;

double cal(int typed, int n, double *v)
{
    double ks;
    int i, j;
    double xpt;
    double pos = 1;
    //enter
    ks = n + 2;
    //backspcae
    for (i = 0; i < typed; ++i) {
	for (j = 0, pos = 1; j < typed - i; ++j) {
	    pos *= v[j];
	}
	xpt = pos * (2 * i + n - typed + 1) + (1 - pos) * (2 * i + 2 * n - typed + 2);
	if (xpt < ks)
	    ks = xpt;
    }

    return ks;
}

int main(void)
{
    int tc, i, j;
    int typed, n;
    double pos;
    double v[100001];
    for (cin >> tc, i = 1; i <= tc; ++i) {
	cin >> typed >> n;
	printf("Case #%d: ", i);
	for (j = 0; j < typed; ++j) {
	    cin >> v[j];
	}
	printf("%.6lf\n", cal(typed, n, v));
    }
    return 0;
}

