#include <cstdio>
#include <iostream>

using namespace std;

int a[10000];
int b[10000];
int c[1 << 20];
int d[1 << 20];
int q[1 << 20];

int main() {
  int T; scanf("%d\n", &T);
  for (int i = 1; i < 1 << 10; ++i) {
  	c[i] = c[i >> 1] + (i & 1);
  }
  for (int tt = 1; tt <= T; ++tt) {
  	int n; scanf("%d", &n);
  	for (int i = 0; i < n; ++i) {
  		scanf("%d %d", &a[i], &b[i]);
  	}
  	memset(d, ~0, sizeof(d));
  	int h = 0, t = 0;
  	q[t++] = 0;
  	d[0] = 0;
  	int r = -1;
  	while (h < t) {
  		int v = q[h++];
  		if ((v >> n) == (1 << n) - 1) {
  			r = d[v];
  			break;
  		}
  		int w = c[v & ((1 << n) - 1)] + 2 * c[~(v & ((1 << n) - 1)) & (v >> n)] + c[(v & ((1 << n) - 1)) & (v >> n)];
 		for (int i = 0; i < n; ++i) {
 			if (!(v & (1 << i)) && (a[i] <= w) && d[v | (1 << i)] == -1) {
 				d[v | (1 << i)] = d[v] + 1;
 				q[t++] = v | (1 << i);
 			}
  		}
 		for (int i = 0; i < n; ++i) {
 			if (!(v & (1 << (n + i))) && (b[i] <= w) && d[v | (1 << (n + i))] == -1) {
 				d[v | (1 << (n + i))] = d[v] + 1;
 				q[t++] = v | (1 << (n + i));
 			}
  		}
  	}
  	fprintf(stderr, "%d\n", tt);
    printf("Case #%d: ", tt);
    if (r == -1) printf("Too Bad");
    else printf("%d", r);
    putchar('\n');
  }
  return 0;
}

