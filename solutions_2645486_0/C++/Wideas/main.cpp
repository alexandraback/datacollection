#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 50;
int f[maxn][maxn];
int v[maxn];

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
	int T, ca = 0, e, r, n, ans;
	scanf("%d", &T);
	while(T--){
		memset(f, -1, sizeof(f));
		scanf("%d%d%d", &e, &r, &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		for(int j = 0; j <= e; j++) f[0][j] = 0;
		for(int i = 0; i < n ; i++)
			for(int j = 0; j <= e; j++){
				if(f[i][j] == -1) continue;
				for(int k = 0; k <= j; k++){
					int ne = j - k + r;
					if(ne > e) ne = e;
					f[i + 1][ne] = max(f[i + 1][ne], f[i][j] + k * v[i]);
				}
			}
		ans = 0;
		for(int j = 0; j <= e; j++)
			ans = max(ans, f[n][j]);
		printf("Case #%d: %d\n", ++ca, ans);
	}
	return 0;
}