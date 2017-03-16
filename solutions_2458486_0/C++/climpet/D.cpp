#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vint;

int ok[1048576];

int N, K;
vint ts, c0;
vector<vint> ks;

vint keys(int S){
	vint c = c0;
	for(int i = 0; i < N; ++i){
		if(S >> i & 1){
			--c[ts[i]];
			for(int j = 0; j < ks[i].size(); ++j){
				++c[ks[i][j]];
			}
		}
	}
	return c;
}

int dfs(int S){
	int &ret = ok[S];
	if(ret & 2){ return ret & 1; }

	ret = 2;
	if(S + 1 == (1 << N)){
		ret = 3;
	}
	else{
		vint c = keys(S);
		for(int i = 0; i < N; ++i){
			for(int i = 0; i < N; ++i){
				if(S >> i & 1 || c[ts[i]] < 1){ continue; }
				ret |= dfs(S | 1 << i);
			}
		}
	}

	return ret;
}

void output(){
	int S = 0;
	int last = (1 << N) - 1;
	while(S != last){
		vint c = keys(S);
		for(int i = 0; i < N; ++i){
			int T = S | 1 << i;
			if(S != T && c[ts[i]] > 0 && (ok[T] & 1)){
				S = T;
				printf(" %d", i + 1);
				break;
			}
		}
	}
	puts("");
}

vint solve(){
	memset(ok, 0, sizeof ok);

	int ki;
	scanf("%d%d", &K, &N);

	c0.assign(201, 0);
	ts.resize(N);
	ks.assign(N, vint());
	for(int i = 0; i < K; ++i){
		scanf("%d", &ki);
		++c0[ki];
	}

	for(int i = 0; i < N; ++i){
		scanf("%d%d", &ts[i], &ki);
		ks[i].resize(ki);
		for(int j = 0; j < ki; ++j){
			scanf("%d", &ks[i][j]);
		}
	}

	dfs(0);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		vint ret = solve();
		printf("Case #%d:", i);
		if(ok[0] & 1){
			output();
		}
		else{
			puts(" IMPOSSIBLE");
		}
	}
}
