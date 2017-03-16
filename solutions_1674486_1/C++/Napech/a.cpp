#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <complex>
#include <cstdio>

using namespace std;

vector < vector < int > > adj;
vector < bool > visit;

bool dfs(int start)
{
    bool tmp;
    int i;
    visit[start] = true;
    for(i = 0; i<adj[start].size(); i++)
    {
	if(visit[adj[start][i]] == true)
	    return true;
	else
	{
	    if(dfs(adj[start][i]))
		return true;
	}
    }
    return false;
}


int
main (void)
{
    int step, nb_step;
    cin >> nb_step;
    for(step = 0; step < nb_step; step++)
    {
	fprintf(stdout, "Case #%d: ", step+1);
	int N, i, j;
	cin >> N;
	adj.resize(N, vector < int > (0));
	visit.resize(N, false);
	for(i = 0; i<N; i++)
	{
	    int nb_voisins;
	    cin >> nb_voisins;
	    for(j = 0; j<nb_voisins; j++)
	    {
		int tmp;
		cin >> tmp;
		tmp--;

		adj[i].push_back(tmp);
	    }

	}
	
	// for(i = 0; i<N; i++)
	// {
	//     cout << i << " ";
	//     for(j=0; j<adj[i].size(); j++)
	// 	printf("%d,", adj[i][j]);
	//     cout << endl;
	// }

	bool diamond = false;
	for(i = 0; i<N; i++)
	{
	    // for(j = 0; j<N; j++)
	    // {
	    // 	printf("%d : %d\n", i, visit[i] == false ? 0 : 1);
		
	    // }
	    // cout << endl;
	    visit.resize(N, false);
	    if(dfs(i) == true)
	    {
//1		printf("-->%d\n", i);
		diamond = true;
		visit.resize(0);
		break;
	    }
	    visit.resize(0);
	}
	if(diamond)
	    printf("Yes\n");
	else
	    printf("No\n");
		
	adj.resize(0);

    }

    return 0;
}
