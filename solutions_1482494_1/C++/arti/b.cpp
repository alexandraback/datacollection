#include <cstdio>
#include <iostream>

using namespace std;

int a[10000];
int b[10000];
int c[10000];

int main() {
  int T; scanf("%d\n", &T);
  for (int tt = 1; tt <= T; ++tt) {
  	int n; scanf("%d", &n);
  	for (int i = 0; i < n; ++i) {
  		scanf("%d %d", &a[i], &b[i]);
  		c[i] = 0;
  	}
  	int r = 0;
  	int d = 0;
  	while (true) {
//  		cout << d << endl;
  		int x = -1;
  		int y = -1;
  		int z = -1;
  		int w = -1;
  		int q = -1;
  		int l = -1;
  		for (int i = 0; i < n; ++i) {
  			if (c[i] == 0) {
  				if (w == -1 || b[i] < w) {
  					w = b[i];
  					x = i;
  				}
  				if (a[i] <= d && (q == -1 || b[y] <= b[i])) {
//  				if (q == -1 || (a[i] < ) {
  					q = a[i];
  					y = i;
  				}
  			} else if (c[i] == 1) {
  				if (l == -1 || b[i] < l) {
  					l = b[i];
  					z = i;
  				}
  			}
  		}
  		if (x == -1 && z == -1) break;
  		if (w != -1 && d >= w) {
  			d += 2 - c[x];
  			c[x] = 2;
//	  		cout << x << " " << w << " " << 2 << endl;
  		} else if (l != -1 && d >= l) {
  		 	d += 2 - c[z];
  			c[z] = 2;
//	  		cout << z << " " << l << " " << 1 << "-" << 2 << endl;
		} else {
  			if (d < q || q == -1) {
  				r = -1;
  				break;
  			}
  			d += 1 - c[y];
  			c[y] = 1;
//	  		cout << y << " " << q << " " << 1 << endl;
  		}
  		++r;
  	}
  	fprintf(stderr, "%d\n", tt);
    printf("Case #%d: ", tt);
    if (r == -1) printf("Too Bad");
    else printf("%d", r);
    putchar('\n');
  }
  return 0;
}

