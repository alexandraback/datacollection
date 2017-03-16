#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, mi, ma, cnt, t, fi, cc, e, r, z, x, an, q, w, s;
int v[1010];
vector <int> a[1010];

void dfs(int x){
	for (int i=0; i<a[x].size(); i++){
		if (v[a[x][i]] == 0){
			v[a[x][i]] = 1;
			dfs(a[x][i]);
		} else {
			fi = 1;
			return;
		}
	}
}

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		fi = 0;
		printf("Case #%d: ", rr);
		scanf("%d", &m);
		for (int i=0; i<m; i++)
			a[i].clear();
		for (int i=0; i<m; i++){
			scanf("%d", &n);
			for (int j=0; j<n; j++){
				scanf("%d", &q); q--;
				a[i].push_back(q);
			}
		}
		for (int k=0; k<m; k++){
			if (fi == 1) break;
			memset(v, 0, sizeof(v));
			v[k] = 1;
			dfs(k);
		}
		if (fi == 1)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
