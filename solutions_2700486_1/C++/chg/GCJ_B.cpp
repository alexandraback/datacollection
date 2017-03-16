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

const int N = 1510;
int n, x, y;
double dp[N][N];

double gao(int n, int x, int y) {
	int z = (x + y) / 2 + 1;
	if (z > 750) return 0.0;
	int H = z * 2 - 1;
	int t1 = (z - 1) * (z * 2 - 3);
	int t2 = z * H;
	if (n <= t1) return 0.0;
	if (n >= t2) return 1.0f;
	int rest = n - t1;
//	printf("%d %d\n", rest, H);
//	forn (i, H) forn (j, H)
//		dp[i][j] = 0;
	clr(dp, 0);
	dp[0][0] = 1.0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < H; ++j) {
			if (i + j > rest) continue;
			if (i == H - 1) {
				dp[i][j + 1] += dp[i][j];
			} else if (j == H - 1) {
				dp[i + 1][j] += dp[i][j];
			} else {
				dp[i + 1][j] += dp[i][j] * 0.5;
				dp[i][j + 1] += dp[i][j] * 0.5;
			}
		}
	}
	double ans = 0.0;
	forn (i, H) {
		if (i > y && rest - i < H)
			ans += dp[i][rest - i];
	}
	return ans;
}

void solve() {
	scanf("%d%d%d", &n, &x, &y);
	if (x < 0) x = -x;
	printf("%.8lf\n", gao(n, x, y));
}

int main() {
//	freopen("in.txt","r",stdin);
//	freopen("D:\\in.txt","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);//freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
