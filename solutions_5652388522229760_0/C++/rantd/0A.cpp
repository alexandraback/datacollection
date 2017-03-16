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

bool vis[10];

void check(ll x, int &cnt) {
    while (x) {
        int d = x % 10;
        if (!vis[d]) {
            vis[d] = 1, cnt++;
        }
        x /= 10;
    }
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
    int noTest, n;
    
    cin >> noTest;
    REPU(it, 1, noTest + 1) {
        cin >> n;
        ll ans = 0;
        if (n > 0) {
            ll x = n;
            int cnt = 0;
            MEM(vis, 0);
            while (cnt < 10) {
                ans = x;
                check(x, cnt); x += n;
            }
        }
        if (ans == 0) printf("Case #%d: INSOMNIA\n", it);
        else printf("Case #%d: %lld\n", it, ans);
    }
	
	return 0;
}
