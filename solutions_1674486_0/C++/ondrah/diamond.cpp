#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <math.h>
#define FOR(A, B) for(A=0;A<B;A++)
#define MAXN 1111
using namespace std;
vector<int> sousede[MAXN];
int pth[MAXN];
bool result;
void dfs(int v, int pn)
{
	int i;
	if(pth[v] == -1) {
		pth[v] = pn;
	} else if(pth[v] != pn) {
		result = true;
	}
	FOR(i, sousede[v].size()) {
		if(pth[sousede[v][i]] == -1) {
			dfs(sousede[v][i], pn);
		} else if(pth[sousede[v][i]] != pn) {
			result = true;
		}
	}
}
int main()
{
	int t,T,i,j,n;
	scanf("%d", &T);
	FOR(t, T) {
		FOR(i, MAXN) sousede[i].clear();
		scanf("%d", &n);
		FOR(i, n) {
			int mi;
			scanf("%d", &mi);
			FOR(j, mi) {
				int x;
				scanf("%d", &x);
				sousede[i].push_back(x-1);
			}
		}
		
		bool ans = false;
		
		FOR(i, n) {
			FOR(j, n) pth[j] = -1;
			pth[i] = 0;
			result = false;
			FOR(j, sousede[i].size()) {
				dfs(sousede[i][j], j);
			}
			if(result) ans = true;
		}

		printf("Case #%d: %s\n", t+1, ans ? "Yes" : "No");
	}
	return 0;
}
