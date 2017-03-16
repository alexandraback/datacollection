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

int L;
long long X;
char a[120010];
int s[120010];

inline int multi(int x, int y) {
	int minus = x / 4 + y / 4;
	x %= 4, y %= 4;
	int z;
	if (x == 0 || y == 0) {
		z = x + y;
		if (minus % 2 == 1)
			z += 4;
		return z;
	}
	if (x > y) {
		swap(x, y);
		minus += 1;
	}
	if (x == 1) {
		if (y == 1)
			z = 4;
		if (y == 2)
			z = 3;
		if (y == 3)
			z = 6;
		if (minus % 2 == 1)
			z = (z + 4) % 8;
		return z;
	}
	if (x == 2) {
		if (y == 2)
			z = 4;
		if (y == 3)
			z = 1;
		if (minus % 2 == 1)
			z = (z + 4) % 8;
		return z;
	}

	if (x == 3) {
		z = 4;
		if (minus % 2 == 1)
			z = (z + 4) % 8;
		return z;
	}
	return -1;
}

void work() {
	cin >> L >> X;
	//scanf("%d %d", &L, &X);
	scanf("%s", a + 1);
	if (X >= 8)
		X = X % 4 + 8;
	if (X == 0) {
		printf("NO\n");
		return;
	}
	for (int i = L + 1; i <= L * X; ++i) 
		a[i] = a[i - L];
	s[0] = 0;
	int minI = 1000000, maxK = -1;
	for (int i = 1; i <= L * X; ++i) {
		int cur = 1;
		if (a[i] == 'j')
			cur = 2;
		if (a[i] == 'k')
			cur = 3;
		s[i] = multi(s[i - 1], cur);
		if (s[i] == 1 && i < minI)
			minI = i;
		if (s[i] == 3 && i > maxK)
			maxK = i;
	}
	//for (int i = 0; i <= L * X; ++i)
	//	printf("%d", s[i]);
	//printf("\n");
	if (s[L * X] == 4 && maxK != -1 && minI != -1 && minI < maxK) {
		printf("YES\n");
	}else {
		printf("NO\n");
	}
}


int main() {
	#ifdef LOCAL_JUDGE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif // LOCAL_JUDGE

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		work();
	}
 	
	return 0;
}