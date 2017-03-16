#include <cstdio>
#include <algorithm>
using namespace std;

int T, n, m;
struct stuff{
	long long val;
	int id;
};
long long cache[105][105];
stuff box[105], toy[105];

long long solve(int a, int b, long long nval, long long mval){
//	printf("%d %d %lld %lld\n", a, b, nval, mval);
	if(a == n || b == m){
	//	printf("HERE %d %d %d %d", a, b, n, m);
		return 0;
	}
//	if(cache[a][b] != -1) return cache[a][b];
	if(toy[b].id == box[a].id){
		if(nval > mval){
			cache[a][b] = solve(a, b+1, nval-mval, toy[b+1].val) + mval;
		}
		else if(mval > nval){
			cache[a][b] = solve(a+1, b, box[a+1].val, mval-nval) + nval;
		}
		else{
			cache[a][b] = solve(a+1, b+1, box[a+1].val, toy[b+1].val) + mval;
		}
	}
	else{
		cache[a][b] = max(solve(a+1, b, box[a+1].val, mval), solve(a, b+1, nval, toy[b+1].val));
	}
//	printf("%lld\n", cache[a][b]);
	return cache[a][b];
}

int main(){
	freopen("q3.in", "r", stdin);
	freopen("q3.out", "w", stdout);
	scanf("%d", &T);
	for(int trololo = 1; trololo <= T; trololo++){
		scanf("%d %d", &n, &m);
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				cache[i][j] = -1;
			}
		}
		for(int i = 0; i < n; i++){
			scanf("%lld %d", &box[i].val, &box[i].id);
		}
		for(int i = 0; i < m; i++){
			scanf("%lld %d", &toy[i].val, &toy[i].id);
		}
		long long ans = solve(0, 0, box[0].val, toy[0].val);
		printf("Case #%d: %lld\n", trololo, ans);
	}
	return 0;
}
	
