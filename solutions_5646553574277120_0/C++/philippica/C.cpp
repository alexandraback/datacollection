#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int dep,T,C,D,V;
int dp[100];
int v[100],f;
int vis[100];

void Dfs(int p){
	if(f) return;
	if(p > dep){
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= dep; ++i){
			for(int j = V; j >= v[i]; --j){
				dp[j] |= dp[j - v[i]];
			}
		}
		int flag = 1;
		for(int i = 1; i <= V; ++i) if(dp[i] == 0){
			flag = 0;
			break;
		}
		if(flag) f = 1;
		return;
	}
	for(int i = 1; i <= V; ++i) if(vis[i] == 0){
		vis[i] = 1;
		v[p] = i;
		Dfs(p + 1);
		vis[i] = 0;
	}
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&C,&D,&V);
		for(int i = 1; i <= D; ++i){
			scanf("%d",&v[i]);
			vis[v[i]] = 1;
		}
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i = 1; i <= D; ++i){
			for(int j = V; j >= v[i]; --j){
				dp[j] |= dp[j - v[i]];
			}
		}
		printf("Case #%d: ",tt);
		int flag = 1;
		for(int i = 1; i <= V; ++i) if(dp[i] == 0){
			flag = 0;
			break;
		}
		if(flag){
			printf("0\n");
			continue;
		}
		for(int i = 1; i <= V; ++i){
			dep = i + D;
			f = 0;
			Dfs(D + 1);
			if(f){
				//for(int j = 1; j <= dep; ++j){
				//	printf("%d ",v[j]);
				//}
				//puts("");
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}

