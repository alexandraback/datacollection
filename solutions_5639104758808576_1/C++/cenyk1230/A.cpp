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
char a[1005];

void work() {
	scanf("%d %s", &n, a);
	int sum = 0, ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (a[i] > '0' && sum < i) {
			ans += (i - sum);
			sum = i;
		}
		sum += a[i] - '0';
	}
	cout << ans << endl;
}

int main() {
	#ifdef LOCAL_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif // LOCAL_JUDGE

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		work();
	}
 	
	return 0;
}

