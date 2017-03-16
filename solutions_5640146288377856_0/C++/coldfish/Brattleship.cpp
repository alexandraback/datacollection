#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
int r, c, w;

int solved(int left, int right, int width){
	if (right - left < width)
		return 0;

	return solved(left, (left + right) / 2, width) + solved((left + right) / 2 + 1, right, width)+1;
}
void main()
{
	FILE *fs = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");

	int testcase;
	fscanf(fs, "%d", &testcase);

	for (int t = 0; t < testcase; t++)
	{
		fprintf(fp, "Case #%d:", t + 1);
		int ans = 0;
		fscanf(fs, "%d %d %d", &r, &c, &w);

	//	ans = solved(1, c, w);
	//	fprintf(fp, " %d\n", ans*(r - 1) + ans + w);

		if (c == w)
			fprintf(fp, " %d\n", w);
		else if (c == w + 1 || c / w == 1)
			fprintf(fp, " %d\n", w+1);
		else fprintf(fp, " %d\n", (c / w) + w - 1);
	}
	fclose(fs);
	fclose(fp);
}