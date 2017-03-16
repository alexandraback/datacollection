#include <stdio.h>
#include <string.h>

struct ab_t {
	int l[2];
	int c;
};

int f_sort(struct ab_t *a, struct ab_t *b) {
	if (a->l[0] < b->l[0])
		return (-1);
	if ((a->l[0] == b->l[0]) &&
	    (a->l[1] > b->l[1]))
		return (-1);
	return (1);
}


int main(int argc, char *argv[]) {
	int T, t;

	scanf("%d", &T);
	for (t=0; t<T; t++) {
		int N, nt, stars, done;
		struct ab_t ab[1000];
		int i;

		nt = 0;
		stars = 0;
		done = 0;
		scanf("%d", &N);
		memset(ab, 0, sizeof(ab));
		for (i=0; i<N; i++)
			scanf("%d %d", &ab[i].l[0], &ab[i].l[1]);

		qsort(ab, N, sizeof(ab[0]), f_sort);
		//for (i=0; i<N; i++)
		//	printf("%d %d\n", ab[i].l[0], ab[i].l[1]);
		//printf("\n");

		do {
			int pstars = stars;
			int found = 0;
			for(i=0; i<N; i++) {
				if (ab[i].l[1] <= stars && ab[i].c < 2) {
					stars += 2-ab[i].c;
					nt++;
					ab[i].c = 2;
					found = 1;
					//printf("2.%d (%d)\n", i, stars);
				}
			}
			if (!found) {
				for(i=0; i<N; i++) {
					if (ab[i].l[0] <= stars && ab[i].c == 0) {
						stars++;
						nt++;
						ab[i].c = 1;
						found = 1;
						//printf("1.%d (%d)\n", i, stars);
						break;
					}
				}
			}
			//printf(".\n");
			if (!found)
				goto term;
			if (stars == 2*N)
				done = 1;
		} while (!done);

	 term:
		if (done)
			printf("Case #%0d: %d\n", t+1, nt);
		else
			printf("Case #%0d: Too Bad\n", t+1);

	}

	return (0);
}
