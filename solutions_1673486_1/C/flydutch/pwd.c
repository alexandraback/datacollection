#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]) {
	int T, t;

	scanf("%d", &T);
	for (t=0; t<T; t++) {
		int A, B;
		int i;
		float min, p;

		scanf("%d %d", &A, &B);
		min = B+2;
		p = 1;
		for (i=0; i<A; i++) {
			float tmp, n;

			scanf("%f", &tmp);
			p *= tmp;
			n = p*(2*(A-i-1)+(B-A)+1);
			n += (1-p)*(2*(A-i-1)+(B-A)+1+B+1);
			if (n<min)
				min = n;
		}

		printf("Case #%0d: %.6f\n", t+1, min);

	}

	return (0);
}
