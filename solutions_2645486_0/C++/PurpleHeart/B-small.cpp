#include <cstdio>
#include <algorithm>

using namespace std;

int E, R, N, cases, V[50], ans, now, hp;

int gao(int v){
	if(v == N){
		ans = max(ans, now);
		return 0;
	}
	int tmp1 = now, tmp2 = hp;
	for(int i = 0; i <= hp; ++i){
		now += V[v] * i;
		hp = hp - i + R;
		hp = min(hp, E);
		gao(v + 1);
		hp = tmp2;
		now = tmp1;
	}
}

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d%d%d", &E, &R, &N);
		for(int i = 0; i < N; ++i) scanf("%d", &V[i]);
		ans = 0, now = 0, hp = E;
		gao(0);
		printf("Case #%d: %d\n", xx, ans);
	}
}
