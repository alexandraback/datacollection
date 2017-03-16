#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXL 128

int map[ MAXL ][ MAXL ];
int row[ MAXL ], col[ MAXL ];

int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int p = 1; p <= t; ++p) {
	    int n, m;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
	    scanf("%d %d", &n, &m);
	    for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &map[i][j]);
                if (map[i][j] > row[i]) row[i] = map[i][j];
                if (map[i][j] > col[j]) col[j] = map[i][j];
            }
        bool flag = true;
	    for (int i = 1; i <= n && flag; ++i)
            for (int j = 1; j <= m && flag; ++j)
                if (row[i] > map[i][j] && col[j] > map[i][j]) flag = false;
        printf("Case #%d: %s\n", p, flag ? "YES" : "NO");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

