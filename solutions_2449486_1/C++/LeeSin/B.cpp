#include <cstdio>
#include <algorithm>
#define N 105
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int n, m, t, a[N][N], b[N][N];

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d %d", &n, &m);
		FI(i, 1, n) FI(j, 1, m) scanf("%d", &a[i][j]);
		FI(i, 1, n){
			int h = 0;
			FI(j, 1, m) h = max(h, a[i][j]);
			FI(j, 1, m) b[i][j] = h;
		}
		FI(j, 1, m){
			int h = 100;
			FI(i, 1, n) if(a[i][j] < b[i][j]) h = min(h, a[i][j]);
			FI(i, 1, n) b[i][j] = min(h, b[i][j]);
		}
		
		bool f = 1;
		FI(i, 1, n) FI(j, 1, m) if(a[i][j] != b[i][j]) f = 0;
		printf("Case #%d: %s\n", z, f ? "YES" : "NO");
	}
	scanf("\n");
}
