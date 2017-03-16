#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE *f_in, *f_out;
	int i, j, n;
	int ranks[2][1000];
	int nb_lvl, nb_stars, nb_run, ind, val;
	if (!(f_in = fopen("B.in", "r")))
	{
		puts("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("B.out", "w+");
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d: ", i+1);
		fscanf(f_in, "%d", &nb_lvl);
		for(j = 0; j < nb_lvl; j++)
		{
			fscanf(f_in, "%d %d", &ranks[0][j], &ranks[1][j]);
		}
		//Boucle de parcours des degrés 2.
		nb_stars = 0;
		nb_run = 0;
loop:
		ind = -1;
		val = -1;
		for(j = 0; j < nb_lvl; j++)
		{
			if (ranks[1][j] <= nb_stars)
			{
				nb_run++;
				nb_stars++;
				if (ranks[0][j] != 6666)
				{
					nb_stars++;
					ranks[0][j] = 6666;
				}
				ranks[1][j] = 6666;
				goto loop;
				/*if (ranks[0][j] < val || val == -1)
				{
					ind = j;
					val = ranks[0][j];
				}*/
			}
		}
		ind = -1;
		val = -1;
		for(j = 0; j < nb_lvl; j++)
		{
			if (ranks[0][j] <= nb_stars)
			{
				if (ranks[1][j] > val || val == -1)
				{
					ind = j;
					val = ranks[1][j];
				}
			}
		}
		if (ind != -1)
		{
			nb_run++;
			nb_stars++;
			ranks[0][ind] = 6666;
			goto loop;
		}
		if (nb_stars != 2*nb_lvl)
		{
			fprintf(f_out, "Too Bad\n");
		}
		else
		{
			fprintf(f_out, "%d\n", nb_run);
		}
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
