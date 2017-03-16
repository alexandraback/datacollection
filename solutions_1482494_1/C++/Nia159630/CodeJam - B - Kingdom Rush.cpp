#include <stdio.h>
#include <algorithm>
using namespace std;

struct Level {
	int a, b;
};

bool cmp (Level a , Level b) {
	return a.b < b.b;
}

int main () {
	int T, tt, n, i, sc, rem, times, d, p;
	int finished[1000];
	Level req[1000];
	freopen ("B-large.in" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);
	scanf ("%d" , &T);
	for (tt = 1 ; tt <= T ; tt++) {
		scanf ("%d" , &n);
		for (i = 0 ; i < n ; i++) {
			scanf ("%d%d" , &req[i].a , &req[i].b);
			finished[i] = 0;
		}
		sort (req , req + n , cmp);
		times = sc = 0;
		rem = n;
		while (rem > 0) {
			for (i = 0 ; i < n ; i++) {
				if (finished[i] != 2 && sc >= req[i].b) {
					sc += 2 - finished[i];
					finished[i] = 2;
					times++;
					rem--;
					break;
				}
			}
			if (i == n) {
				p = d = -1;
				for (i = 0 ; i < n ; i++) {
					if (finished[i] == 0 && sc >= req[i].a && req[i].b - sc > d) {
						d = req[i].b - sc;
						p = i;
					}
				}
				if (p == -1) {
					times = -1;
					break;
				}
				else {
					finished[p] = 1;
					sc++;
					times++;
				}
			}
		}
		if (times == -1) {
			printf ("Case #%d: Too Bad\n" , tt);
		}
		else {
			printf ("Case #%d: %d\n" , tt , times);
		}
	}
}