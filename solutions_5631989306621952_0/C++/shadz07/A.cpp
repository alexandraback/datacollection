#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 2123123123
#define pb push_back
using namespace std;

int main() {
	int T;
	char st[1005];
	string ans;

	scanf("%d", &T);

	FORU(tc, 1, T) {
		scanf("%s", st);

		ans = st[0];
		int len = strlen(st);

		FORU(i, 1, len - 1) {
			if (st[i] >= ans[0]) {
				ans = st[i] + ans;
			}
			else {
				ans = ans + st[i];
			}
		}

		printf("Case #%d: %s\n", tc, ans.c_str());
	}

	return 0;
}
