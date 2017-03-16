#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <sstream>
#include <cassert>
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) ((int) x.size())
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;

double a[10000][2];

int fill(int c, int m) {
    // cout << c << " " << m << endl;
    int d = 0, i, j, h = c / 2;
    fo(j,2)fo(i,9998)
	a[i][j] = 0.0;

    if (m == c) {
	fo(i, 9998)
	    a[i][0] = 1.0;
	return 0;
    }
    
    a[0][d] = a[0][1-d] = 1;
    int u = 1;
    fo(i,m) {
	for(j = h + 1; j>0; j--) {
	    a[j][1-d] = a[j][d] + (a[j-1][d] -a[j][d]) * 0.5;
	}
	if (a[h+1][1-d] > 0.0000000001) {
	    // cout << a[u][1-d] + a[h+1][1-d] << endl;
	    a[u][1-d] += a[h+1][1-d];
	    a[h+1][1-d] = 0;
	    u++;
	}
	d = 1 - d;
    }
    // cout << a[1][d] << endl;
    return d;
}

int main(void) {
    int t, tt;
    cin >> t;
    fo(tt, t) {
	int n, x, y, l;
	cin >> n >> x >> y;

	double p = 0;
	if (n == 1) {
	    if (x == 0 && y == 0)
		p = 1;
	} else {
	    for(l = 0;l*(2*l-1) < n; l++);
	    assert(l > 0);
	    l--;
	    int xyl = abs(x) + abs(y);
	    if (xyl != 2*l) {
		if (xyl > 2*l) p = 0.0;
		if (xyl < 2*l) p = 1.0;
	    } else {
		int m = n - l*(2*l-1);
		int d = fill(1+4*l, m);
		p = a[abs(y) + 1][d];
	    }
	}
	
	printf("Case #%d: %.7lf\n", tt+1, p);
    }
}
