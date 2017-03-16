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
int height[MAXN][MAXN];
int cut_row[MAXN];
int cut_col[MAXN];

int n, m;
bool solve(int height){
	// D(height);
	while (height > 0){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (board[i][j] == height){
					//D(i); D(j);
					if (cut_row[i] > height and cut_col[j] > height) return false;
					cut_row[i] = max(height, cut_row[i]);
					cut_col[j] = max(height, cut_col[j]);
				}
			}
		}
		
		// printf("After height %d\n", height);
		// printf("Cut Row: ");
		// for (int i = 0; i < n; ++i) printf("%d ", cut_row[i]);
		// printf("\nCut Col: ");
		// for (int j = 0; j < m; ++j) printf("%d ", cut_col[j]);
		// puts("");
		
		height--;
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
				max_height = max(max_height, board[i][j]);
			}
		}
		
		for (int i = 0;i < n; ++i) cut_row[i] = -1;
		for (int j = 0; j < m; ++j) cut_col[j] = -1;
		
		printf("Case #%d: ", run);
		if (solve(max_height)) puts("YES");
		else puts("NO");
	}
    return 0;
}
