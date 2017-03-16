#include <iostream>
#include <iomanip>

using namespace std;

int a[100][100];

int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	cin >> T;
	cout << fixed << setprecision(15);
	for (int tst = 1; tst <= T; tst++){
		printf("Case #%d:\n", tst);
		
		int n, m, c;

		cin >> n >> m >> c;

		memset(a, 0, sizeof(a));

		if (n * m == c + 1){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					if ((i == n) && (j == m)) printf("c"); else printf("*");
				}
				printf("\n");
			}
			continue;
		}

		if (n == 1){
			for (int i = 1; i <= m; i++){
				if (i == 1) printf("c"); else
					if (i <= m - c) printf("."); else printf("*");
			}
			printf("\n");
			continue;
		}

		if (m == 1){
			for (int i = 1; i <= n; i++){
				if (i == 1) printf("c\n"); else
					if (i <= n - c) printf(".\n"); else printf("*\n");
			}
			continue;
		}

		int ok = 0;
		for (int i = 2; i <= n; i++){
			for (int j = 2; j <= m; j++){
				if (ok) break;
				if (n * m - (2 * i + 2 * j - 4) >= c)
					if (n * m - i * j <= c){
						ok = 1;
						a[1][1] = 1;
						int C = c;
						//cout << i << " " << j << endl;
						for (int ii = 1; ii <= n; ii++){
							for (int jj = 1; jj <= m; jj++){
								if ((ii > i) || (jj > j)){
									a[ii][jj] = 2;
									C--;
								}
							}
						}

						for (int ii = i; ii > 2; ii--){
							for (int jj = j; jj > 2; jj--){
								if (C > 0) a[ii][jj] = 2;
								C--;
							}
						}
					}
			}
		}
		if (!ok) cout << "Impossible\n"; 
			else{
				for (int i = 1; i <= n; i++){
					for (int j = 1; j <= m; j++){
						if (a[i][j] == 0) cout << "."; else
							if (a[i][j] == 1) cout << "c"; else
								cout << "*";
					}
					cout << endl;
				}
			}
	}
	return 0;
}
