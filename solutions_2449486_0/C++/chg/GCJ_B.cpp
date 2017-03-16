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
int n, m;
int val[2][N][N];

bool gao(int use, int n, int m) {
	int (*lawn)[N] = val[use];
	int (*nxt)[N] = val[1 - use];
	if (n == 0 || m == 0) return true;
	int r = 0;
	int c = 0;
	int v = lawn[r][c];

//	puts("");
//	forn (i, n) {
//		forn (j, m) {
//			printf("%d ", lawn[i][j]);
//		}
//		puts("");
//	}

	forn (i, n) forn (j, m) {
		if (lawn[i][j] < v) {
			r = i;
			c = j;
			v = lawn[i][j];
		}
	}
	bool flag;
	flag = true;
	forn (i, n) {
		if (lawn[i][c] != v) {
			flag = false;
			break;
		}
	}
	if (flag) {
		forn (i, n) forn (j, m) {
			if (j == c) continue;
			int jj = (j < c) ? j : (j - 1);
			nxt[i][jj] = lawn[i][j];
		}
		return gao(1 - use, n, m - 1);
	}

	flag = true;
	forn (j, m) {
		if (lawn[r][j] != v) {
			flag = false;
			break;
		}
	}
	if (flag) {
		forn (i, n) forn (j, m) {
			if (i == r) continue;
			int ii = (i < r) ? i : (i - 1);
			nxt[ii][j] = lawn[i][j];
		}
		return gao(1 - use, n - 1, m);
	}
	return false;
}

void solve() {
	scanf("%d%d", &n, &m);
	forn (i, n) forn (j, m)
		scanf("%d", &val[0][i][j]);
	if (gao(0, n, m)) puts("YES");
	else puts("NO");
}

int main() {
//	freopen("in.txt","r",stdin);
//	freopen("D:\\in.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
