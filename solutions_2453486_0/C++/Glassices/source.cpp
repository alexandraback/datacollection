#include <iostream>
using namespace std;

char a[10][10];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int step = 1; step <= T; step++) {
		for (int i = 0; i < 4; i++) cin >> a[i];
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			if (flag) break;
			flag = 1;
			for (int j = 0; j < 4; j++)
				if (a[i][j] != 'X' && a[i][j] != 'T') {
					flag = 0;
					break;
				}
		}
		for (int j = 0; j < 4; j++) {
			if (flag) break;
			flag = 1;
			for (int i = 0; i < 4; i++)
				if (a[i][j] != 'X' && a[i][j] != 'T') {
					flag = 0;
					break;
				}
		}
		if (! flag) {
			flag = 1;
			for (int i = 0; i < 4; i++)
				if (a[i][i] != 'X' && a[i][i] != 'T') {
					flag = 0;
					break;
				}
		}
		if (! flag) {
			flag = 1;
			for (int i = 0; i < 4; i++)
				if (a[i][3-i] != 'X' && a[i][3-i] != 'T') {
					flag = 0;
					break;
				}
		}
		if (flag) {
			cout << "Case #" << step << ": X won" << endl;
			continue;
		}
		flag = 0;
		for (int i = 0; i < 4; i++) {
			if (flag) break;
			flag = 1;
			for (int j = 0; j < 4; j++)
				if (a[i][j] != 'O' && a[i][j] != 'T') {
					flag = 0;
					break;
				}
		}
		for (int j = 0; j < 4; j++) {
			if (flag) break;
			flag = 1;
			for (int i = 0; i < 4; i++)
				if (a[i][j] != 'O' && a[i][j] != 'T') {
					flag = 0;
					break;
				}
		}
		if (! flag) {
			flag = 1;
			for (int i = 0; i < 4; i++)
				if (a[i][i] != 'O' && a[i][i] != 'T') {
					flag = 0;
					break;
				}
		}
		if (! flag) {
			flag = 1;
			for (int i = 0; i < 4; i++)
				if (a[i][3-i] != 'O' && a[i][3-i] != 'T') {
					flag = 0;
					break;
				}
		}
		if (flag) {
			cout << "Case #" << step << ": O won" << endl;
			continue;
		}
		flag = 1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (a[i][j] == '.')
					flag = 0;
		if (flag)
			cout << "Case #" << step << ": Draw" << endl;
		else
			cout << "Case #" << step << ": Game has not completed" << endl;
	}
	return 0;
}

