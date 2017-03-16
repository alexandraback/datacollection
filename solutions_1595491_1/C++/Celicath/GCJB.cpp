#include<stdio.h>

int main()
{
	int nreq[11] = {0,1,4,7,10,13,16,19,22,25,28};
	int req[11] = {0,1,2,5,8,11,14,17,20,23,26};

	int T;

	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt","w");

	fscanf(fin, "%d", &T);

	int N, S, P, nrmax, rmax, tmp;

	for(int i = 1; i <= T; i++)
	{
		nrmax = rmax = 0;
		fscanf(fin, "%d%d%d", &N, &S, &P);

		while(N --> 0)
		{
			fscanf(fin, "%d", &tmp);
			if(tmp >= nreq[P]) nrmax++;
			else if(tmp >= req[P]) rmax++;
		}
		int result = nrmax + (rmax > S ? S : rmax);
		fprintf(fout,"Case #%d: %d\n", i, result);
	}

	return 0;
}