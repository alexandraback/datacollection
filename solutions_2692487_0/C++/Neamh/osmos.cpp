#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

FILE* fout;

int res[100 + 1][1000000 + 1];
int dV[100 + 1][1000000 + 1] = {0};
vector <int> motesSC;
int curT, nbMotos;

int trouveRes(int tailleMote, int nbMotSup, int idDerAMang)
{
	//fprintf(fout, "tM : %d, nbMS : %d, idDerM : %d\n", tailleMote, nbMotSup, idDerAMang);
	if(motesSC[motesSC.size() - nbMotSup - 1] < tailleMote)
	{
		//fprintf(fout, "stop\n");
		return 0;
	}
	if(idDerAMang > nbMotos)
	{
		//fprintf(fout, "2stop\n");
		return 0;
	}
	if(dV[nbMotSup][tailleMote] == curT)
	{
		//fprintf(fout, "3stop\n");
		return res[nbMotSup][tailleMote];
	}

	dV[nbMotSup][tailleMote] = curT;

	res[nbMotSup][tailleMote] = trouveRes(tailleMote, nbMotSup + 1, idDerAMang) + 1;

	int nouvTaille = tailleMote * 2 - 1;
	while(idDerAMang < motesSC.size() && motesSC[idDerAMang] < nouvTaille)
	{
		nouvTaille += motesSC[idDerAMang];
		idDerAMang++;
		//fprintf(fout, "\t%d %d\n", nouvTaille, idDerAMang);
	}
	if(nouvTaille != tailleMote)
		res[nbMotSup][tailleMote] = min(res[nbMotSup][tailleMote], trouveRes(nouvTaille, nbMotSup, idDerAMang) + 1);
	return res[nbMotSup][tailleMote];
}

int main()
{
    FILE *fin  = fopen ("osmos.in", "r");
    fout = fopen ("osmos.out", "w");

    int nbTests;
    fscanf(fin, "%d", &nbTests);
    for(curT = 1; curT <= nbTests; curT++)
    {
    	int tailleDep;
    	fscanf(fin, "%d%d", &tailleDep, &nbMotos);
    	int poids;
    	for(int curM = 0; curM < nbMotos; curM++)
    	{
    		fscanf(fin, "%d", &poids);
    		motesSC.push_back(poids);
    	}
    	motesSC.push_back(-1);
    	sort(motesSC.begin(), motesSC.end());
    	int idDerAMang = 1;
    	while(idDerAMang < motesSC.size() && motesSC[idDerAMang] < tailleDep)
    	{
    		tailleDep += motesSC[idDerAMang];
    		idDerAMang++;
    		//fprintf(fout, "\t%d %d\n", tailleDep, idDerAMang);
    	}
    	int meillRes = 200;
    	for(int nbS = 0; nbS <= nbMotos; nbS++)
    		meillRes = min(meillRes, trouveRes(tailleDep, nbS, idDerAMang) + nbS);
    	fprintf(fout, "Case #%d: %d\n", curT, meillRes);
    	motesSC.clear();
    }
    return 0;
}
