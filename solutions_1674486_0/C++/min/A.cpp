#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <functional>
using namespace std;

int T, n;
typedef long long LL;
vector< int > vec[1009], t;
LL sta[1009];
LL temp[1009];
bool yes ;
int idx;

LL dfs( int u) {
	int v;
	LL ret = 0, o;	
	for( int i = 0; i < vec[u].size(); ++ i) {
		v = vec[u][i];
		o = dfs(v);
		if(ret & o) {
			yes = true;
			return 0LL;
		}
		ret |= o;
	}
	return ret | (1LL << u);
}
int in[1009];
bool judge() {
	memset( sta, 0, sizeof(sta));
	yes = false;
	for( int i = 1; i <= n; ++ i)if(in[i] == 0) {
		dfs( i);
	//	for( int j = 1; j <= n; ++ j) sta[j] |= temp[j];	
	}
	return yes;
}
int main() {
	//freopen("A-small-attempt1.in", "r",stdin);

	freopen("A-small-attempt2.in", "r",stdin);
	freopen("out", "w",stdout);
	scanf("%d", &T);
	for( int cas = 1;cas <= T; ++cas) {
		printf("Case #%d: ",cas);
		scanf("%d", &n);
		for( int i = 1; i <= n; ++ i)vec[i].clear();
		memset( in, 0, sizeof(in));
		int tmp, u, v;
		for( int i = 1; i <= n; ++ i) {
			scanf("%d", &tmp);
			for( int j = 0; j < tmp; ++ j) {
				scanf("%d", &v);
				vec[i].push_back(v);
				++ in[v];
			}
		}

		puts( judge() ? "Yes" : "No");
	}
	return 0;
}
