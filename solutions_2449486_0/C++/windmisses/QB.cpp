#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100;
int mat[N][N], n, m;
bool col[N], row[N];
bool flag;

int main() {
	int T;
	scanf("%d", &T);
	
	for (int ca = 1; ca <= T; ca++) {
		printf("Case #%d: ", ca);
	
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
	
		flag = true;	
		for (int k = 1; k < 100; ++k) {
			memset(col, true, sizeof col);
			memset(row, true, sizeof row);
			
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (mat[i][j] > k) {
						row[i] = false;
						col[j] = false;
					}
						
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (mat[i][j] == k && !row[i] & !col[j]) 
						flag = false;
						
			if (!flag) break;
		}		
		
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}