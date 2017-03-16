#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define ll long long
#define pb push_back 
#define mp make_pair
#define FOR(x, l, r) for(x = (l); x <= (r); x++)
#define FORD(x, r, l) for(x = (r); x >= (l); x --)
using namespace std;
int a[100][100];
int main()
{
	int tt, cas = 0, n, m, n1, m1, num, i, j, num1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	cin >> tt;
	while (tt --) {
		printf("Case #%d:\n", ++cas);
		memset(a, 0, sizeof(a));
		cin >> n1 >> m1 >> num;
		//cout << n1 << " " << m1 << endl;
		n = min(n1, m1); m = max(n1, m1); num1 = num;
		num = n * m - num;
		if (n == 1) {
			for (i = 1; i <= num; i ++) a[1][i] = 1;
		}
		if (n == 2) {
			if (num != 1)
			if (num % 2 == 1 || num == 2) { printf("Impossible\n");  continue; }
			for (i = 1; i <= num; i ++) a[2 - i % 2][(i - 1)/ 2 + 1] = 1;
		}
		if (n >= 3) {
			if (num == 3 || num == 5 || num == 7 || num == 2) { printf("Impossible\n");  continue; }
			if (num == 1) a[1][1] = 1;
			else if (num == 4) {a[1][1] = a[1][2] = a[2][1] = a[2][2] = 1; }
			else if (num == 6) {a[1][1] = a[1][2] = a[2][1] = a[2][2] = a[1][3] = a[2][3] = 1; }
			else {
				a[1][1] = a[1][2] = a[2][1] = a[2][2] = a[1][3] = a[2][3] = a[3][1] = a[3][2] = 1;
				num -= 8;
				for (i = 4; i <= n; i ++)
					if (num >= 2) a[i][1] = a[i][2] = 1, num -= 2;
					else break;
				for (i = 4; i <= m; i ++)
					if (num >= 2) a[1][i] = a[2][i] = 1, num -= 2;
					else break;
				for (i = 3; i <= n; i ++)
					for (j = 3; j <= m; j ++)
						if (num) a[i][j] = 1, num --;
			}
		}
		printf("c");
		for (i = 1; i <= n1; i ++) {
			for (j = 1; j <= m1; j ++)
				if (i != 1 || j != 1)
				if (n1 != n) {
					if (a[j][i]) putchar('.');
					else putchar('*');
				}
				else {
					if (a[i][j]) putchar('.');
					else putchar('*');
				}
			 putchar('\n');
		}
	}
	return 0;
}
