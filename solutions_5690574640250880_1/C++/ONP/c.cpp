#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-6;

int n, m, M;
char a[200][200];
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d%d", &n, &m, &M);
//		if (n > m) swap(n, m);
		printf("Case #%d:\n", ++ca);
		int emp = n * m - M;
		if (n == 1 || m == 1) {
			int first = 1, mines = n * m;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (first) {
						printf("c");
					} else if (mines > M)
						printf(".");
					else
						printf("*");
					mines--;
					first = false;
				}
				puts("");
			}
		} else if (emp == 2 || emp == 3 || emp == 5 || emp == 7) {
			puts("Impossible");
		} else if (emp == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i + j == 0)
						printf("c");
					else
						printf("*");
				}
				puts("");
			}
		} else if ((n == 2 || m == 2) && emp % 2 != 0) {
			puts("Impossible");
		} else {
			bool flag = false;
			bool rev = false;
			if (n > m) {
				rev = 1;
				swap(n, m);
			}
			for (int i = 1; i < n; i++)
				for (int j = 1; j < m; j++) {
//					if (i == n - 1 && j == m - 2)
	//					cout << "!"<<endl;
					if (flag) break;
					if ((i + 1) * (j + 1) == emp) {
						flag = true;
						for (int x = 0; x < n; x++)
							for (int y = 0; y < m; y++)
								a[x][y] = '*';
						for (int x = 0; x <= i; x++)
							for (int y = 0; y <= j; y++)
								a[x][y] = '.';
						break;
					}
					int l = (i + 1) * (j + 1) + 2;
					int r = (i + 1) * (j + 1) + j;
					if (l <= emp && emp <= r) {
						flag = true;
						for (int x = 0; x < n; x++)
							for (int y = 0; y < m; y++)
								a[x][y] = '*';
						for (int x = 0; x <= i; x++)
							for (int y = 0; y <= j; y++)
								a[x][y] = '.';
						int rest = emp - (i + 1) * (j + 1);
						for (int y = 0; y <= j; y++) {
							rest--;
							a[i + 1][y] = '.';
							if (!rest) break;
						}
						break;
					}
				}
			if (!flag) {
				for (int x = 0; x < n; x++)
					for (int y = 0; y < m; y++)
						a[x][y] = '.';
				int rest = M;
				for (int x = n - 1; x > 1; x--)
					for (int y = m - 1; y > 1; y--) {
						if (rest <= 0) break;
						rest--;
						a[x][y] = '*';
					}
				if (rest == 0)
					flag = 1;
			}
			a[0][0] = 'c';
			if (rev) {
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						printf("%c", a[j][i]);
					}
					puts("");
				}
			} else {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						printf("%c", a[i][j]);
					}
					puts("");
				}
			}
		}
	}
}
