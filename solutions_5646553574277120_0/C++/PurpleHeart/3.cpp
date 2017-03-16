#include <cstdio>
#include <cstring>

const int MAXV = 35;
const int MAXN = 20;

bool M[MAXV], flag[MAXV];
int C, D, V, T;
int A[MAXN];

bool check(int v){
	memset(flag, false, sizeof(flag));
	for(int i = 0; i < (1 << v); ++i){
		int cnt = 0;
		for(int j = 0; j < v; ++j)
			if(i & (1 << j)) cnt += A[j];
		if(cnt <= V) flag[cnt] = true;
	}
	for(int i = 1; i <= V; ++i)
		if(!flag[i]) return false;
	return true;
}

int gao(int dep, int limit, int hehe){
	if(dep == limit)
		return check(D + dep);
	for(int i = hehe + 1; i <= V; ++i)
		if(!M[i]){
			A[D + dep] = i;
			M[i] = true;
			bool xx = gao(dep + 1, limit, i);
			if(xx) return true;
			M[i] = false;
		}
	return false;
}

int main(){
	scanf("%d", &T);
	for(int xx = 1; xx <= T; ++xx){
		scanf("%d%d%d", &C, &D, &V);

		memset(M, false, sizeof(M));
		for(int i = 0; i < D; ++i){
			scanf("%d", &A[i]);
			M[A[i]] = true;
		}
		
		int ans = -1;
		for(int i = 0; i <= 5; ++i)
			if(gao(0, i, 0)){
				ans = i;
				break;
			}
		
		printf("Case #%d: %d\n", xx, ans);
	}
}
