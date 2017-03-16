#include <stdio.h>

#define INT64 __int64

int main()
{
	int cs, k;
	scanf("%d", &cs);
	for (k = 0; k < cs; k++) {
		INT64 p, q;
		scanf("%lld/%lld", &p, &q);
		int result = 0;
		bool err = false;
		for (;;) {
			if (p >= q) {
				for (;;) {
					if (p == 0) {
						break;
					}
					if (p >= q) {
						p -= q;
					}
					else {
						if (q % 2 == 0) {
							q /= 2;
						}
						else {
							err = true;
							break;
						}
					}
				}
				break;
			}
			if (q % 2 == 0) {
				q /= 2;
				result++;
			}
			else {
				err = true;
				break;
			}
		}
		if (err) {
			printf("Case #%d: impossible\n", k + 1);
		}
		else {
			printf("Case #%d: %d\n", k + 1, result);
		}
	}
	return 0;
}