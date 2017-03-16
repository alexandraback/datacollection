/*
 * Author: NomadThanatos
 * Created Time:  2012-5-6 17:10:43
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;

#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())

const int MAXINT = -1u>>1;
const int MAXN = 1000 + 50;

bool isDiagram;
bool vis[MAXN];
int in[MAXN];
vector<int> adj[MAXN];

void dfs(const int &i) {
	vis[i] = true;
	for(int j = 0 ; j < (int)adj[i].size() ; j++) {
		int u = adj[i][j];
		if (!vis[u]) {
			dfs(u);
		}
		else isDiagram = true;
	}
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	int T;
	scanf("%d",&T);
	for(int t = 0 ; t < T ; t++) {
		int N;
		scanf("%d",&N);
		memset(in,0,sizeof(in));
		for(int i = 0 ; i < N ; i++) {
			adj[i].clear();
		}
		for(int i = 0 ; i < N ; i++){
			int K;
			scanf("%d",&K);
			for(int k = 0 ; k < K ; k++) {
				int u;
				scanf("%d",&u);
				adj[i].push_back(u - 1);
				in[u - 1]++;
			}
		}
		isDiagram = false;
		for(int i = 0 ; i < N ; i++) {
			if (in[i] == 0) {
				memset(vis,false,sizeof(vis));
				dfs(i);
			}
		}
		printf("Case #%d: %s\n",t + 1,isDiagram ? "Yes" : "No");
	}
    return 0;
}

