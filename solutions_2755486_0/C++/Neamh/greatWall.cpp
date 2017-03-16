#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

FILE* fout;
FILE *fin2;

struct Attaque
{
	int deb;
	int fin;
	int date;
	int force;

	Attaque() {}
	Attaque(int uD, int uF, int uDa, int uFo) : deb(uD), fin(uF), date(uDa), force(uFo){}

	bool operator < (const Attaque& autre) const
	{
		return date > autre.date;
	}
};

void trouveSol(int curT)
{
	int hauteur[800 + 2] = {0};
	int nbTribus;
	int nbAttReussies = 0;
	priority_queue <Attaque> attaques;
	fscanf(fin2, "%d", &nbTribus);
	for(int curTr = 0; curTr < nbTribus; curTr++)
	{
		int date, nbA, deb, fin, force;
		int distTps, distEsp, distForce;
		fscanf(fin2, "%d%d%d%d", &date, &nbA, &deb, &fin);
		fscanf(fin2, "%d%d%d%d", &force, &distTps, &distEsp, &distForce);
		for(int curA = 0; curA < nbA; curA++)
		{
			attaques.push(Attaque(deb + distEsp * curA + 200, fin + distEsp * curA + 200, date + distTps * curA, force + distForce * curA));
		}
	}

	int curH[800 + 2] = {0};
	int datePrec = -1;

	while(!attaques.empty())
	{
		Attaque curA = attaques.top();
		attaques.pop();
		//fprintf(fout, "date : %d\n", curA.date);
		if(curA.date != datePrec)
		{
			datePrec = curA.date;
			for(int x = 0; x < 800; x++)
			{
				hauteur[x] = max(hauteur[x], curH[x]);
				curH[x] = 0;
			}
		}
		bool reussi = false;
		for(int x = curA.deb * 2; x <= curA.fin * 2; x++)
		{
			if(hauteur[x] < curA.force)
				reussi = true;
			curH[x] = max(curH[x], curA.force);
		}
		if(reussi == true)
		{
			//fprintf(fout, "reussi\n");
			nbAttReussies++;
		}
	}

	fprintf(fout, "Case #%d: %d\n", curT, nbAttReussies);
}

int main()
{
    fin2 = fopen ("great.in", "r");
    fout = fopen ("great.out", "w");

    int nbTests;
    fscanf(fin2, "%d", &nbTests);
    /*priority_queue <Attaque>attaques;
    attaques.push(Attaque(2, 3, 4, 5));
    attaques.push(Attaque(2, 3, 6, 5));
    printf("%d", attaques.top().date);*/
    for(int curT = 1; curT <= nbTests; curT++)
    	trouveSol(curT);
    return 0;
}
