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

const int n = 4;

char a[10][10];

//-------------------------------------------------------------------------------------------------

bool check(char c, int test) {
	for (int i = 1; i <= n; i++) {
		bool bl = true;
		for (int j = 1; j <= n; j++)
			if (a[i][j] == c || a[i][j] == '.')
				bl = false;
		if (bl) {
			//printf("Case #%d: X won\n", test);
			return bl;
		}
	}
	for (int j = 1; j <= n; j++) {
		bool bl = true;
		for (int i = 1; i <= n; i++)
			if (a[i][j] == c || a[i][j] == '.')
				bl = false;
		if (bl) {
			//printf("Case #%d: X won\n", test);
			return bl;
		}
	}

	bool bl = true;
	for (int i = 1; i <= n; i++) 
		if (a[i][i] == c || a[i][i] == '.')
			bl = false;
	if (bl) {
			return bl;
		}

	bl = true;
	for (int i = 1; i <= n; i++) 
		if (a[i][n - i + 1] == c || a[i][n - i + 1] == '.')
			bl = false;
	if (bl) {
			//printf("Case #%d: X won\n", test);
			return bl;
		}

	return false;
}

void solve(int test) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	if (check('O', test)) {
		printf("Case #%d: X won\n", test);
		return;
	}	
	if (check('X', test)) {
		printf("Case #%d: O won\n", test);
		return;
	}
	
	int kol = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] == '.')
				kol++;

	if (kol == 0)
		printf("Case #%d: Draw\n", test);
	else {
    	printf("Case #%d: Game has not completed\n", test);
	}
}

int main() {

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		solve(test);				
	}
	
	return 0;
}