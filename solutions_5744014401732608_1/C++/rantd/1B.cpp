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

const int N = 55;
ll p[N];
int a[N][N];

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
	int nTest, B;
	ll M;

	p[0] = 1;
	REPU(i, 1, N) p[i] = p[i - 1] * 2;

	cin >> nTest;
	REPU(it, 1, nTest + 1) {
		printf("Case #%d: ", it);
		cin >> B >> M;
		if (M > p[B - 2]) {
			puts("IMPOSSIBLE"); continue;
		}
		REPU(i, 0, N) fill(a[i], a[i] + N, 0);
		REPU(i, 1, B) REPU(j, i + 1, B) a[i][j] = 1;
		REPD(i, B - 1, 0) {
			int ind = i > 1 ? i - 2 : 0;
			if (M >= p[ind]) {
				M -= p[ind];
				a[i][B] = 1;
			}
		}
		puts("POSSIBLE");
		REPU(i, 1, B + 1) {
			REPU(j, 1, B + 1) {
				printf("%d", a[i][j]);
				if (j == B) puts("");
			}
		}
	}
	
	return 0;
}
