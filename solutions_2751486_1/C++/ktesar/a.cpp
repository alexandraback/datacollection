#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

char line[1111111];
int l, n;
int pref[1111111];
int cnt[1111111];

bool isvowel(char c) {
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return true;
	else return false;
}

void solve() {
	scanf(" %s%d", line, &n);
	l = strlen(line);
	int x = 0;
	int last = -1;
	ll ans = 0;
	REP(i, l) {
		if (!isvowel(line[i])) x++;
		else x = 0;
		if (x>=n) {
			last = i;
		}
		if (last!=-1) {
			ans += (ll)last-n+2;
		}
		//printf("%d %d %d\n", x, last, ans);
	}
	printf("%lld\n", ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	REP (i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
