#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int T, N, M;

vector<int> graph[1005];
queue<int> tbv;

int num[1005];
bool visit[1005];

int main()
{
	
	scanf("%d ", &T);

	for(int cas=1;cas<=T;cas++){
		
		for(int i=0;i<1005;i++) graph[i].clear();

		scanf("%d ", &N);
		for(int nod=1;nod<=N;nod++){
			scanf("%d ", &M);
			int nb;			
			for(int j=0;j<M;j++){
				scanf("%d ", &nb);
				graph[nod].push_back(nb);
			}
		}

		bool diamond = false;

		for(int nod=1;nod<=N;nod++){

			memset(visit,0,sizeof(visit));		
			
			while(!tbv.empty()) tbv.pop();

			tbv.push(nod);	
			visit[nod]=true;
			
			while(!tbv.empty()){

				int cur = tbv.front();
				tbv.pop();				

				for(int i=0;i<graph[cur].size();i++){
					int next = graph[cur].at(i);
					if(visit[next]){diamond=true;break;}
					visit[next] =true;
					tbv.push(next);
				}
			}

			if(diamond) break;

		}

		while(!tbv.empty()) tbv.pop();


		printf("Case #%d: ", cas);
		if(diamond) printf("Yes\n");	
		else printf("No\n");		
	}
	
	return 0;

}
