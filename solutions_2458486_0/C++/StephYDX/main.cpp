#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long llong;

const int MAXC = 20, MAXK = 40, MAXT = 200;
int open[MAXC], contain[MAXC][MAXK], cntk[MAXC];
int key[1<<MAXC][MAXT];
int K, N, mask;

int path[1<<MAXC];
int dfs(int s){
	if(path[s] >= 0) return path[s];
	int &ret = path[s];
	ret = N;
	for(int i = 0;i < N; ++i){
		if((s >> i) & 1) continue;
		if(key[s][open[i]] <= 0) continue;
		int ns = s | (1 << i);
		if(dfs(ns) < N || ns == mask) return ret = i;
	}
	return ret;
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		scanf("%d %d", &K, &N);
		memset(key[0], 0, sizeof(key[0]));
		for(int i = 0;i < K; ++i){
			int id;
			scanf("%d", &id);
			++key[0][id - 1];
		}
		for(int i = 0;i < N; ++i){
			scanf("%d %d", open + i, cntk + i);
			--open[i];
			memset(contain[i], 0, sizeof(contain[i]));
			for(int j = 0;j < cntk[i]; ++j){
				scanf("%d", contain[i] + j);
				--contain[i][j];
			}
		}
		for(int s = 1, es = 1 << N; s < es; ++s){
			for(int i = 0;i < N; ++i) if((s >> i) & 1){
				int ns = s ^ (1 << i);
				memcpy(key[s], key[ns], sizeof(key[s]));
				--key[s][open[i]];
				for(int j = 0;j < cntk[i]; ++j){
					++key[s][contain[i][j]];
				}
				break;
			}
		}
		
		memset(path, -1, sizeof(path[0]) << N);
		mask = (1 << N) - 1;
		printf("Case #%d:", cas);
		if(dfs(0) < N){
			for(int i = 0, x = 0;i < N; ++i){
				printf(" %d", path[x] + 1);
				x |= (1 << path[x]);
			}
			puts("");
		}
		else puts(" IMPOSSIBLE");
	}
	return 0;
}
