#include <cstdio>
#include <cstring>
using namespace std;

int n, m, a[102][102];

bool check(int h, int y, int x, int dy, int dx){
	while(a[y][x]){
		if(a[y][x] > h){ return false; }
		y += dy;
		x += dx;
	}
	return true;
}

bool solve(){
	memset(a, 0, sizeof a);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j){
		scanf("%d", &a[i][j]);
	}

	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j){
		int h = a[i][j];
		if(!check(h, 1, j, 1, 0) && !check(h, i, 1, 0, 1)){
			return false;
		}
	}
	return true;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		printf("Case #%d: %s\n", i, solve() ? "YES" : "NO");
	}
}
