#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<int> vi;
const int MAXN = 1010, MAXL = 1000010;

int n;
int bf[MAXN];
vi f[MAXN];
bool visi[MAXN];

int dfs(int s, int u, int c);
int dfs2(int u, int forb, int c);

int main() {
	//freopen("C-small-attempt1.in", "r", stdin);
//	freopen("output-small.txt", "w", stdout); 

	int t;
	scanf("%d", &t);

	for(int test=1; test<=t; test++) {
		printf("Case #%d: ", test);

		scanf("%d", &n);
		for(int i=0; i<n; i++) f[i].clear();
		for(int i=0; i<n; i++) {
			scanf("%d", &bf[i]);
			bf[i]--;
			f[ bf[i] ].push_back(i);
		}

		int circulo = 0;
		for(int i=0; i<n; i++) {
			memset(visi, false, sizeof(visi));
			circulo = max(circulo, dfs(i, i, 0));
		}

		int dupla = 0;
		for(int i=0; i<n; i++) {
			if(bf[ bf[i] ] == i) {
				memset(visi, false, sizeof(visi));
				dupla += 2 + dfs2(i, bf[i], 0) + dfs2(bf[i], i, 0);
			}
		}

		printf("%d\n", max(circulo, dupla/2));
	}
}

int dfs2(int u, int forb, int c) {
	int aux = 0;
	for(int i=0; i<(int)f[u].size(); i++) if(f[u][i] != forb) {
		aux = max(aux, dfs2(f[u][i], forb, c)+1);
	}
	return aux;
}

int dfs(int s, int u, int c) {
	if(u == s and c) return c;

	if(visi[u]) return -1;
	visi[u] = true;

	return dfs(s, bf[u], c+1);
}
