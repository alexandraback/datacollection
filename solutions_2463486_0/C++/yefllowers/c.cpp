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

bool OK(long long n) {
	int a[20], l = 0;
	while (n) a[l++] = n % 10, n /= 10;
	rep(i, l / 2) if (a[i] != a[l - 1 - i]) return false;
	return true;
}

vector<long long> A;

int main() {
	for (long long i = 1; i <=  10000000; i++)
	if (OK(i) && OK(i * i))
		A.PB(i * i);
	int CNT;
	cin >> CNT;
	rep(cnt, CNT) {
		long long a, b;
		cin >> a >> b;
		int ans = 0;
		rep(i, sz(A)) ans += a <= A[i] && A[i] <= b;
		cout << "Case #" << cnt + 1 << ": " << ans << endl;
	}
}