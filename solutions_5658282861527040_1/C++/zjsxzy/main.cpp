#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAX = 31;
LL dp[MAX+1][2][2][2];
vector<int> dA, dB, dC;

vector<int> getBit(int x) {
	vector<int> bit(MAX);
	for (int i = 0; i < MAX; i++) {
		bit[i] = (x & (1 << i)) != 0;
	}
	return bit;
}

long long rec(int pos, int eqA, int eqB, int eqC) {
	if (dp[pos][eqA][eqB][eqC] != -1) return dp[pos][eqA][eqB][eqC];
	long long & res = dp[pos][eqA][eqB][eqC];
	res = 0;
	if (pos == 0) return res = 1;
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++) {
			int z = x & y;
			if ((!eqA || x <= dA[pos - 1]) && (!eqB || y <= dB[pos - 1]) && (!eqC || z <= dC[pos - 1])) {
				res += rec(pos - 1, eqA && x == dA[pos - 1], eqB && y == dB[pos - 1], eqC && z == dC[pos - 1]);
			}
		}
	return res;
}

int main() {
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		int A, B, K;
		cin >> A >> B >> K;
		A--; B--; K--;
		dA = getBit(A); dB = getBit(B); dC = getBit(K);
		memset(dp, -1, sizeof(dp));
		LL res = rec(MAX, 1, 1, 1);
		cout << res << endl;
	}
	return 0;
}

