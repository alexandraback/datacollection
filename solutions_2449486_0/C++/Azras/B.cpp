#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100][100];
int rows[100];
int columns[100];
int main(){
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++){
			rows[i] = 0;
		}
		for(int j = 0; j < m; j++){
			columns[j] = 0;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d", &arr[i][j]);
				rows[i] = max(rows[i], arr[i][j]);
				columns[j] = max(columns[j], arr[i][j]);
			}
		}
		bool fail = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(arr[i][j] != min(columns[j], rows[i]))
					fail = true;
			}
		}
		printf("Case #%d: ", test);
		if(fail) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
