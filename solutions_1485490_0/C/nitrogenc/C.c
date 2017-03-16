#include <stdlib.h>
#include <stdio.h>

int min(int n1, int n2)
{
	if (n2 > n1)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}

int main(void)
{
	FILE *f_in, *f_out;
	if (!(f_in = fopen("C.in", "r")))
	{
		puts("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("C.out", "w");
	int b, i, j, n, t;
	int boxes_cycles, toys_cycles;
	unsigned long int p, tmp, tmp1, tmp1_i, tmp2, tmp2_i, tmp1_g, tmp2_g;
	unsigned long int boxes[100][2];
	unsigned long int toys[100][2];
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		printf("Case #%d -> Starting..\n", i+1);
		fprintf(f_out, "Case #%d: ", i+1);
		fscanf(f_in, "%d %d", &boxes_cycles, &toys_cycles);
		for(j = 0; j < boxes_cycles; j++)
			fscanf(f_in, "%lu %lu", &boxes[j][0], &boxes[j][1]);
		for(j = 0; j < toys_cycles; j++)
			fscanf(f_in, "%lu %lu", &toys[j][0], &toys[j][1]);
		b = 0;
		t = 0;
		p = 0;
		printf("Cycle started...\n");
		while (b < boxes_cycles && t < toys_cycles)
		{
			if (boxes[b][1] == toys[t][1])
			{
				//les boîtes correspondent aux jouets : faisons des paquets.
				tmp = min(boxes[b][0], toys[t][0]);
				boxes[b][0] -= tmp;
				toys[t][0] -= tmp;
				printf("%lu nouveaux cadeaux pour les enfants !\n", tmp);
				p += tmp;
				if (boxes[b][0] == 0) b++;
				if (toys[t][0] == 0) t++;
			}
			else
			{
				//On va déterminer l'élimination la moins coûteuse.
				tmp1 = 0;
				tmp1_i = b+1;
				tmp1_g = 0;
				for(j = b+1; j < boxes_cycles; j++)
				{
					if (boxes[j][1] != toys[t][1])
					{
						tmp1 += boxes[j][0];
						tmp1_i++;
					}
					else
					{
						tmp1_g = min(boxes[j][0], toys[t][0]);
						break;
					}
				}
				tmp2 = 0;
				tmp2_i = t+1;
				tmp2_g = 0;
				for(j = t+1; j < toys_cycles; j++)
				{
					if (toys[j][1] != boxes[b][1])
					{
						tmp2 += toys[j][0];
						tmp2_i = j;
					}
					else
					{
						tmp2_g = min(boxes[b][0], toys[j][0]);
						break;
					}
				}
				if (tmp1-tmp1_g < tmp2-tmp2_g)
				{
					printf("On sacrifie des boites !\n");
					b = tmp1_i;
				}
				else
				{
					printf("On sacrifie des jouets !\n");
					t = tmp2_i;
				}
			}
		}
		printf("Case #%d -> %lu\n", i+1, p);
		fprintf(f_out, "%lu\n", p);
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
