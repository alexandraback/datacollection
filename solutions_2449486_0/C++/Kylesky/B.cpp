#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int cases;
	scanf("%d", &cases);
	for(int z=1; z<=cases; z++){
		int n, m;
		scanf("%d %d", &n, &m);
		
		int grid[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &grid[i][j]);
			}
		}
		
		bool yes = true;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				bool vert = false;
				bool hori = false;
				for(int k=i-1; k>=0; k--){
					if(grid[k][j] > grid[i][j]){
						vert = true;
						goto a;
					}
				}
				for(int k=i+1; k<n; k++){
					if(grid[k][j] > grid[i][j]){
						vert = true;
						goto a;
					}
				}
				a:
				for(int k=j-1; k>=0; k--){
					if(grid[i][k] > grid[i][j]){
						hori = true;
						goto b;
					}
				}
				for(int k=j+1; k<m; k++){
					if(grid[i][k] > grid[i][j]){
						hori = true;
						goto b;
					}
				}
				b:
				if(vert && hori){
					yes = false;
					goto c;
				}
			}
		}
		c:
		if(yes){
			printf("Case #%d: YES\n", z);
		}else{
			printf("Case #%d: NO\n", z);
		}
	}

	return 0;
}