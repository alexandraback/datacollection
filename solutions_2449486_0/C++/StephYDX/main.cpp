#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	int a[100][100];
	int b[100][100];
	for(int cas = 1;cas <= TT; ++cas){
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i = 0;i < N; ++i){
			for(int j = 0;j < M; ++j){
				scanf("%d", a[i] + j);
			}
		}
		for(int i = 0;i < N; ++i){
			int maxi = 0;
			for(int j = 0;j < M; ++j){
				maxi = max(maxi, a[i][j]);
			}
			for(int j = 0;j < M; ++j){
				b[i][j] = maxi;
			}
		}
		bool chk = true;
		for(int j = 0;j < M; ++j){
			int maxi = 0;
			for(int i = 0;i < N; ++i){
				maxi = max(maxi, a[i][j]);
			}
			for(int i = 0;i < N; ++i){
				b[i][j] = min(b[i][j], maxi);
				if(b[i][j] != a[i][j]) chk = false;
			}
		}
		printf("Case #%d: %s\n", cas, chk? "YES": "NO");
	}
	return 0;
}
