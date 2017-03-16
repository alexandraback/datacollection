#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define foreach(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define sqr(x) ((x)*(x))
#define clr(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
int dcmp(double x) { if (x < -eps) return -1; else return x > eps;}
#define se(x) cout<<#x<<" = "<<x<<endl

const int N = 110;
int z, n;
int a[N];

void solve() {
	scanf("%d%d", &z, &n);
	forn (i, n) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
//	printf("%d:", z);
//	forn (i, n) {
//		printf("%d, ", a[i]);
//	}
//	puts("");
	if (z == 1) {
		printf("%d\n", n);
		return;
	}
	int ans = n;
	int cnt = 0;
	forn (i, n) {
		if (z > a[i]) {
			z += a[i];
			continue;
		}
		ans = min(ans, cnt + n - i);
		while (z <= a[i]) {
			z += z - 1;
			cnt++;
		}
		z += a[i];
	}
	ans = min(cnt, ans);
	printf("%d\n", ans);
}

int main() {
//	freopen("in.txt","r",stdin);
//	freopen("D:\\in.txt","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
