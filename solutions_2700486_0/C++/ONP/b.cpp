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

const long double pi = acos(-1.);
const long double eps = 1e-6;

long double C(int a, int b)
{
	if (a < b) return 0;
	long double s = 1;
	for (int i = 1; i <= b; i++)
		s = s * ((long double)a - i + 1) / (long double)i;
	return s;
}
long double calc(int n, int top, int y)
{
//	C(n, y)+C(n,y+1)... / 2^n
	long double total = 0;
	for (int i = 0; i <= top; i++) {
		if (n - i <= top)
			total += C(n, i);
	}
	long double s = 0;
	for (int i = y + 1; i <= top; i++) {
		if (n - i <= top && i <= n)
			s += C(n, i);
	}
	return s / total;
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		int n, x, y, r;
		scanf("%d%d%d", &n, &x, &y);
		for (int i = 1; ; i += 2) {
			if ((i * (i + 1)) / 2 > n) {
				r = i - 2;
				n -= ((i - 2) * (i - 1)) / 2;
				break;
			}
		}
		int ty = r + 1, tx = 0;
		long double p;
		if (y > ty) {
			p = 0;
		} else {
			if (x + y < tx + ty && y - x < ty - tx)
				p = 1;
			else if (x + y == tx + ty || y - x == ty - tx) {
				p = calc(n, ty, y);
			} else p = 0;
		}
		printf("Case #%d: %.9f\n", ++ca, (double)p);
	}
}
