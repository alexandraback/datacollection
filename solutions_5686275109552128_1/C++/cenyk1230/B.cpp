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

int n;
int a[1010];

bool check(int mid) {
	for (int i = 0; i < mid; ++i) {
		int t = mid - i;
		int needSpecial = 0;
		for (int j = 1; j <= n; ++j) {
			needSpecial += (a[j] - 1) / t;
			if (needSpecial > i)
				break;
		}
		if (needSpecial <= i)
			return true;
	}
	return false;
}

void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	int l = 0, r = a[1] + 1, mid;
	//cout << check(7) << endl;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}

int main() {
	#ifdef LOCAL_JUDGE
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	#endif // LOCAL_JUDGE

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		work();
	}
 	
	return 0;
}