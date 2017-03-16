#include <cstdio>
#include <fstream>
#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>

#include <ctime>
#include <cstdlib>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(A) (int) (A).size()

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(A) fputs((A), stderr)

#define sqr(A) ((A) * (A))
#define x first
#define y second
  
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

const int N = (int) 4;

int t;
char f[N][N];

bool test (int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

bool test (int x, int y, int dx, int dy, char val)
{
	int tx = x, ty = y;
	while (test(x, y)) {
		if (f[x][y] != val && f[x][y] != 'T')
			return false;
		x += dx, y += dy;
	}	

	cerr << tx << ' ' << ty << ' ' << dx << ' ' << dy << endl;

	return true;
}

int solve ()
{
	bool win[2] = {false, false};
	bool haveTurn = false;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (f[i][j] == '.')
				haveTurn = true;

	for (int i = 0; i < N; i++) {
		win[0] |= test(0, i, 1, 0, 'X') || test(i, 0, 0, 1, 'X');
		win[1] |= test(0, i, 1, 0, 'O') || test(i, 0, 0, 1, 'O');
	}

	win[0] |= test(0, 0, 1, 1, 'X') || test(N - 1, 0, -1, 1, 'X');
	win[1] |= test(0, 0, 1, 1, 'O') || test(N - 1, 0, -1, 1, 'O');

	if (win[0] || win[1]) 
		return win[1];
	else if (haveTurn)	
		return 3;
	else
		return 2;
}

int main () 
{
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif

    scanf("%d\n", &t);
    for (int test = 0; test < t; test++) {
    	for (int i = 0; i < N; i++)
    		for (int j = 0; j < N; j++)
    			scanf("%c ", &f[i][j]);

		int res = solve();

		printf("Case #%d: ", test + 1);
		if (res == 0)
			puts("X won");
		else if (res == 1)
			puts("O won");
		else if (res == 2)
			puts("Draw");
		else
			puts("Game has not completed");
	}
    
    return 0; 
}

