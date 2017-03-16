#include <bits/stdc++.h>
using namespace std;

#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define FOREACH(it, a) for (auto it = a.begin(); it != a.end(); ++it)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> inline T tabs(T a) { return (a > 0) ? a : -a; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

const int N = 1005;
string a[N], b[N];

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
	int nTest, n;

	cin >> nTest;
	REPU(it, 1, nTest + 1) {
		cin >> n;
		REPU(i, 0, n) cin >> a[i] >> b[i];
		int ans = 0;
		REPU(i, 1, (1 << n)) {
			int cnt = 0;
			REPU(j, 0, n) if (i & (1 << j)) {
				bool ft = false, sn = false;
				REPU(k, 0, n) if (!(i & (1 << k))) {
					if (a[j] == a[k]) ft = true;
					if (b[j] == b[k]) sn = true;
				}
				if (ft && sn) cnt++;
			}
			amax(ans, cnt);
		}
		printf("Case #%d: %d\n", it, ans);
	}
	
	return 0;
}
