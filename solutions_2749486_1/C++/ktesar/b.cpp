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

int x, y;
ll d[1111111];
int p[1111111];

void solve() {
	scanf("%d%d",&x, &y);
	int z = ABS(x)+ABS(y);
	ll tmp = 0;
	int k = 0;		// pocet kroku
	int par = 0;
	while (tmp<z || par!=z%2) {
		tmp += ++k;
		d[k] = tmp;
		par = (par+k)%2;
		p[k] = par;
	}
	stack<char> ans;
	while (k>0) {
		if (ABS(x-k)+ABS(y)<=d[k-1]) {
			x -= k;
			ans.push('E');
		}
		else if (ABS(x+k)+ABS(y)<=d[k-1]) {
			x += k;
			ans.push('W');
		}
		else if (ABS(x)+ABS(y-k)<=d[k-1]) {
			y -= k;
			ans.push('N');
		}
		else if (ABS(x)+ABS(y+k)<=d[k-1]) {
			y += k;
			ans.push('S');
		}
		else printf("ERROR\n");
		k--;
	}
	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	printf("\n");
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
