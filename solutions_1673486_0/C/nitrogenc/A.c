#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE *f_in, *f_out;
	int i, j, k, n;
	int a, b, cf;
	float flo;
	int car, ent, val;
	int kpt[6][9];
	int ftab[3];
	if (!(f_in = fopen("A.in", "r")))
	{
		puts("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("A.out", "w+");
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d: ", i+1);
		fscanf(f_in, "%d %d", &a, &b);
		printf("Parameters: %d, %d\n", a, b);
		for(j = 0; j < 9; j++)
			kpt[0][j] = 1;
		for(j = 0; j < 9; j++)
			for(k = 1; k < 6; k++)
				kpt[k][j] = 0;
		cf = 1;
		for(j = 0; j < a; j ++)
			cf *= 10;
		car = 0;	
		for(j = 0; j < a; j++)
		{
			fscanf(f_in, "%f", &flo);
			ftab[j] = (int) (10 * flo) + car;
			if (ftab[j] == 10 && car == 0)
			{
				car = 1;
			}
			else
			{
				car = 0;
			}
			printf("{%d}", ftab[j]);
		}
		printf("\n");
		switch(a)
		{
		case 1:
			kpt[0][0] *= ftab[0];
			kpt[0][1] *= (10-ftab[0]);
			break;
		case 2:
			kpt[0][0] *= ftab[0]*ftab[1];
			kpt[0][1] *= ftab[0]*(10-ftab[1]);
			kpt[0][2] *= (10-ftab[0])*ftab[1];
			kpt[0][3] *= (10-ftab[0])*(10-ftab[1]);
			break;
		case 3:
			kpt[0][0] *= ftab[0]*ftab[1]*ftab[2];
			kpt[0][1] *= ftab[0]*ftab[1]*(10-ftab[2]);
			kpt[0][2] *= ftab[0]*(10-ftab[1])*ftab[2];
			kpt[0][3] *= (10-ftab[0])*ftab[1]*ftab[2];
			kpt[0][4] *= ftab[0]*(10-ftab[1])*(10-ftab[2]);
			kpt[0][5] *= (10-ftab[0])*ftab[1]*(10-ftab[2]);
			kpt[0][6] *= (10-ftab[0])*(10-ftab[1])*ftab[2];
			kpt[0][7] *= (10-ftab[0])*(10-ftab[1])*(10-ftab[2]);
			break;
		}
		for(j = 0; j < (1<<a); j++)
		{
			printf("[%d]", kpt[0][j]);
		}
		printf("\n");
		//Toujours vrai.
		kpt[1][0] = b-a+1;
		kpt[2][0] = b-a+3;
		kpt[3][0] = b-a+5;
		kpt[4][0] = b-a+7;
		kpt[5][0] = b + 2;
		kpt[5][1] = b + 2;
		kpt[5][2] = b + 2;
		kpt[5][3] = b + 2;
		kpt[5][4] = b + 2;
		kpt[5][5] = b + 2;
		kpt[5][6] = b + 2;
		kpt[5][7] = b + 2;
		switch(a)
		{
		case 1:
			kpt[1][1] = 2*b + 1;
			kpt[2][1] = b + 2;
			break;
		case 2:
			kpt[1][1] = 2*b;
			kpt[2][1] = b + 1;
			kpt[3][1] = b + 3;
			kpt[1][2] = 2*b;
			kpt[2][2] = 2*b + 2;
			kpt[3][2] = b + 3;
			kpt[1][3] = 2*b;
			kpt[2][3] = 2*b + 2;
			kpt[3][3] = b + 3;
			break;
		case 3:
			kpt[1][1] = 2*b - 1;
			kpt[2][1] = b;
			kpt[3][1] = b + 2;
			kpt[4][1] = b + 4;
			
			kpt[1][2] = 2*b - 1;
			kpt[2][2] = 2*b + 1;
			kpt[3][2] = b + 2;
			kpt[4][2] = b + 4;
			
			kpt[1][3] = 2*b - 1;
			kpt[2][3] = 2*b + 1;
			kpt[3][3] = 2*b + 3;
			kpt[4][3] = b + 4;
			
			kpt[1][4] = 2*b - 1;
			kpt[2][4] = 2*b + 1;
			kpt[3][4] = b + 2;
			kpt[4][4] = b + 4;
			
			kpt[1][5] = 2*b - 1;
			kpt[2][5] = 2*b + 1;
			kpt[3][5] = 2*b + 3;
			kpt[4][5] = b + 4;
			
			kpt[1][6] = 2*b - 1;
			kpt[2][6] = 2*b + 1;
			kpt[3][6] = 2*b + 3;
			kpt[4][6] = b + 4;
			
			kpt[1][7] = 2*b - 1;
			kpt[2][7] = 2*b + 1;
			kpt[3][7] = 2*b + 3;
			kpt[4][7] = b + 4;
			break;
		}		
		//Calcul de la 8e colonne.
		val = 0;
		for(j = 1; j < 6; j++)
		{
			if (a == 3 || (a == 1 && j != 3 && j != 4) || (a == 2 && j != 4))
			{
				kpt[j][8] = 0;
				for(k = 0; k < (1<<a); k++)
					kpt[j][8] += kpt[j][k]*kpt[0][k];
				printf("<%d>", kpt[j][8]);
				if (val == 0 || kpt[j][8] < val)
					val = kpt[j][8];
			}
		}
		printf("\nMin value: %d\n", val);
		//On écrit le nombre.
		fprintf(f_out, "%.6f\n", (val * 1.0)/cf);
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
