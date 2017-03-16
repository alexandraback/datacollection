#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main() {
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("A-small-attempt3.out", "w", stdout);
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int t;
	scanf("%d", &t);
	int res;
	int r, w, c;
	int rowTry;
	for (int tt = 1; tt <= t; tt++) {
		res = 0;
		
		scanf("%d %d %d", &r, &c, &w);
		if (w == 1) {
			printf("Case #%d: %d\n", tt, r * c);
			continue;
		}

		if (r == 1) {
			res += c / w;
			res += w;
			if ( c % w == 0  ) 
				res--;
		} else {
			res +=r * (c / w);
			res += w;
			
			if ( c % w == 0 ) 
				res--;
		}
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}