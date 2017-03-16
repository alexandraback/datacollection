#include <cstdio>
#include <algorithm>
#define N 2005
#define M 26
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, c[M], u[10][M], a[M];
char s[10][20] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char str[N];

void solve(int tt){
	scanf("%s", str);
	fi(i, 0, M) c[i] = a[i] = 0;
	for(int i = 0; str[i]; i++) c[str[i] - 'A']++;
	
	a[0] = c['Z' - 'A'];
	fi(i, 0, M) c[i] -= u[0][i] * a[0];
	
	a[2] = c['W' - 'A'];
	fi(i, 0, M) c[i] -= u[2][i] * a[2];
	
	a[6] = c['X' - 'A'];
	fi(i, 0, M) c[i] -= u[6][i] * a[6];
	
	a[8] = c['G' - 'A'];
	fi(i, 0, M) c[i] -= u[8][i] * a[8];
	
	a[7] = c['S' - 'A'];
	fi(i, 0, M) c[i] -= u[7][i] * a[7];
	
	a[5] = c['V' - 'A'];
	fi(i, 0, M) c[i] -= u[5][i] * a[5];
	
	a[4] = c['F' - 'A'];
	fi(i, 0, M) c[i] -= u[4][i] * a[4];
	
	a[3] = c['R' - 'A'];
	fi(i, 0, M) c[i] -= u[3][i] * a[3];
	
	a[1] = c['O' - 'A'];
	fi(i, 0, M) c[i] -= u[1][i] * a[1];
	
	a[9] = c['I' - 'A'];
	fi(i, 0, M) c[i] -= u[9][i] * a[9];
	
	printf("Case #%d: ", tt);
	fi(i, 0, 10) fi(j, 0, a[i]) printf("%d", i);
	puts("");
	
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	fi(i, 0, 10)
		for(int j = 0; s[i][j]; j++)
			u[i][s[i][j] - 'A']++;
	
	scanf("%d", &tc);
	FI(tt, 1, tc) solve(tt);
	scanf("\n");
}
