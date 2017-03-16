#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
char s[1000];
int a[6][6];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin >> test;
	bool u1, u2;
	for (int tt =  1 ; tt <= test; tt++) {
		gets(s); int l = 0;
		for (int i = 1; i <= 4; i++) {
			char h;
			for (int j = 1; j <= 4; j++) {
				scanf("%c", &h);
				switch (h)  {
					case 'X' : a[i][j] = 1; break;
					case '.' : a[i][j] = 0; l++; break;
					case 'T' : a[i][j] = 3; break;
					case 'O' : a[i][j] = 2; break;
				
				}
				//if (tt == 481) cout << h << endl;
			}
			gets(s);
		}
		u1 = false; u2 = false;
		int dir[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
		int c[5];
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j ++) {
				if (i == 1 || j == 1) {
					
					for (int dd = 0; dd < 4; dd++) {
						memset(c, 0, sizeof(c));
						int x = i, y = j;
						for (int k = 1; k <= 4; k++) {
							c[a[x][y]]++;
							x += dir[dd][0];
							y += dir[dd][1];
							if (x < 1 || x > 4 || y < 1 || y > 4) break;
						}
						if (c[3] + c[2] == 4) u1 = true;
						if (c[3] + c[1] == 4) u2 = true;
					}
				}
			}
		}
		printf("Case #%d: ", tt);
		/*if (tt == 481) {
			for (int i = 1; i <= 4; i++) {
				for (int j = 1; j <= 4; j++) 
					printf("%d", a[i][j]);
				printf("\n");
			}
		}*/
		if (u1 && u2) printf("Draw"); 
		else if (u1) printf("O won");
		else if (u2) printf("X won");
		else if (l > 0) printf("Game has not completed"); else printf("Draw");
		printf("\n");
	}
	return 0;
}
