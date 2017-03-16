#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
vector<int> voisins[1001];
int nbTests, nbNodes, nbVois;
bool dejaVus[1001];
bool diamond;


void DFS(int node)
{
	//printf("%d===>", node);
	if (dejaVus[node])
	{
		//printf("AAAAAAAAA %d", node);
		diamond = true;
		return;
	}

	dejaVus[node] = true;
	int truc = voisins[node].size();

	//printf("%d=====>", nbVois);
	for (int i = 0; i < truc; i++)
	{
		//printf("lalala%d = %d\n", i, voisins[node][i]);
		DFS(voisins[node][i]);
	}
}




int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d", &nbTests);
	int lu;

	for (int test = 1; test <= nbTests; test++)
	{
		printf("Case #%d: ", test);
		scanf("%d", &nbNodes);
		diamond = false;

		for (int i = 1; i <= nbNodes; i++)
		{
			scanf("%d", &nbVois);
			voisins[i].clear();

			for (int vois = 0; vois < nbVois; vois++)
			{
				scanf("%d", &lu);
				//printf("%d\n", lu);
				voisins[i].push_back(lu);
			}
		}

		for (int i = 1; i <= nbNodes; i++)
		{
			/*printf("Node = %d :", i);
			for (int j = 0; j < voisins[i].size(); j++)
				printf("%d   ", voisins[i][j]);
			printf("\n");*/
			for (int j = 1; j <= nbNodes; j++)
				dejaVus[j] = false;
			//printf("NOEUDDDDDDDDDDDDDDDDDDDDD %d:\n", i);
			DFS(i);
			//printf("\n\n\n");
		}

		if (diamond)
			printf("Yes\n");
		else
			printf("No\n");
	}





    return 0;
}
