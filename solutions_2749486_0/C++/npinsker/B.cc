#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

#define ll long long

using namespace std;

int d, x, y, zt;
char dt[1000005];

int main() {
    scanf("%d", &zt);
    
    for (int kt=0; kt<zt; ++kt) {
	scanf("%d%d", &x, &y);
	memset(dt, 0, sizeof(dt));
	
	int p = abs(x) + abs(y), n;
	for (n=0; n<10000; ++n) {
	    if (n*(n+1)/2 > p && ((n*(n+1)/2) % 2) == (p % 2)) {
		break;
	    }
	}
	for (int i=n; i>0; --i) {
	    int nn;
	    if (abs(x) > abs(y)) {
		if (x > 0) {
		    dt[i-1] = 'E';
		    x -= i;
		}
		else {
		    dt[i-1] = 'W';
		    x += i;
		}
	    }
	    else {
		if (y > 0) {
		    dt[i-1] = 'N';
		    y -= i;
		}
		else {
		    dt[i-1] = 'S';
		    y += i;
		}
	    }
	}
	printf("Case #%d: %s\n", kt+1, dt);
    }
}