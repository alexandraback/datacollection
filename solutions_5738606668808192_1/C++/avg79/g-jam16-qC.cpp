#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include "gmp.h"

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	if (argc > 1)
	{
		char tname[200];
		fin = fopen(argv[1],"r");
		strncpy (tname,argv[1],200);
		strncpy(strstr (tname,".in"),".out",4);
		fout = fopen(tname,"w");
	} else {
		fin = fopen("A.in","r");
		fout = fopen("A.out","w");
	}
	int nppr = 100000000;
	long long * pprime = new long long[nppr];
	pprime[0] = 2;
	int npr = 1;

	for (int j=3; j<1000000; j+=2)
	{
		mpz_t ppk;
		mpz_init_set_si(ppk,j);
		if (mpz_probab_prime_p (ppk, 10) != 0)
		{
			pprime[npr++] = j;
		}
	}

	int t;
	fscanf(fin,"%d",&t);

	for (int ti=0; ti<t; ti++)
	{
		fprintf(fout,"Case #%d:\n", ti+1);
		int n,ilim;
		fscanf(fin,"%d", &n);
		fscanf(fin,"%d", &ilim);
		int ifound = 0;
		mpz_t numb[9];
		for (int i=0; i<9; i++)
		{
			mpz_init (numb[i]);
		}
		long long fbin = (1LL<<(n-1))+1;
		long long ebin = 1LL<<n;
		for (long long  i=fbin; i<ebin; i+=2)
		{
			mpz_set_si(numb[0],i);

			if (mpz_probab_prime_p (numb[0],10) == 0)
			{
				for (int j=1; j<9; j++) mpz_set_si(numb[j],1);
				for (int p=1; p<n; p++)
				{
					for (int bj=1; bj<9; bj++) mpz_mul_si(numb[bj], numb[bj], bj+2);
					if ( (i&(1LL<<(n-p-1))) >0)
					{
						for (int bj=1; bj<9; bj++) mpz_add_ui(numb[bj], numb[bj], 1);
					}
				}
				bool allcomposite = true;
				for (int j=1; j<9; j++)
				{
					if (mpz_probab_prime_p (numb[j],10) != 0)
					{
						allcomposite = false;
						break;
					}
				}
				if (allcomposite)
				{
					for (int p=n-1; p>=0; p--)
					{
						if ( (i&(1LL<<p)) >0)
						{
							fprintf(fout,"1");
						} else {
							fprintf(fout,"0");
						}
					}
					for (int j=0; j<9; j++)
					{

/*
						char tstr[40];
						mpz_get_str (tstr, 10,  numb[j]);
						fprintf(fout,"   %s",tstr);*/
/*						mpz_get_str (tstr, j+2,  numb[j]);
					    fprintf(fout,"   %s  ",tstr);*/

						for (int pr=0; pr< npr; pr++)
						{
							if(mpz_divisible_ui_p(numb[j], pprime[pr]) != 0)
							{
								fprintf(fout," %lld", pprime[pr]);
								break;
							}
						}
					}
					fprintf(fout,"\n");
					ifound++;
					if(ifound == ilim) break;
				}
			}
		}

	}
	fclose(fin);
	fclose(fout);
	return 0;
}