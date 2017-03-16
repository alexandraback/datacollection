#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <set>
#include <limits>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

int G[52][52];
ll cnt[52];
int N;
ll M;

int main(){
	int TC; ri(TC);
	FOR(tc,1,TC+1){
		scanf("%d %lld",&N, &M);
		ms(G,0);
		ms(cnt,0);
		cnt[0] = 1;
		FOR(u,0,N-1){
			FOR(v,u+1,N){
				cnt[v] += cnt[u];
				G[u][v] = 1;
			}
		}
		if(cnt[N-1] < M){
			printf("Case #%d: IMPOSSIBLE\n",tc);
			continue;
		}
		ll dif = cnt[N-1] - M;
		for(int u=N-2; u>-1; u--){
			if(dif >= cnt[u]){
				dif -= cnt[u];
				G[u][N-1] = 0;
			}
		}
		printf("Case #%d: POSSIBLE\n",tc);
		FOR(i,0,N){
			FOR(j,0,N){
				printf("%d",G[i][j]);
			}
			printf("\n");
		}
	}
	
}

