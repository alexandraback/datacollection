#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
		return 0;
	FILE *fp = fopen(argv[1], "r");
	FILE *ofp = fopen(argv[2], "w");

	int ncase;
	fscanf(fp, "%d\n", &ncase);
	for(int i = 1; i <= ncase; i++)
	{
		int n_googler;
		int n_triplet;
		int n_point;
		fscanf(fp, "%d %d %d", &n_googler, &n_triplet, &n_point);

		int count = 0;
		int cnt3n_2 = 0;

		if(n_point == 0)
		{
			for(int j = 0; j < n_googler; j++)
			{
				int score;
				fscanf(fp, "%d", &score);
			}
			count = n_googler;
		}
		else if(n_point == 1)
		{
			for(int j = 0; j < n_googler; j++)
			{
				int score;
				fscanf(fp, "%d", &score);
				if(score > 0)
					count++;
			}
		}
		else
		{
			int reference = 3 * n_point - 2;
			int r1 = reference - 1;
			int r2 = reference - 2;

			for(int j = 0; j < n_googler; j++)
			{
				int score;
				fscanf(fp, "%d", &score);
				if(score >= reference)
					count++;
				else if(score == r1 || score == r2)
					cnt3n_2++;
			}
			if(cnt3n_2 >= n_triplet)
				count += n_triplet;
			else
				count += cnt3n_2;
		}
		fprintf(ofp, "Case #%d: %d\n", i, count);
	}

	fclose(fp);
	fclose(ofp);
	return 0;
}

