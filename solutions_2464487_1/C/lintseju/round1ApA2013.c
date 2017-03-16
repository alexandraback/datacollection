#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int i, j, n, c = 1, x;
	long long tt;
	long long r, t;

	scanf("%d", &n);
	while(n--){
		scanf("%I64d%I64d", &r, &t);
		printf("Case #%d: %.0lf\n", c++, floor((double)t / (double)(2 * r - 1)));
	}
	return 0;
}