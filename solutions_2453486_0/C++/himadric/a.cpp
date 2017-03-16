#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int tests;
	cin >> tests;
	getchar();
	for (int tt = 0; tt < tests; tt++) {
		const int n = 4;
		int row[4][2];
		int col[4][2];
		int diag[2][2];
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(diag, 0, sizeof(diag));
		
		
		int tot = 4 * 4;
		for (int r = 0; r < 4; r++) {
			string str;
			cin >> str;
			for (int c = 0; c < 4; c++) {
				if (str[c] == 'X' || str[c] == 'T') {
					row[r][0]++;
					col[c][0]++;
					if (r == c) {
						diag[0][0]++;
					} 
					if (3 - r == c) {
						diag[1][0]++;
					}
				} 
				if (str[c] == 'O' || str[c] == 'T') {
					row[r][1]++;
					col[c][1]++;
					if (r == c) {
						diag[0][1]++;
					} 
					if (3 - r == c) {
						diag[1][1]++;
					}					
				}
				if (str[c] == '.') {
					tot--;
				}
				
			}
		}
		bool somone_won = false;
		for (int i = 0; i < n; i++) {
			if (row[i][0] == n || col[i][0] == n) {
				printf("Case #%d: X won\n", tt + 1);
				somone_won = true;
				break;
			}
			if (col[i][1] == n || row[i][1] == n) {
				printf("Case #%d: O won\n", tt + 1);
				somone_won = true;
				break;
			}
		}
		if (!somone_won) {
			for (int i = 0; i < 2; i++) {
				if (diag[i][0] == n) {
					printf("Case #%d: X won\n", tt + 1);
					somone_won = true;
					break;				
				}
				if (diag[i][1] == n) {
					printf("Case #%d: O won\n", tt + 1);
					somone_won = true;
					break;
				}
			}			
		}
		if (!somone_won && tot == 4 * 4) {
			printf("Case #%d: Draw\n", tt + 1);
		}
		if (!somone_won && tot < 4 * 4) {
			printf("Case #%d: Game has not completed\n", tt + 1);
		}
	}	
	return 0;
}