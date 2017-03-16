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
#define BIG 1000000000
#define LL long long
using namespace std;

int ntest;
LL A, B, C;
int a[110], b[110], c[110];
LL f[110][2][2][2];

LL go(int at, int topA, int topB, int topC) {
	if (at < 0) return 1;
	LL &ans = f[at][topA][topB][topC];
	if (ans != -1) return ans;
	ans = 0;
	int upA = 1;
	if (!topA) upA = a[at];
	int upB = 1;
	if (!topB) upB = b[at];
	int upC = 1;
	if (!topC) upC = c[at];
	for (int i = 0; i <= upA; i++)
		for (int j = 0; j <= upB; j++)
			for (int k = 0; k <= upC; k++)
				if ((i & j) == k) ans += go(at - 1, topA | (i < a[at]), 
													topB | (j < b[at]),
													topC | (k < c[at]));
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> ntest;
	for (int test = 1; test <= ntest; test++) {
		cin >> A >> B >> C;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		A--;
		B--;
		C--;
		for (int i = 0; i < 32; i++) {
			a[i] = (A >> i) & 1;
			b[i] = (B >> i) & 1;
			c[i] = (C >> i) & 1;
		}
		//for (int i = 0; i < 31; i++) cout << c[i] << ' '; cout << endl;
		memset(f, -1, sizeof(f));
		cout << "Case #" << test << ": " << go(31, 0, 0, 0) << endl;
	}
}

