#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>

using namespace std;

double solve(int n, int x, int y)
{
    int lev = (x+y)/2;
    int ub = lev*lev*2 + lev*3 + 1;
    int lb = (lev-1)*(lev-1)*2 + (lev-1)*3 + 1;
    double p;
    if (n > ub) {
	p = 1.0;
    } else if (n <= lb) {
	p = 0.0;
    } else if (x == 0) {
	p = (n == ub) ? 1.0 : 0.0;
    } else if (y == 0) {
	int m = n - lb;
	if (m > x+y) p = 1.0;
	else {
	    p = 0.5;
	    double x = 0.25;
	    for (int i=1; i<m; i++) {
		p += x;	
		x *= 0.5;
	    }
	}
    } else {
	int m = n - lb;
	if (m > x+y+y) p = 1.0;
	else {
	    double tmp1 = solve(n-1, x+1, y-1);
	    double tmp2 = solve(n-1, x, y);
	    p = 0.5*(tmp1-tmp2) + tmp2;
	}
    }
    return p;
}

int main()
{
    int T,N,X,Y;
    cin >> T;
    for (int c=1; c<=T; c++) {
	double p;
	cin >> N >> X >> Y;
	printf("Case #%d: %.7lf\n", c, solve(N,abs(X),abs(Y)));
    }
    return 0;
}
