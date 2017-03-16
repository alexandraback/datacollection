#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;

void readInt(int &x) {
	x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + c - '0';
}

void readSignedInt(int &x) {
	x = 0;
	bool minus = false;
	char c = getchar();
	for (; c != '-' && (c < '0' || c > '9'); c = getchar());
	if (c == '-')
		minus = true, c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + c - '0';
	if (minus)
		x = -x;
}

int X, R, C;

bool work() {
	cin >> X >> R >> C;
	if (X > 4)
		return false;
	if (X == 1)
		return true;
	if (X == 2)
		return R * C % 2 == 0;
	if (X == 3)
		return (R % 3 == 0 && C >= 2 || R >= 2 && C % 3 == 0);
	if (X == 4)
		return (R % 4 == 0 && C >= 3 || R >= 3 && C % 4 == 0);
	return false;
}

int main() {
	#ifdef LOCAL_JUDGE
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	#endif // LOCAL_JUDGE

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		if (work())
			printf("GABRIEL\n");
		else
			printf("RICHARD\n");
	}
 	
	return 0;
}