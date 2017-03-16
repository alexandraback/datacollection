#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

long long *FairSQ;
int FCount;

int palin_test(long long x)
{
        char numb[20];
        int i;
        int str_len;
        int str_len2;

        sprintf(numb, "%lld", x);
        str_len = strlen(numb);
        str_len2 = str_len/2;

        for (i = 0; i < str_len2; i++)
                if (numb[i] != numb[str_len-1-i])
                        return 0;
        return 1;
}

void palin_gen(int digit)
{
	int limits[9]={1,10,100,1000,10000,100000,1000000,10000000, 100000000};
	int i, j, k, m, n;
	int lim1, lim2;
	long long palin;
	long long palin_sq;
	char plain_st[20];
	char part[10];
	int digit2;

	FCount = 0;
	FairSQ = NULL;

	for (i = 1; i < 10; i++) {
		palin_sq = i*i;
		if (palin_test(palin_sq)) {
			FairSQ = (long long*)realloc(FairSQ, sizeof(long long)*(FCount+1));
			if (FairSQ == NULL)
				exit(1);
			FairSQ[FCount] = palin_sq;
			FCount++;
		}
	}

	for (i = 2; i <= digit; i++) {
		digit2 = i/2;
		lim1 = limits[digit2-1];
		lim2 = limits[digit2];
		if (i%2) {
			for (j = lim1; j < lim2; j++) {
				sprintf(part, "%d", j);
				for (n = 0; n < 10; n++) {
					for (k = 0; k < digit2; k++)
						plain_st[k] = part[k];
					plain_st[k] = '0'+n;
					for (k = digit2-1, m=1; k >= 0; k--, m++)
						plain_st[digit2+m] = part[k];
					plain_st[digit2+m] = '\0';
					sscanf(plain_st, "%lld ", &palin);
					palin_sq = palin*palin;
					if (palin_test(palin_sq)) {
						FairSQ = (long long*)realloc(FairSQ, sizeof(long long)*(FCount+1));
						if (FairSQ == NULL)
							exit(1);
						FairSQ[FCount] = palin_sq;
						FCount++;
					}
				}
			}
		}
		else {
			for (j = lim1; j < lim2; j++) {
				sprintf(part, "%d", j);
					for (k = 0; k < digit2; k++)
						plain_st[k] = part[k];
					for (k = digit2-1, m=0; k >= 0; k--, m++)
						plain_st[digit2+m] = part[k];
					plain_st[digit2+m] = '\0';
					sscanf(plain_st, "%lld ", &palin);
					palin_sq = palin*palin;
					if (palin_test(palin_sq)) {
						FairSQ = (long long*)realloc(FairSQ, sizeof(long long)*(FCount+1));
						if (FairSQ == NULL)
							exit(1);
						FairSQ[FCount] = palin_sq;
						FCount++;
					}
			}
		}
	}
}
	

int main(int argc, char **argv)
{
	FILE *fp_in, *fp_out;
	int T;
	long long A, B;
	int i;
	int k;
	int dl, ul;

	fp_in = fopen(argv[1], "r");
	if (fp_in == NULL) {
		perror(argv[1]);
		exit(1);
	}

	fp_out = fopen(argv[2], "w");
	if (fp_out == NULL) {
		perror(argv[2]);
		exit(1);
	}

	fscanf(fp_in, "%d ", &T);

	palin_gen(8);
	for (i = 0; i < T; i++) {
		fscanf(fp_in, "%lld %lld ", &A, &B);
		for (k = 0; k < FCount; k++)
			if (FairSQ[k] >= A) {
				break;
			}
		dl = k;
		for (k = FCount-1; k >= dl; k--) {
			if (FairSQ[k] <= B) {
				break;
			}
		}
		ul = k;
		
		fprintf(fp_out, "Case #%d: %d\n", i+1, ul-dl+1);
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
