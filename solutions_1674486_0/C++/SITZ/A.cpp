#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

#define MAXX 1000

int mat[MAXX + 1][MAXX + 1];

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				mat[i][j] = 0;
				
		for (int n = 1; n <= N; n++) {
			int M, m;
			cin >> M;
			while (M--) {
		 		cin >> m;
  	 			++mat[n][m];
	  		}
  		}
  		
  		bool flag = false;
  		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
  				for (int j = 1; j <= N; j++) {
					mat[i][j] += (mat[i][k] && mat[k][j]);
					if (mat[i][j] > 1) {
   					   flag = true;
   					   break;
		   			}
				}
			}
		}
 		if (flag) cout << "Case #" << t << ": Yes" << endl;
 		else cout << "Case #" << t << ": No" << endl;
	}
	return 0;
}
