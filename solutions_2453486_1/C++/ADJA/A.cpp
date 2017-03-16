#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

int t;
char a[10][10];
string ans;

void solve() {
	int x, o, t, dot = 0;

	for (int i = 1; i <= 4; i++) {
		x = o = t = 0;
		for (int j = 1; j <= 4; j++) {
			if (a[i][j] == 'X') 
				x++;
			if (a[i][j] == 'O')
				o++;
			if (a[i][j] == 'T') 
				t++;
			if (a[i][j] == '.')
				dot++;
		}
		if (x == 4 || (x == 3 && t == 1)) {
			ans = "X won";
			return;
		}
		if (o == 4 || (o == 3 && t == 1)) {
			ans = "O won";
			return;
		}
	}

	for (int j = 1; j <= 4; j++) {
		x = o = t = 0;
		for (int i = 1; i <= 4; i++) {
			if (a[i][j] == 'X') 
				x++;
			if (a[i][j] == 'O')
				o++;
			if (a[i][j] == 'T') 
				t++;
			if (a[i][j] == '.')
				dot++;
		}
		if (x == 4 || (x == 3 && t == 1)) {
			ans = "X won";
			return;
		}
		if (o == 4 || (o == 3 && t == 1)) {
			ans = "O won";
			return;
		}
	}

	x = o = t = 0;
	for (int i = 1; i <= 4; i++) {
		if (a[i][i] == 'X') 
			x++;
		if (a[i][i] == 'O')
			o++;
		if (a[i][i] == 'T') 
			t++;
		if (a[i][i] == '.')
			dot++;
	}
	if (x == 4 || (x == 3 && t == 1)) {
		ans = "X won";
		return;
	}
	if (o == 4 || (o == 3 && t == 1)) {
		ans = "O won";
		return;
	}

	x = o = t = 0;
	for (int i = 1; i <= 4; i++) {
		if (a[4 - i + 1][i] == 'X') 
			x++;
		if (a[4 - i + 1][i] == 'O')
			o++;
		if (a[4 - i + 1][i] == 'T') 
			t++;
		if (a[4 - i + 1][i] == '.')
			dot++;
	}
	if (x == 4 || (x == 3 && t == 1)) {
		ans = "X won";
		return;
	}
	if (o == 4 || (o == 3 && t == 1)) {
		ans = "O won";
		return;
	}

	if (dot == 0) {
		ans = "Draw";
		return;
	}

	ans = "Game has not completed";
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d\n", &t);

	for (int it = 1; it <= t; it++) {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) 
				scanf("%c", &a[i][j]);
			scanf("\n");
		}
		scanf("\n");
		solve();
		printf("Case #%d: ", it);
		cout << ans << endl;
	}

	return 0;
}