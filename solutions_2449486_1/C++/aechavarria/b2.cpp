using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 105;
int board[MAXN][MAXN];
int max_row[MAXN];
int max_col[MAXN];

int n, m;
bool solve(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (board[i][j] < max_row[i] and board[i][j] < max_col[j]) return false;
		}
	}
	return true;
}

int main(){
	int cases; cin >> cases;
	for (int run = 1; run <= cases; ++run){
		cin >> n >> m;
		
		int max_height = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> board[i][j];
			}
		}
		
		for (int i = 0;i < n; ++i){
			max_row[i] = -1;
			for (int j = 0; j < m; ++j){
				max_row[i] = max(max_row[i], board[i][j]);
			}
		}
		
		for (int j = 0; j < m; ++j){
			max_col[j] = -1;
			for (int i = 0; i < n; ++i){
				max_col[j] = max(max_col[j], board[i][j]);
			}
		}
		
		printf("Case #%d: ", run);
		if (solve()) puts("YES");
		else puts("NO");
	}
    return 0;
}
