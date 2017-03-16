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

typedef long long i64;
typedef pair<int, int> PI;

#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))
#define each(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define PB push_back
#define MP make_pair
#define X first
#define Y second

template<class T> void fmax(T &a, T b) { if (a < b) a = b; }
template<class T> void fmin(T &a, T b) { if (a > b) a = b; }

int n, m, a[111][111];
bool A[111][111];

int main() {
	int CNT;
	cin >> CNT;
	rep(cnt, CNT) {
		cin >> n >> m;
		rep(i, n) rep(j, m) cin >> a[i][j];
		memset(A, 0, sizeof(A));
		bool flag = false;
		rep(i, n) {
			int w = 1;
			rep(j, m) fmax(w, a[i][j]);
			rep(j, m) A[i][j] = w > a[i][j];
		}
		rep(j, m) {
			int w = 1;
			rep(i, n) fmax(w, a[i][j]);
			rep(i, n) flag |= w > a[i][j] && A[i][j];
		}
		cout << "Case #" << cnt+1 << ": ";
		if (flag) cout << "NO";
		else cout << "YES";
		cout << endl;
	}
}