#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 10000 + 5;
const int signCalcMap[4][4] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};
int signMul[8][8];
int n, strInt[maxn], first[maxn], last[maxn];
LL repeat;
char str[maxn];

// [0,1,2,3,4,5,6,7]->[1,i,j,k,-1,-i,-j,-k]
int sign2int(char x) {
	if (x == '1') return 0;
	if (x == 'i') return 1;
	if (x == 'j') return 2;
	if (x == 'k') return 3;

}

int mul0(int val1, int val2) {
	int sign = 0;
	if (val1 >= 4) val1 -= 4, sign ^= 1;
	if (val2 >= 4) val2 -= 4, sign ^= 1;
	int res = signCalcMap[val1][val2];
	if (sign) res += 4;
	if (res >= 8) res -= 8;
	return res;
}

int mul(int val1, int val2) {
	return signMul[val1][val2];
}

int Pow(int val, LL p) {
	p = p % 4;
	int res = 0;
	for (int i = 0; i < p; i++) 
		res = mul(res, val);
	return res;
}

void init() {
	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)
		signMul[i][j] = mul0(i, j);
}

int segMul[maxn][maxn];
int work() {
	first[0] = strInt[0];
	for (int i = 1; i < n; i++) first[i] = mul(first[i - 1], strInt[i]);
	last[n] = 0;
	for (int i = n - 1; i >= 0; i--) last[i] = mul(strInt[i], last[i + 1]);

	for (int i = 0; i < n; i++)
	for (int j = i; j < n; j++)
		segMul[i][j] = i == j ? strInt[i] : mul(segMul[i][j - 1], strInt[j]);

	int iInt = sign2int('i');
	int jInt = sign2int('j');
	int kInt = sign2int('k');
	for (int X1 = 0; X1 < 4; X1++) {
		// X2 = -1
		LL X3 = repeat - X1 - 1;
		if (X3 < 0)
			continue;
		int seg1 = Pow(first[n - 1], X1);
		int seg3 = Pow(first[n - 1], X3);
		for (int Y1 = 0; Y1 < n; Y1++)
		for (int Y2 = Y1 + 1; Y2 < n; Y2++) {
			int val1 = mul(seg1, first[Y1]);
			int val2 = segMul[Y1 + 1][Y2];
			int val3 = mul(last[Y2 + 1], seg3);
			if (val1 == iInt && val2 == jInt && val3 == kInt)
				return 1;
		}
	}

	for (int X1 = 0; X1 < 4; X1++)
	for (int X2 = 0; X2 < 4; X2++) {
		LL X3 = repeat - X1 - X2 - 2;
		if (X3 < 0)
			continue;
		int seg1 = Pow(first[n - 1], X1);
		int seg2 = Pow(first[n - 1], X2);
		int seg3 = Pow(first[n - 1], X3);
		for (int Y1 = 0; Y1 < n; Y1++)
		for (int Y2 = 0; Y2 < n; Y2++) {
			int val1 = mul(seg1, first[Y1]);
			int val2 = mul(mul(last[Y1 + 1], seg2), first[Y2]);
			int val3 = mul(last[Y2 + 1], seg3);
			if (val1 == iInt && val2 == jInt && val3 == kInt)
				return 1;
		}
	}

	return 0;
}

int main() {
//freopen("in", "r", stdin);
//freopen("large.in", "r", stdin);
//freopen("C-small-attempt1.in", "r", stdin);
//freopen("C-small-attempt1.out", "w", stdout);
	init();
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %lld", &n, &repeat);
		scanf("%s", str);
		for (int i = 0; i < n; i++)
			strInt[i] = sign2int(str[i]);

		int res = work();
		printf("Case #%d: %s\n", ti, res ? "YES" : "NO");
	}
	return 0;
}
