#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
#include <limits.h>
using namespace std;

#define MAX_V 1005
#define MAX_DEGREE 15

struct graph{
	int edges[MAX_V][MAX_DEGREE];
	int degree[MAX_V];
};

bool discovered[MAX_V];
bool finished;
bool result;

void graphInit(graph *g){
	memset(g->degree, 0, sizeof(g->degree));
	memset(discovered, false, sizeof(discovered));

	finished = false;
	result = false;
}

// x to y (directed)
void graphInsert(graph *g, int x, int y, bool directed){
	g->edges[x][g->degree[x]] = y;
	g->degree[x]++;
	
	if(!directed){
		g->edges[y][g->degree[y]] = x;
		g->degree[y]++;
	}
}

bool BFS(graph *g, int start){
	queue<int> q;
	int neighbour;
	int v;
	
	q.push(start);
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		for(int i=0; i<g->degree[v]; i++){
			neighbour = g->edges[v][i];
		
			if(!discovered[neighbour]){
				q.push(neighbour);
				discovered[neighbour] = true;
			}else{
				result = true;
				finished = true;
				return result;
			}
		}
	}

	return false;
}

graph g;

int main(void){
	int T, u, M, N, vc, i, j, buffer;
	cin >> T;
	
	for(u=0; u<T; u++){
		cin >> N;

		graphInit(&g);
		i = 0;
		
		for(i=1; i<=N; i++){
			cin >> M;
			for(j=0; j<M; j++){
				cin >> buffer;
				graphInsert(&g, i, buffer, true);
			}
		}

		for(i=1; i<=N; i++){
			BFS(&g, i);
		
			if(finished){
				break;
			}
		
			memset(discovered, false, sizeof(discovered));
			finished = false;
			result = false;
		}
		
		cout << "Case #" << (u+1) << ": ";
		cout << (result?"Yes":"No") << endl;
	}
	
	return 0;
}
