#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000
#define INF 1000000000

int a[10][10];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d\n", &test);
	for (int test1 = 0; test1 < test; test1++) {
		memset(a, sizeof(a), 0);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				char ch;
				scanf("%c", &ch);
				if (ch == '.')
					a[i][j] = -1;
				if (ch == 'X')
					a[i][j] = 1;
				if (ch == 'O')
					a[i][j] = 0;
				if (ch == 'T')
					a[i][j] = 100;
			}
			scanf("\n");
		}
		string ans = "";
		int k = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (a[i][j] != -1)
					k++;
				if (j + 3 < 4) {
					vector < int > b;
					b.push_back(a[i][j]);
					b.push_back(a[i][j + 1]);
					b.push_back(a[i][j + 2]);
					b.push_back(a[i][j + 3]);
					sort(b.begin(), b.end());
					if (b[0] == b[1] && b[1] == b[2] && (b[3] == b[0] || b[3] == 100)) {
						if (b[0] == 1)
							ans = "X won";
						else if (b[0] == 0)
							ans = "O won";
					}
				}
				
				if (i + 3 < 4) {
					vector < int > b;
					b.push_back(a[i][j]);
					b.push_back(a[i + 1][j]);
					b.push_back(a[i + 2][j]);
					b.push_back(a[i + 3][j]);
					sort(b.begin(), b.end());
					if (b[0] == b[1] && b[1] == b[2] && (b[3] == b[0] || b[3] == 100)) {
						if (b[0] == 1)
							ans = "X won";
						else if (b[0] == 0)
							ans = "O won";
					}
				}

				if ((i == 0 && j == 0)) {
					vector < int > b;
					b.push_back(a[0][0]);
					b.push_back(a[1][1]);
					b.push_back(a[2][2]);
					b.push_back(a[3][3]);
					sort(b.begin(), b.end());
					if (b[0] == b[1] && b[1] == b[2] && (b[3] == b[0] || b[3] == 100)) {
						if (b[0] == 1)
							ans = "X won";
						else if (b[0] == 0)
							ans = "O won";
					}
				}

				if (i == 0 && j == 3) {
					vector < int > b;
					b.push_back(a[0][3]);
					b.push_back(a[1][2]);
					b.push_back(a[2][1]);
					b.push_back(a[3][0]);
					sort(b.begin(), b.end());
					if (b[0] == b[1] && b[1] == b[2] && (b[3] == b[0] || b[3] == 100)) {
						if (b[0] == 1)
							ans = "X won";
						else if (b[0] == 0)
							ans = "O won";
					}
				}
				

			}

			if (ans == "") {
				if (k != 16) {
					printf("Case #%d: Game has not completed\n", test1 + 1);
				} else
					printf("Case #%d: Draw\n", test1 + 1);

			} else {
				printf("Case #%d: ", test1 + 1);
				cout << ans << endl;
			}
	}

	return 0;
}