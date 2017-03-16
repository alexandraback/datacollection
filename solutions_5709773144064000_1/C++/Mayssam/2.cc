
#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

double run(double c, double f, double x, double rate = 2.0) {
    double tf = 0;
    double ret = 0.0;
    while (true) {
	double xf = x / (rate + tf);
	double cf = c / (rate + tf);
	tf += f;
	double xff = x / (rate + tf);
	if (xf < cf + xff) {
	    ret += xf;
	    break;
	} else {
	    ret += cf;
	}
    }
    return ret;
}


double solve(double c, double f, double x) {
    return run(c, f, x);
}

int main() {

    int t = 0;
    cin >> t;
    for (int i=0; i<t; i++) {
	double c, f, x = -1;
	cin >> c >> f >> x;
	if (x<0) break;
	fprintf(stdout, "Case #%d: %0.7lf\n", (1+i), solve(c, f, x));
    }

    return 0;
}
