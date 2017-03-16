#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define N 105
using namespace std;

int n, m, cut, ban, ok;
int a[N][N], h[N][N];

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%d%d", &n, &m);
	FOR(i,0,n) FOR(j,0,m) scanf("%d", &a[i][j]), h[i][j] = 100;
	for (int k=100; k; k--){
		FOR(i,0,n){
			cut = ban = 0;
			FOR(j,0,m){
				if (a[i][j] == k) cut = 1;
				if (a[i][j] > k) ban = 1;
			}
			if (cut && !ban) FOR(j,0,m) h[i][j] = min(h[i][j], k);
		}
		FOR(i,0,m){
			cut = ban = 0;
			FOR(j,0,n){
				if (a[j][i] == k) cut = 1;
				if (a[j][i] > k) ban = 1;
			}
			if (cut && !ban) FOR(j,0,n) h[j][i] = min(h[j][i], k);
		}
	}
	ok = 1;
	FOR(i,0,n) FOR(j,0,m) if (a[i][j] != h[i][j]) ok = 0;
	puts(ok ? "YES" : "NO");
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
