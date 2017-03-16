#include <iostream>
#include <stdio.h>
using namespace std;
int m[200][200];

int main () {
	int T, TC=1, x, y;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		for (int i=0; i<x; i++) for (int j=0; j<y; j++)
			scanf("%d", &m[i][j]);

		bool t = true;
		for (int i=0; i<x; i++) for (int j=0; j<y; j++) {
			bool tt = false; int k;
			for (k=0; k<x; k++) if(m[k][j] > m[i][j]) break;
			if (k == x) tt = true;
			for (k=0; k<y; k++) if(m[i][k] > m[i][j]) break;
			if (k == y) tt = true;

			if (tt == false) t = false;
		}

		if (t) printf("Case #%d: YES\n", TC++);
		else printf("Case #%d: NO\n", TC++);
	}
} 
