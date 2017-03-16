#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int depth(vector<vector<int> > &M, int x)
{
	int ret = 1;
	for (int i=0; i<M[x].size(); i++) {
		int res = depth(M, M[x][i]) + 1;
		if (ret < res) { ret = res; }
	}
	return ret;
}
int cycle(int *G, int *V, int x)
{
	if (V[G[x]] > 0) { return V[x] - V[G[x]] + 1; }
	V[G[x]] = V[x] + 1;
	return cycle(G, V, G[x]);
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);


	int _n;
	scanf("%d", &_n);

	for (int _t=1; _t<=_n; _t++) {
		int n, m, G[1010] = {0}, ret = 0;
		scanf("%d", &n);
		vector<vector<int> > M(n+1);
		for (int i=1; i<=n; i++) {
			scanf("%d", G+i);
		}
		for (int i=1; i<=n; i++) {
			if (i == G[G[i]]) { continue; }
			M[G[i]].push_back(i);
		}
		
		for (int i=1; i<=n; i++) {
			if (i == G[G[i]] && i < G[i]) {
				int res = depth(M, i) + depth(M, G[i]);
				if (ret < res) { ret = res; }
			}
		}

		int V[1010] = {0};
		for (int i=1; i<=n; i++) {
			if (V[i] == 0) {
				V[i] = 1;
				int res = cycle(G, V, i);
				if (ret < res) { ret = res; }
			}
		}

		printf("Case #%d: %d\n", _t, ret);

	}
}
