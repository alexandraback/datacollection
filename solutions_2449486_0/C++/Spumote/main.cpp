#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define next qwertyusdfgh
#define read(x) scanf("%d", &x)
#define write(x) printf("%d ", x)
#define writeln(x) printf("%d\n", x)

const int maxN = 200;

int a[maxN][maxN];
int cl[maxN], ln[maxN];

//-------------------------------------------------------------------------------------------------

bool solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	
	for (int i = 1; i <= n; i++) {
		ln[i] = -1;
		for (int j = 1; j <= m; j++)
			ln[i] = max(ln[i], a[i][j]);
	}	
	for (int j = 1; j <= m; j++) {
		cl[j] = -1;
		for (int i = 1; i <= n; i++)
			cl[j] = max(cl[j], a[i][j]);
	}	

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] < ln[i] && a[i][j] < cl[j])
				return false;
		}

	return true;
}

int main() {

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		if (solve()) 
			printf("Case #%d: YES\n", test);
		else 
        	printf("Case #%d: NO\n", test);
	}
	
	return 0;
}