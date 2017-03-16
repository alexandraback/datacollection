//c small Hewr
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define fo(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define clr(a,x) memset(&a, x, sizeof(a))

const int mn = 21, ms = 2100000;

int f[mn][ms], a[mn];
int n;

void gen(int i, int j){
	bool fir(1);
	while (i > 0 && j > 0){
		int x = f[i][j];
		if (!fir) printf(" ");
		fir = 0;
		printf("%d", a[x]);
		i = x - 1, j -= a[x];
	}
	printf("\n");
}

int main(){
	int Ca;
	cin >> Ca;
	fo (CA, 1, Ca){
		cin >> n;
		a[0] = 0;
		fo (i, 1, n) cin >> a[i];
		int fi = -1, fs = -1;
		clr(f, -1), f[0][0] = 0;
		fo (i, 1, n){
			fo (j, 0, a[0] + a[i]) f[i][j] = f[i - 1][j];
			fo (j, 0, a[0]) if (f[i - 1][j] != -1){
				if (f[i][j + a[i]] != -1){
					fi = i, fs = j + a[i];
					break;
				}
				f[i][j + a[i]] = i;
			}
			a[0] += a[i];
			if (fi != -1) break;
		}
		printf("Case #%d:\n", CA);
		if (fi == -1) printf("Impossible\n"); else {
			gen(fi, fs);
			printf("%d", a[fi]);
			if (a[fi] != fs){
				printf(" ");
				gen(fi - 1, fs - a[fi]);
			} else printf("\n");
		}
	}
}
