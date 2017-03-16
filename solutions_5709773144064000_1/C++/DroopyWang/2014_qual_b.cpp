#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>

static double cookie_persecond = 2.0;

void solve(int id) {
	// local variables
    double c, f, x;
	// read data
    std::cin>>c>>f>>x;	
    // process
	double t = 0;
    double rate = cookie_persecond;
    int nfarm = 0;
    while ((x-c)/rate > x/(rate+f)) {
        t += c/rate;
        rate += f;
    }
    t += x/rate;
    // output
	printf("Case #%d: %.7f\n", id, t);
}

int main(int argc, char *argv[]) {
	int t = 0;
	std::cin>>t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}