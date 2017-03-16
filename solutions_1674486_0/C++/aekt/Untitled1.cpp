#include <cstdio>

int tc, n, m[1001];
bool v[1001][1001], w;

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &tc);
	for(int ct = 1; ct <= tc; ct++){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				v[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &m[i]);
			for(int j = 0, k; j < m[i]; j++){
				scanf("%d", &k);
				v[i][k-1] = true;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				//printf("%2d", v[i][j]);
			}
			//printf("\n");
		}
		w = 0;
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if (!v[i][j]){
						if (v[i][k] && v[k][j]){
							v[i][j] = true;
						}
					}else{
						if (v[i][k] && v[k][j]){
							w = true;
							break;
						}
					}
				}
			}
		}
		printf("Case #%d: %s\n", ct, w ? "Yes" : "No");
	}
	scanf("\n");
	return 0;
}
