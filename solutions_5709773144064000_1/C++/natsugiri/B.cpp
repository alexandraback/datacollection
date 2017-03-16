#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	double C, F, X;
	scanf("%lf%lf%lf", &C, &F, &X);

	double now = 0;
	double ans = 1e12;

	for (int i=0; ;i++) {
	    double tmp = X / (2.0 + i * F) + now;
	    if (ans < tmp) {
		break;
	    } else {
		ans = tmp;
		now = C / (2.0 + i * F) + now;
	    }
	}
	
	printf("Case #%d: ", tc);
	printf("%.7f\n", ans);
    }
    return 0;
}
