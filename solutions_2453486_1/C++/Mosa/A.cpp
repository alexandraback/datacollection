#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

char grid[5][5];

bool win(char c) {

	bool a, b;
	for(int i = 0; i < 4; ++i) {
		a = b = 1;
		for(int j = 0; j < 4; ++j) {
			a &= (grid[i][j] == c || grid[i][j] == 'T');
			b &= (grid[j][i] == c || grid[j][i] == 'T');
		}
		if(a || b)
			return true;
	}
	a = 1;
	for(int i = 0; i < 4; ++i)
		a &= (grid[i][i] == c || grid[i][i] == 'T');
	if(a)
		return true;
	a = 1;
	for(int i = 0; i < 4; ++i) {
		a &= (grid[i][3 - i] == c || grid[i][3 - i] == 'T');
	}
	return a;
}

bool empty() {
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			if(grid[i][j] == '.')
				return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
	
	int t;
	scanf("%d", &t);
	for(int tst = 1; tst <= t; ++tst) {
		for(int i = 0; i < 4; ++i)
			scanf("%s", grid[i]);
		printf("Case #%d: ", tst);
		if(win('X')) {
			printf("X won\n");
		}else if(win('O')) {
			printf("O won\n");
		}else if(empty()) {
			printf("Draw\n");
		}else {
			printf("Game has not completed\n");
		}
	}

	return 0;
}
