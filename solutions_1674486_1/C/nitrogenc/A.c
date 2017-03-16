#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE *f_in, *f_out;
	if (!(f_in = fopen("A.in", "r")))
	{
		puts("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("A.out", "w");
	int cpt, i, j, k, l, n, nb, num, res;
	int cl[1000][11];
	int list[10000];
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 1000; j++)
			for(k = 0; k < 11; k++)
				cl[j][k] = 0;
		fprintf(f_out, "Case #%d: ", i+1);
		fscanf(f_in, "%d", &nb);
		for(j = 0; j < nb; j++)
		{
			fscanf(f_in, "%d", &cl[j][0]);
			for(k = 0; k < cl[j][0]; k++)
				fscanf(f_in, "%d", &cl[j][k+1]);
		}
		res = 0;
		printf("Starting case #%d...\n", i+1);
		for(j = 0; j < nb && res == 0; j++)
		{
			for(k = 0; k < 10000; k++)
				list[k] = 0;
			//printf("Starting from class %d...\n", j+1);
			num = cl[j][0];
			for(k = 0; k < cl[j][0]; k++)
				list[k] = cl[j][k+1];
			//printf("Starting recursive assignment...\n");
			cpt = 0;
			while(cpt < num && num < 10000)
			{
				for(k = 0; k < cl[list[cpt]-1][0]; k++)
					list[num+k] = cl[list[cpt]-1][k+1];
				num += cl[list[cpt]-1][0];
				//printf("Total elements: %d\n", num);
				cpt++;
			}
			//printf("Detecting diamond structure for case #%d among %d elements...\n", i+1, num);
			//Une fois qu'on a fini, on cherche deux éléments égaux dans la liste.
			for(k = 0; k < num-1 && res == 0; k++)
				for(l = k+1; l < num && res == 0; l++)
					if (list[k] == list[l])
						res = 1;
		}
		if (res == 0)
		{
			fprintf(f_out, "No\n");
		}
		else
		{
			fprintf(f_out, "Yes\n");
		}
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
