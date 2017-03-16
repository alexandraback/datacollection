#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

int a[7];

bool chk (int i, int j, int k, int t) {
	return t == 1 || i == t || j == t || k == t
		|| i * j == t || j * k == t || i * k == t
		|| i * j * k == t;
}

int main () {
	int i, j, k, T, t;
	int r, n, m, nou;
	scanf ("%d", &T);
	printf ("Case #1:\n");
	scanf ("%d%d%d%d", &r, &n, &m, &nou);
	for (int cnt = 1; cnt <= r; cnt++) {
		for (i = 1; i <= nou; ++i) scanf ("%d", &a[i]);
		for (i = 2; i <= m; ++i)
			for (j = 2; j <= m; ++j)
				for (k = 2; k <= m; ++k) {
					for (t = 1; t <= nou; ++t) 
						if (!chk (i, j, k, a[t])) break;
					if (t > nou) {
						printf("%d%d%d\n", i,j,k);
						goto lab;
					}
				}
	lab:;
						
	}
	return 0;
}
	
