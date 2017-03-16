// a Hewr
#include <iostream>
#include <cstdio>
using namespace std;

int a[4][4];

int main() {
	freopen("a.in", "r", stdin);
	int CA;
	cin >> CA;
	for (int Ca = 1; Ca <= CA; ++Ca) {
		char ch;
		for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
			do { cin >> ch; } while (ch != 'X' && ch != 'T' && ch != 'O' && ch != '.');
			if (ch == 'X') {
				a[i][j] = 1;
			} else 
			if (ch == 'T') {
				a[i][j] = 3;
			} else 
			if (ch == 'O') {
				a[i][j] = 2;
			} else {
				a[i][j] = 0;
			}
		}

		int flag(0);

		// row
		for (int i = 0; i < 4; ++i) {
			int own(-1), cntT = 0;
			bool legal(1);
			for (int j = 0; j < 4; ++j) {
				if (a[i][j] == 3) {
					++cntT;
					if (cntT > 1) {
						legal = 0;
						break;
					}
					continue;
				}
				if (a[i][j] == 0 || (own != -1 && a[i][j] != own)) {
					legal = 0;
					break;
				}
				own = a[i][j];
			}
			if (legal) {
				flag = own;
				break;
			}
		}
		if (flag) {
			printf("Case #%d: %c won\n", Ca, flag == 1 ? 'X' : 'O');
			continue;
		}

		// column
		for (int j = 0; j < 4; ++j) {
			int own(-1), cntT = 0;
			bool legal(1);
			for (int i = 0; i < 4; ++i) {
				if (a[i][j] == 3) {
					++cntT;
					if (cntT > 1) {
						legal = 0;
						break;
					}
					continue;
				}
				if (a[i][j] == 0 || (own != -1 && a[i][j] != own)) {
					legal = 0;
					break;
				}
				own = a[i][j];
			}
			if (legal) {
				flag = own;
				break;
			}
		}
		if (flag) {
			printf("Case #%d: %c won\n", Ca, flag == 1 ? 'X' : 'O');
			continue;
		}

		// diag1
		int own(-1), cntT = 0;
		bool legal(1);
		for (int i = 0; i < 4; ++i) {
			if (a[i][i] == 3) {
				++cntT;
				if (cntT > 1) {
					legal = 0;
					break;
				}
				continue;
			}
			if (a[i][i] == 0 || (own != -1 && a[i][i] != own)) {
				legal = 0;
				break;
			}
			own = a[i][i];
		}
		if (legal) {
			printf("Case #%d: %c won\n", Ca, own == 1 ? 'X' : 'O');
			continue;
		}
		
		// diag2
		own = -1, cntT = 0;
		legal = 1;
		for (int i = 0; i < 4; ++i) {
			if (a[i][3 - i] == 3) {
				++cntT;
				if (cntT > 1) {
					legal = 0;
					break;
				}
				continue;
			}
			if (a[i][3 - i] == 0 || (own != -1 && a[i][3 - i] != own)) {
				legal = 0;
				break;
			}
			own = a[i][3 - i];
		}
		if (legal) {
			printf("Case #%d: %c won\n", Ca, own == 1 ? 'X' : 'O');
			continue;
		}

		flag = 0;
		for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) if (a[i][j] == 0) {
			flag = 1;
			break;
		}
		if (flag == 1) 
			printf("Case #%d: Game has not completed\n", Ca);
		else	printf("Case #%d: Draw\n", Ca);
	}
}
