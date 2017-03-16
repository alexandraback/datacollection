#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

bool visited[1048576];
int K, N;
vector<int> firstkeys;
int key[20];
vector<int> dedans[20];

queue<pair<int, pair<vector<int>, vector<int> > > > q; // (situation, (chemin, possession))


int main()
{
	int i, j, T, t;
	int k;
	int M;
	int a;
	vector<int> vide;
	pair<int,pair<vector<int>,vector<int> > > s;
	vector<int> possession, chemin, newpossession, newchemin, cheminfinal;
	int situation, newsituation;
	vector<int>::iterator it;
	
	scanf("%d", &T);
	
	int powtwo[20];
	
	for(i = 0; i < 20; i++)
	{
		powtwo[i] = 1 << i;
	}
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		while(!q.empty()) q.pop();
		scanf("%d %d", &K, &N);
		M = 1 << N;
		for(i = 0; i < M; i++)
		{
			visited[i] = false;
		}
		firstkeys.resize(0);
		for(i = 0; i < K; i++)
		{
			scanf("%d", &k);
			firstkeys.push_back(k);
		}
		for(i = 0; i < N; i++)
		{
			dedans[i].resize(0);
			scanf("%d", &key[i]);
			scanf("%d", &k);
			for(j = 0; j < k; j++)
			{
				scanf("%d", &a);
				dedans[i].push_back(a);
			}
		}
		
		q.push(make_pair(0, make_pair(vide, firstkeys)));
		visited[0] = true;
		
		while(!visited[M-1] && !q.empty())
		{
			s = q.front();
			q.pop();
			situation = s.first;
			possession = s.second.second;
			chemin = s.second.first;
			for(i = 0; i < N; i++)
			{
				if(!(powtwo[i] & situation) && find(possession.begin(), possession.end(), key[i]) != possession.end())
				{
					newsituation = situation + powtwo[i];
					if(!visited[newsituation])
					{
						visited[newsituation] = true;
						newchemin = chemin;
						newchemin.push_back(i+1);
						newpossession = possession;
						for(j = 0; j < dedans[i].size(); j++)
						{
							newpossession.push_back(dedans[i][j]);
						}
						it = find(newpossession.begin(), newpossession.end(), key[i]);
						newpossession.erase(it);
						q.push(make_pair(newsituation, make_pair(newchemin, newpossession)));
						if(newsituation == M-1) cheminfinal = newchemin;
					}
				}
			}
		}
		
		if(visited[M-1])
		{
			for(i = 0; i < cheminfinal.size(); i++)
			{
				if(i) printf(" ");
				printf("%d", cheminfinal[i]);
			}
			printf("\n");
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
		
	}

	return 0;
}
