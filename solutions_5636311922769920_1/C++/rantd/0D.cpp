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

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	
    int noTest, K, C, S;

    cin >> noTest;
    REPU(it, 1, noTest + 1) {
        cin >> K >> C >> S;
        printf("Case #%d: ", it);
        int visible = min(K, C);
        int need = (K + visible - 1) / visible;
        if (S < need) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        vector<ll> ans;
        REPU(i, 0, need) {
            int from = K * i / need, to = K * (i + 1) / need;
            ll x = 0;
            REPU(j, from, to) x = x * K + j;
            ans.push_back(x + 1);
        }
        sort(ALL(ans)); UNIQUE(ans);
        REPU(i, 0, ans.size()) printf("%lld%c", ans[i], " \n"[i == ans.size() - 1]);
    }
	
	return 0;
}
