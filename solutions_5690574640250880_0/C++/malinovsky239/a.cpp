#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 50;

int r, c, m;
bool mine[N][N];
int val[N][N], strong[N][N], was_str[N][N], cnt_str, start_j, start_k;

bool valid(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

void _dfs(int j, int k) {
	cnt_str--;
	was_str[j][k] = 1;
	for (int dx = -1; dx <= 1; dx++)
    	for (int dy = -1; dy <= 1; dy++) 
        	if (valid(j + dx, k + dy))
        		if (strong[j + dx][k + dy] && !was_str[j + dx][k + dy])
        			_dfs(j + dx, k + dy);        			
}

bool check() {
	memset(strong, 0, sizeof(strong));
	memset(val, 0, sizeof(val));

	cnt_str = 0;
	start_j = start_k = -1;

    for (int j = 0; j < r; j++)
        for (int k = 0; k < c; k++) 
        	if (!mine[j][k]) {
        		for (int dx = -1; dx <= 1; dx++)
        			for (int dy = -1; dy <= 1; dy++) {        				
        				if (valid(j + dx, k + dy))
        					if (mine[j + dx][k + dy])
        						val[j][k]++;
        			}	
				if (val[j][k] == 0) {
					strong[j][k] = 1;
					start_j = j, start_k = k;
					cnt_str++;
				}									
          	}

    for (int j = 0; j < r; j++)
        for (int k = 0; k < c; k++) 
        	if (!mine[j][k] && !strong[j][k]) {
				int cnt = 0;        		
        		for (int dx = -1; dx <= 1; dx++)
        			for (int dy = -1; dy <= 1; dy++) {        				
        				if (valid(j + dx, k + dy))
        					if (strong[j + dx][k + dy])
        						cnt++;
        			}					
				if (cnt == 0) {			
					return 0;
          		}
			}
		                                
	memset(was_str, 0, sizeof(was_str));
	_dfs(start_j, start_k);		

	return (cnt_str == 0);
}

bool dfs(int x, int y, int mines) {
	if (mines == m) {				
		if (check()) {
   			bool center = 0;
			for (int i = 0; i < r; i++, puts(""))
				for (int j = 0; j < c; j++) {
					if (mine[i][j])
						printf("*");
					else {
						if (strong[i][j] && !center) {
							printf("c");
							center = 1;
						}
						else
							printf(".");
					}						
				}			
			return 1;
		}
		else
			return 0;
	}
	if (x == r)
		return 0;
	
	int next_x = x, next_y = y + 1;
	if (next_y == c) {	
		next_y = 0;
		next_x++;
	}
		
	if (dfs(next_x, next_y, mines))
		return 1;
	mine[x][y] = 1;
	if (dfs(next_x, next_y, mines + 1)) {
		mine[x][y] = 0;
		return 1;
	}
	mine[x][y] = 0;
	return 0;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
	    printf("Case #%d:\n", i + 1);
		cin >> r >> c >> m;
		if (m == r * c - 1) {
			for (int j = 0; j < r; j++, puts(""))
				for (int k = 0; k < c; k++)
					if (j + k == 0)
						printf("c");
					else	
						printf("*");
			continue;
		}
		if (dfs(0, 0, 0)) {
		}
		else {
			puts("Impossible");
		}
	}
	return 0;
}
