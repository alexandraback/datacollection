#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
using namespace std;
#define MAXN 1010
vector<int> Adj[MAXN];
int N;
vector<int> rev[MAXN];
int inDegree[MAXN];
int paths[MAXN][MAXN];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int cases=1;cases<=T;cases++)
	{
		scanf("%d", &N);
		
		for(int i=1;i<=N;i++) {
			Adj[i].clear();
			rev[i].clear();
			inDegree[i] = 0;
		}
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) paths[i][j] = 0;
		
		for(int i=1;i<=N;i++)
		{
			int sz;
			scanf("%d", &sz);
			for(int j=0;j<sz;j++)
			{
				int v;
				scanf("%d", &v);
				Adj[i].push_back(v);
				rev[v].push_back(i);
				inDegree[i]++;
			}
		}
		// topo sort
		vector<int> Q;
		for(int i=1;i<=N;i++) if(inDegree[i] == 0) Q.push_back(i);
		int front = 0;
		while(front < Q.size())
		{
			int u = Q[front++];
			// cout << "AT node = " << u << endl;
			for(int i=0;i<rev[u].size();i++) {
				int v = rev[u][i];
				inDegree[v]--;
				if(inDegree[v] == 0) Q.push_back(v);
			}
		}
		// print
		assert((int)Q.size() == N);
		/*
		for(int i=0;i<N;i++) cout << Q[i] << " ";
		cout << endl;
		*/
		// check
		bool ok = 0;
		for(int i=0;i<N;i++)
		{
			int v = Q[i];
			assert(paths[v][v] == 0);
			paths[v][v] = 1;
			
			for(int j=0;j<Adj[v].size();j++)
			{
				int u = Adj[v][j];
				// cout << "Edge from " << v << " to " << u << endl;
				// v->u is an edge
				for(int z=1;z<=N;z++) {
					paths[v][z] += paths[u][z];
					if(paths[v][z] > 1) ok = 1;
				}
			}
		}
		
		printf("Case #%d: ", cases);
		printf("%s\n", ok ? "Yes" : "No");
	}
	return 0;
}
