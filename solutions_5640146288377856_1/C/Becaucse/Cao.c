
#include <stdio.h>

int main() {
	int i, ts, r, c, w, result;
	FILE *rfp, *wfp;

	rfp = fopen("A-large.in", "r");
	wfp = fopen("answer.txt", "w");

	fscanf(rfp, "%d", &ts);

	for(i = 0 ; i < ts ; i++) {
		result = 0;

		fscanf(rfp, "%d %d %d", &r, &c, &w);
		if(c % w == 0)
			result = (c/w)*r + (w - 1);
		else
			result = (c/w)*r + w;

		fprintf(wfp, "Case #%d: %d\n", i + 1, result);
	}

	return 0;
}
