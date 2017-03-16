// b Hewr
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define clr(a,x) memset(&a, x, sizeof(a))

const int maxn = 110;

int a[maxn][maxn];
bool col[maxn], row[maxn];
int n, m;

int main() {
	freopen("b.in", "r", stdin);
	int CA;
	cin >> CA;
	for (int Ca = 1; Ca <= CA; ++Ca) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
		clr(col, 0); clr(row, 0);
		
		bool legal(1);
		while (1) {
			int X(0), Y(0), opt = 200;
			for (int i = 1; i <= n; ++i) if (!row[i]) 
				for (int j = 1; j <= m; ++j) if (!col[j]) 
					if (a[i][j] < opt) {
						opt = a[i][j], X = i, Y = j;
					}
			if (opt == 200) break;
			
			bool flag(1);
			// row
			for (int j = 1; j <= m; ++j) if (!col[j] && a[X][j] != a[X][Y]) {
				flag = 0;
				break;
			}
			if (flag) {
				row[X] = 1;
				continue;
			}

			flag = 1;
			// column
			for (int i = 1; i <= n; ++i) if (!row[i] && a[i][Y] != a[X][Y]) {
				flag = 0;
				break;
			}
			if (flag) {
				col[Y] = 1;
				continue;
			}

			legal = 0;
			break;
		}
		if (legal) 
			printf("Case #%d: YES\n", Ca);
		else	printf("Case #%d: NO\n", Ca);
	}
}
