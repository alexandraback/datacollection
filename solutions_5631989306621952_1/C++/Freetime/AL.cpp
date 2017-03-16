#include <stdio.h>

int main()
{
	FILE *fp_r, *fp_w;
	fp_r = fopen("A-large.in", "r");
	fp_w = fopen("AL_output.txt", "w");

	int ii, test, l, r, i;
	char list[2500], c;

	fscanf(fp_r, "%d", &test);
	fscanf(fp_r, "%c", &c);
	for (ii = 1;ii <= test;ii++)
	{
		fprintf(fp_w, "Case #%d: ", ii);
		l = 1300;
		r = 1300;
		for (i = 0;i < 2500;i++)
			list[i] = NULL;
		while (1)
		{
			if (fscanf(fp_r, "%c", &c)<1)
				break;
			if (c == '\n' || c == EOF)
				break;
			if ((l == 1300 && r == 1300) || (int)list[l] <= (int)c)
				list[--l] = c;
			else
				list[r++] = c;
		}
		for (i = l;i < r;i++)
			fprintf(fp_w, "%c", list[i]);
		fprintf(fp_w, "\n");
	}

	fclose(fp_r);
	fclose(fp_w);
	return 0;
}