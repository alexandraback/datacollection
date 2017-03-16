#include <cstdio>
#include <iostream>

using namespace std;

FILE* fout;
FILE *fin;

int tab[1000000 + 3] = {0};

bool estConsonne(char carac)
{
	if(carac == 'a')
		return 0;
	if(carac == 'e')
		return 0;
	if(carac == 'i')
		return 0;
	if(carac == 'o')
		return 0;
	if(carac == 'u')
		return 0;
	return 1;
}

void trouveSol(int curT)
{
	int nbL, nbConsVoul;
	int nbSeq = 0;
	int idDebPrec = 0;

	fscanf(fin, "%d", &nbL);
	char carac;
	fscanf(fin, "%c", &carac);
	if(carac == '\n')
		fscanf(fin, "%c", &carac);
	//printf("n%cn\n", carac);
	tab[0] = 0;
	int curC = 0;
	while(carac != ' ')
	{
		tab[curC + 1] = tab[curC] + estConsonne(carac);
		curC++;
		fscanf(fin, "%c", &carac);
	}
	nbL = curC;
	fscanf(fin, "%d", &nbConsVoul);
	//printf("%d et %d\n", nbConsVoul, nbL);

	for(int curD = 1; curD + nbConsVoul - 1 <= nbL; curD++)
	{
		int nbCons = tab[curD + nbConsVoul - 1] - tab[curD - 1];
		//fprintf(fout, "deb : %d et fin : %d et nbCons : %d\n", curD, curD + nbConsVoul - 1, nbCons);
		if(nbCons == nbConsVoul)
		{
			int curR = (curD - idDebPrec) * (nbL - (curD + nbConsVoul - 1) + 1);
			nbSeq += curR;
			//fprintf(fout, "Ho : %d * %d\n", (curD - idDebPrec), (nbL + 1 - (curD + nbConsVoul - 1) + 1));
			idDebPrec = curD;
		}
	}
	fprintf(fout, "Case #%d: %d\n", curT, nbSeq);
}

int main()
{
    fin  = fopen ("names.in", "r");
    fout = fopen ("names.out", "w");

    int nbTests;
    fscanf(fin, "%d", &nbTests);
    for(int curT = 1; curT <= nbTests; curT++)
    	trouveSol(curT);
    return 0;
}
