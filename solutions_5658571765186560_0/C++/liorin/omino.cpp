#include <cstdio>
#include <cstdlib>
#include <vector>


int int_ceil_div(int n, int k) {
	int ret = n/k;
	if (n % k != 0)
		ret +=1;
	return ret;
}


int main () {
	int t,x,r,c,i, min, max;
	bool ans;
	scanf("%d\n", &t);

	for (i = 1; i <=t; i++) {
		scanf("%d %d %d\n", &x, &r, &c);
		ans = true;
		min = (r < c ? r : c);
		max = (r > c ? r : c);
		
		if (x >= 7 || r*c % x != 0 || int_ceil_div(x,2) > min || x > max)
			ans = false;
		if (ans && x > 3) {
			if (x == 4 && min == 2) ans = false;
			if (x == 6 && min == 3) ans = false;
		}

		printf("Case #%d: %s\n",i, (ans ? "GABRIEL" : "RICHARD"));
	}

	return 0;
}
