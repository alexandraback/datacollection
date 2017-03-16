#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int brojZadataka = 0, i, j;
	//char ulaz[128];
	int A, B;
	double * polje = NULL;
	FILE *in, *out;
	double temp, rez, rezTemp;

	in = fopen("A-small-0.in", "r");
	if (in == NULL) {
		printf("Greska prilikom otvaranja ulazne datoteke!\n");
		return 1;
	}

	out = fopen("A-small-0.out", "w");
	if (out == NULL) {
		printf("Greska prilikom otvaranja izlazne datoteke!\n");
		return 1;
	}

	fscanf(in, "%d\n", &brojZadataka);

	for (i = 1; i <= brojZadataka; i++) {
		//if (fgets(ulaz, sizeof(ulaz), in) == NULL); // onda je greska
		fprintf(out, "Case #%i: ", i);

		fscanf(in, "%d %d\n", &A, &B);
		polje = (double *) realloc( polje, A * sizeof(double) );

		for (j = 0; j < A - 1; j++) {
			fscanf(in, "%lf ", &polje[j]);
		}
		fscanf(in, "%lf\n", &polje[A - 1]);

		// if I press enter right away
		rez = B + 2; // gornja granica

		temp = 1;
		for (j = 0; j < A; j++) {
			temp *= polje[j];

			rezTemp = temp * (A-1-j +B-j);
			rezTemp += (1-temp) * (A-1-j +B-j + B+1);

			if (rezTemp < rez) rez = rezTemp;
		}

		fprintf(out, "%1.6lf", rez);

		/*for (j = 0; ulaz[j] != 0; j++) {
			fprintf(out, "%c", "a");
		}*/
		fprintf(out, "\n");
	}

	free(polje);
	fclose(in);
	fclose(out);

	return 0;
}
