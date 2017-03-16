#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;
 
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)
#define EACH(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
 
typedef long long i64;
typedef pair<int, int> PI;
 
#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))
 
#define PB push_back
#define MP make_pair
#define X first
template<class T> void fmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void fmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> T sqr(const T &a) { return a * a; }

i64 A, a[999], s[999];
int n;

int main() {
	int CNT;
	cin >> CNT;
	rep(cnt, CNT) {
		cin >> A >> n;
		int ans = n;
		FOR(i, 1, n) cin >> a[i];
		sort(a + 1, a + 1 + n);
		s[0] = 0;
		FOR(i, 1, n) s[i] = s[i - 1] + a[i];
		int tmp = 0;
		if (A != 1)
		FOR(i, 1, n) {
			ans = min(ans, tmp + n - i + 1);
			if (A > a[i]) {
				A += a[i];
				continue;
			}
			else {
				while (A <= a[i]) A += A - 1, tmp ++;
				A += a[i];
			}
		}
		if (A != 1)
			ans = min(ans, tmp);
		cout << "Case #" << cnt+1 << ": ";
		cout << ans;
		cout << endl;
	}
}