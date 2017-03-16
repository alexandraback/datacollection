#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int MAX_NOEUDS = 51;
const int MAX_ARCS = 25*49;
const int MAX_TAILLE = 6;

int codes[MAX_NOEUDS];

struct Arc
{
	int dest;
	Arc(int dest = 0) : dest(dest) {}
	bool operator < (const Arc& droite) const
	{
		return codes[dest] < codes[droite.dest];
	}
};

int nbTests;
int nbNoeuds, nbArcs;
vector<Arc> graphe[MAX_NOEUDS];
int u, v;
int dejaVu[MAX_NOEUDS];

void dfs(int noeud, int tour)
{
	if(dejaVu[noeud] == tour)
		return;
	dejaVu[noeud] = tour;
	printf("%d", codes[noeud]);
	for(int iFils = 0; iFils < (int)graphe[noeud].size(); ++iFils)
		dfs(graphe[noeud][iFils].dest, tour);
}

void computeAnswer()
{
	for(int iTest = 1; iTest <= nbTests; ++iTest)
	{
		scanf("%d%d", &nbNoeuds, &nbArcs);
		for(int iNoeud = 1; iNoeud <= nbNoeuds; ++iNoeud)
		{
			scanf("%d", &codes[iNoeud]);
			graphe[iNoeud].clear();
		}
		for(int iArc = 0; iArc < nbArcs; ++iArc)
		{
			scanf("%d%d", &u, &v);
			graphe[u].push_back(Arc(v));
			graphe[v].push_back(Arc(u));
		}
		for(int iNoeud = 1; iNoeud <= nbNoeuds; ++iNoeud)
			sort(graphe[iNoeud].begin(), graphe[iNoeud].end());
		int mini = codes[1];
		int iMin = 1;
		for(int iNoeud = 2; iNoeud <= nbNoeuds; ++iNoeud)
		{
			if(mini > codes[iNoeud])
			{
				mini = codes[iNoeud];
				iMin = iNoeud;
			}
		}
		printf("Case #%d: ", iTest);
		dfs(iMin, iTest);
		printf("\n");
	}
}

void displayAnswer()
{

}

void readInput()
{
	/*
	freopen("test.in", "r", stdin);
	/*/
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	//*/
	scanf("%d", &nbTests);
}

int main()
{
	readInput();
	computeAnswer();
	displayAnswer();
	return 0;
}
