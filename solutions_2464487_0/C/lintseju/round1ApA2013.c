#include <stdio.h>
#include <string.h>

double pi = 3.14159265358;

int main()
{
	int i, j, n, c = 1, x;
	long long tt;
	int r, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &r, &t);
		x = 0;
		r++;
		tt = t - 2 * r + 1;
		while(tt >= 0){
			x++;
			r += 2;
			tt -= (2 * r - 1);
		}
		printf("Case #%d: %d\n", c++, x);
	}
	return 0;
}