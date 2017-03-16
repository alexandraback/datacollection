#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
#define N 1005

int TC, n, m, C, a[N][N], B;

void solve(int tc){
	CLR(a, 0);
	int flip = 0, yes = 0;
	scanf("%d%d%d", &n, &m, &B);
	if (n < m) {swap(n, m); flip = 1;}
	
	if (m == 1){
		FOR(i, 0, B) a[i][0] = '*';
		FOR(i, B, n) a[i][0] = '.';
		a[n - 1][0] = 'c';
		yes = 1;
	}
	else {
		C = n * m - B;
		if (C == 1){
			yes = 1;
			FOR(i, 0, n) FOR(j, 0, m) a[i][j] = '*';
			a[0][0] = 'c';
		}
		if (!yes)
		FOE(i, 2, m){
			int ok = 0, D = C / i;
			if (C % i == 0 && D >= 2 && D <= n) ok = 1;
			if (C % i >= 2 && D >= 2 && D < n) ok = 1;
			if (ok){
				FOR(j, 0, n) FOR(k, 0, m) a[j][k] = '*';
				FOR(j, 0, D) FOR(k, 0, i) a[j][k] = '.';
				FOR(k, 0, C % i) a[D][k] = '.';
				a[0][0] = 'c';
				yes = 1;
				break;
			}
		}
		if (!yes){
			swap(n, m); flip = 1 - flip;
			FOE(i, 2, m){
				int ok = 0, D = C / i;
				if (C % i == 0 && D >= 2 && D <= n) ok = 1;
				if (C % i >= 2 && D >= 2 && D < n) ok = 1;
				if (ok){
					FOR(j, 0, n) FOR(k, 0, m) a[j][k] = '*';
					FOR(j, 0, D) FOR(k, 0, i) a[j][k] = '.';
					FOR(k, 0, C % i) a[D][k] = '.';
					a[0][0] = 'c';
					yes = 1;
					break;
				}
			}
		}
		if (!yes){
			if (n > 3 && B < m){
				FOR(i, 0, n) FOR(j, 0, m) a[i][j] = '.';
				FOR(i, 0, m - 2) a[0][i] = '*';
				FOR(i, 0, B - m + 2) a[1][i] = '*';
				a[n - 1][m - 1] = 'c';
				yes = 1;
			}
		}
	}
	
	printf("Case #%d:\n", tc);
	if (!yes) printf("Impossible\n");
	else {
		if (!flip)
			FOR(i, 0, n){
				FOR(j, 0, m) printf("%c", a[i][j]);
				printf("\n");
			}
		else {
			FOR(j, 0, m){
				FOR(i, 0, n)
					printf("%c", a[i][j]);
				printf("\n");
			}
		}
	}
	
}


int main(){
	scanf("%d", &TC);
	FOR(i, 0, TC) solve(i + 1);
}
