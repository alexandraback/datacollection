#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))); (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define mii(a, b) if(b < a) a = b
#define maa(a, b) if(b > a) a = b

#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
#ifdef TEST
#define deb(...) fprintf(stderr, __VA_ARGS__)
#else 
#define deb(...)
#endif
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

string tobin(int x, int len) {
	string c;
	while(x) { c.PB(x%2+'0'); x /= 2; }
	while(sz(c) < len) c.PB('0');
	reverse(all(c));
	return c;
}
//------------------------------

int T, n = 4;
char mat[5][5];

void solve() {
	bool xWin, oWin;
	
	// cek baris
	for(int i = 0; i < n; i++) {
		xWin = true; oWin = true;
		for(int j = 0; j < n; j++) {
			if(mat[i][j] == '.') { xWin = oWin = false; }
			else if(mat[i][j] == 'O')	xWin = false;
			else if(mat[i][j] == 'X')	oWin = false;
		}
		
		if(xWin) { printf("X won\n"); return; }
		else if(oWin) { printf("O won\n"); return; }
	}
	
	// cek kolom
	for(int j = 0; j < n; j++) {
		xWin = true; oWin = true;
		for(int i = 0; i < n; i++) {
			if(mat[i][j] == '.') { xWin = oWin = false; }
			else if(mat[i][j] == 'O')	xWin = false;
			else if(mat[i][j] == 'X')	oWin = false;
		}
		
		if(xWin) { printf("X won\n"); return; }
		else if(oWin) { printf("O won\n"); return; }
	}
	
	// cek diagonal
	xWin = true; oWin = true;
	for(int i = 0; i < n; i++) {
		if(mat[i][i] == '.') { xWin = oWin = false; }
		else if(mat[i][i] == 'O')	xWin = false;
		else if(mat[i][i] == 'X')	oWin = false;
	}
	
	if(xWin) { printf("X won\n"); return; }
	else if(oWin) { printf("O won\n"); return; }
	
	xWin = true; oWin = true;
	for(int i = 0; i < n; i++) {
		if(mat[i][n-i-1] == '.') { xWin = oWin = false; }
		else if(mat[i][n-i-1] == 'O')	xWin = false;
		else if(mat[i][n-i-1] == 'X')	oWin = false;
	}
	
	if(xWin) { printf("X won\n"); return; }
	else if(oWin) { printf("O won\n"); return; }
	
	// cek draw
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(mat[i][j] == '.') {
				printf("Game has not completed\n");
				return;
			}
	
	printf("Draw\n");
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
			scanf("%s", &mat[i]);
		
		printf("Case #%d: ", tc+1);
		solve();
	}
	
	
	return 0;
}
