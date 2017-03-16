#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BLOCK	1000




int d_war(double naomi_block[], double ken_block[], int num_block)
{
	int i,j;
	int naomi_win = 0;
	for (i = 0, j = 0; i < num_block; i++) {
		if (ken_block[j] < naomi_block[i]) {
			j++;
			naomi_win++;
		}
	}

	return naomi_win;
}

int war(double naomi_block[], double ken_block[], int num_block)
{
	int i, j;
	int naomi_win = 0;

	for (i = 0; i < num_block; i++) {
		for(j = 0; j < num_block; j++) {
			if (naomi_block[i] < ken_block[j]) {
				ken_block[j] = 0;
				break;
			}
		}

		if (j == num_block) {
			for(j = 0; j < num_block; j++) {
				if (ken_block[j] != 0) {
					ken_block[j] = 0;
					naomi_win++;
				}
			}
		}
	}

	return naomi_win;
}

int cmpfunc (const void * a, const void * b)
{
	   return ( (*(double*)a - *(double*)b) > 0 ? 1 : -1 );
}

int main(void)
{
	int num_set;
	int case_num;
	int num_block;
	double naomi_block[MAX_BLOCK];
	double ken_block[MAX_BLOCK];
	int i;	
	int ret_dwar, ret_war;
	scanf("%d", &num_set);
	for (case_num = 1; case_num <= num_set; case_num++) {
		scanf("%d", &num_block);
		for (i = 0; i < num_block; i++) {
			scanf("%lf", &naomi_block[i]);
		}
		for (i = 0; i < num_block; i++) {
			scanf("%lf", &ken_block[i]);
		}

		// sort blocks
		qsort(naomi_block, num_block, sizeof(double), cmpfunc);
		qsort(ken_block, num_block, sizeof(double), cmpfunc);

		//printf("naomi sort ");
		for (i = 0; i < num_block; i++) {
			//printf("%lf ", naomi_block[i]);
		}
		//printf("\n");
		//printf("ken   sort ");
		for (i = 0; i < num_block; i++) {
			//printf("%lf ", ken_block[i]);
		}
		//printf("\n");
		// deceitfull war game
		ret_dwar = d_war(naomi_block, ken_block, num_block);

		// war game
		ret_war = war(naomi_block, ken_block, num_block);
		
		printf("Case #%d: %d %d\n", case_num, ret_dwar, ret_war);
	}


}
