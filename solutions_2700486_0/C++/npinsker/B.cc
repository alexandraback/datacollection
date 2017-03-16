#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cassert>

#define ll long long

using namespace std;

int n, x, y, zt;
double kcn[3005][3005];
double two[3005];

int main() {
    scanf("%d", &zt);
    
    two[0] = 1;
    for (int i=1; i<3005; ++i) {
	kcn[i][0] = 1;
	two[i] = two[i-1] * 2.;
	for (int j=1; j<=i; ++j) {
	    kcn[i][j] = kcn[i][j-1] * (double)(i - (j-1)) / (double)j;
	}
    }
    
    for (int kt=0; kt<zt; ++kt) {
	scanf("%d%d%d", &n, &x, &y);
	
	int row = (abs(x) + abs(y)) / 2;
	double prob = 0.0;
	ll base = 0;
	
	for (int i=0; i<row; ++i) {
	    base += (ll)(4*i + 1);
	}
	if ((long long)n <= base);
	else if (x == 0) { prob = (n >= base + (ll)(4*row + 1)); }
	else if (n >= (ll)(4*row + 1) + base) prob = 1.0;
	else {
	    int nb = n - base, mh = 2*row + 1;
	    if (nb >= mh) {
		y -= (nb - (mh-1));
		nb -= 2*(nb - (mh-1));
	    }
	    if (y < 0) { prob = 1.0; }
	    else {
		double sum = 0.;
		for (int i=y+1; i<=nb; ++i) {
		    sum += kcn[nb][i];
		}
		sum /= two[nb];
		prob = sum;
	    }
	}
	printf("Case #%d: %lf\n", kt+1, prob);
    }
}