#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int t;
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	
	for(int z = 1 ; z <= t ; z++) {
		int n, m, grid[100][100], Max = 0;;
		scanf("%d%d", &n, &m);

		for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) {
			scanf("%d", &grid[i][j]);
			Max = Max<grid[i][j] ? grid[i][j]:Max;
		}

		for(int k = 1 ; k <= Max-1 ; k++) {
			vector<int> row, col;
			for(int i = 0 ; i < n ; i++) {
				int j;
				for(j = 0 ; j < m ; j++) {
					if( grid[i][j] != k ) break;
				}
				if( j == m ) row.push_back(i);
			}
			for(int i = 0 ; i < m ; i++) {
				int j;
				for(j = 0 ; j < n ; j++) {
					if( grid[j][i] != k ) break;
				}
				if( j == n ) col.push_back(i);
			}

			for(int i = 0 ; i < row.size() ; i++) {
				for(int j = 0 ; j < m ; j++) grid[row[i]][j] = k+1;
			}
			for(int i = 0 ; i < col.size() ; i++) {
				for(int j = 0 ; j < n ; j++) grid[j][col[i]] = k+1;
			}
		}
		int tot =0;
		for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) if( grid[i][j] == Max ) tot++;
		
		printf("Case #%d: ", z);
		if( tot == n*m ) printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdout);
}