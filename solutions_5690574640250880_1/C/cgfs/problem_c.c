#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include <ctype.h>

#define MAX_R 50
#define MAX_C 50
#define M	1
#define E	2
#define E0	3
#define ES	4
#define C	5

void printcell(int cell_type)
{
	switch (cell_type)
	{
		case M:
			printf("*");
			break;
		case E:
			printf(".");
			break;
		case E0:
			//			printf(".");
			break;
		case ES:
			//			printf(".");
			break;
		case C:
			printf("c");
			break;
	}
}

void printcells(int r, int c, char cell[][MAX_C])
{
	int i,j;
	int m = 0;
	for (i = 0; i < r; i++) {
		for ( j = 0; j < c; j++) {
			if( cell[i][j] == M)
				m++;
			printcell(cell[i][j]);
		}
		printf("\n");
	}
	//printf("%d %d %d\n", r, c, m);
}

int main(void)
{
	int num_set;
	int case_num;
	int r, c, m;
	int i,j,k,jj,kk;
	int es, e0, e;
	char cell[MAX_R][MAX_C];
	scanf("%d", &num_set);
	//	printf("num of set %d\n\n", num_set);

	for (case_num = 1; case_num <= num_set ; case_num++) {
		memset(cell, 0, MAX_R * MAX_C);
		es = 0;
		e0 = 0;
		e = 0; 
		scanf("%d %d %d", &r, &c, &m);
		printf("Case #%d:\n", case_num);
		//		printf("%d x %d  mine: %d\n", r, c ,m);

		e = r * c - m;

		// one line cells
		if (r == 1 || c == 1) {
			//			printf("Possible\n");
			if ( r == 1) {
				for (i = 0; i < c ; i++) {
					if (i < m)
						cell[0][i] = M;
					else
						cell[0][i] = E;
				}
				cell[0][c-1] = C;
			} else if (c == 1) {
				for (i = 0; i < r ; i++) {
					if (i < m)
						cell[i][0] = M;
					else
						cell[i][0] = E;
				}
				cell[r-1][0] = C;
			}
			printcells(r, c, cell);
			continue;
		}

		if ( e == 2 || e == 3 || e == 5 || e == 7) {
			printf("Impossible\n");
			continue;
		}

		if ( e == 1 ) {
			//	printf("Possible\n");
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++) {
					cell[j][k] = M;
				}
			}
			cell[r-1][c-1] = C;
			printcells(r, c, cell);
			continue;
		}

		//else all possible

		//printf("Possible\n");
		// check all cells to M
		for (j = 0; j < r; j++) {
			for (k = 0; k < c; k++) {
				cell[j][k] = M;
			}
		}
		// set block
		for (j = 1, k = 1; j < r && k < c ; ) {
			/*
			if ((r-(j+1)) > (c-(k+1))) 
				j++;
			else 
				k++;
			*/
			if ((j+1) * (k+1) >= e)
				break;	
			if ((j +1) < r)
				j++;

			if ((j+1) * (k+1) >= e)
				break;	
			if ((k +1) < c)
				k++;
		}
//		printf("block %d x %d e %d r %d c %d\n", j, k, e, r, c);

		// check small box cells to E
		for (jj =0; jj <= j; jj++) {
			for (kk = 0; kk <= k; kk++) {
				//printf("set E to  jj %d kk %d e %d\n", jj, kk, e);
				cell[jj][kk] = E;
			}
		}
		i = (j+1) * (k+1);
		//printf("r %d c %d j %d k %d e %d\n", r, c, j, k, e);
		for(kk = k; j >= 2; j-- ) {
			for(k = kk; k >= 2; k--) {
				if ( i > e ) {
					//printf("set M to r %d c %d j %d k %d e %d i %d\n", r, c, j, k, e, i);
					cell[j][k] = M;
					i--;
				} else {
					//printf("goto OUT\n");
					goto PRINTCELL;
				}
			}
		}
		if ( (i - e) % 2) {
			printf("Impossible\n");
			goto OUT;
		} else {
			if ( i == e )
				goto PRINTCELL;

			for ( j = r-1; j > 1; j -= 1) {
				//printf("set M to r %d c %d j %d k 0 1 e %d i %d\n", r, c, j, e, i);
				cell[j][0] = M;
				cell[j][1] = M;
				i -= 2;
				if ( i == e )
					goto PRINTCELL;
			}
			for ( k = c-1; k > 1; k -= 1) {
				//printf("set M to r %d c %d j 0 1  k %d e %d i %d\n", r, c, k, e, i);
				cell[0][k] = M;
				cell[1][k] = M;
				i -= 2;
				if ( i == e )
					goto PRINTCELL;
			}
			if ( i == e )
				goto PRINTCELL;
			//printf("Somthing Wrong !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

		}

PRINTCELL:
		cell[0][0] = C;
		printcells(r, c, cell);
		continue;
OUT:
		continue;


	}
	return 0;
	}
