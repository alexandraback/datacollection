/*
 * main.c
 *
 *  Created on: 8 janv. 2011
 *      Author: dessoul
 */

#include "malloc.h"
#include "string.h"
#include "time.h"
#include "pthread.h"
#include "math.h"
#include "assert.h"
#include "stdio.h"


int analyse (long long p , long long q, short profondeur)
{
	if(p > q || profondeur > 40)
	{
		return 0-1 ;
	}

	if(p == q)
	{
		return profondeur ;
	}

	if(2 * p < q)
	{
		if(q % 2 != 0)
		{
			return 0-1 ;
		} else
		{
			return analyse (p , q / 2, profondeur + 1) ;
		}
	} else if (2 * p == q)
	{
		return profondeur + 1 ;
	} else
	{
		if(analyse (2 * p - q , q , profondeur + 1) >= 0)
		{
			return profondeur + 1 ;
		} else
		{
			return 0-1 ;
		}
	}
	/*{
		return profondeur + 1 ;
	}*/

	return 0-1 ;
}

int main(void) {
	FILE* f1 = NULL;
	FILE* f2 = NULL;

	f2 = fopen("output.txt", "w");
	//f2 = fopen("/home/dessoul/Documents/Programmation/C-C++/Facebook Hacker Cup, Peg Game/Debug/output.txt", "w");
	assert(f2 != NULL);
	//fclose(f2);

	f1 = fopen("input.txt", "r");
	//f1 = fopen("/home/dessoul/Documents/Programmation/C-C++/Facebook Hacker Cup, Peg Game/Debug/input.txt", "r");
	assert(f1!=NULL);

	int T;
	fscanf(f1, "%d\n", &T);

	printf("T: %d\n", T);

	//int i, j;
	//int R, C, K, M;
	//int* coord1;
	//int* coord2;
	//int col;
	//double proba;
	short i;
	//short ii ;
	//short n ;
	//char* s = malloc(105 * sizeof(char));
	//char** tab = malloc(105 * sizeof(char*));
	 /*char res;
	 char* resultat = malloc(4 * sizeof(char));*/
	long long p ;
	long long q ;

	 // int resultat_temp ;
	 int resultat ;

	// double c, f, x ;
	/*short conf11, conf12, conf13, conf14 ;
	 short conf21, conf22, conf23, conf24 ;
	 short conf31, conf32, conf33, conf34 ;
	 short conf41, conf42, conf43, conf44 ;*/

	for (i = 0; i < T; i++) {
		//fscanf(f1, "%lf %lf %lf\n", &c, &f, &x);
		fscanf(f1, "%lli/%lli\n", &p, &q);

		/*resultat = 0 ;
		for(ii = 1 ; ii < n && resultat >= 0 ; ii++)
				{
			resultat_temp = analyse(tab[0],tab[ii]) ;
			if(resultat_temp < 0)
			{
				resultat = 0-1 ;
			} else
			{
				resultat += resultat_temp ;
			}
				}*/

		resultat = analyse (p , q, 0) ;

		if(resultat >= 0)
		{
					fprintf(f2, "Case #%hd: %i\n", i + 1, resultat);
		} else
		{
			fprintf(f2, "Case #%hd: impossible\n", i + 1);
		}


		printf("Ligne %hd : %i\n", i + 1, resultat);
	}

	//free(s);
	//free(resultat);


	fclose(f1);
	fclose(f2);

	return 1;
}
