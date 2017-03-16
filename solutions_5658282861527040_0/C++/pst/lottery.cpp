#include <bits/stdc++.h>
using namespace std;

#define All(a) a.begin(), a.end()
#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define Fore(i,c) for (int i = 0; i < int((c).size()); ++i)
#define Mem(a,v) memset((a), (v), sizeof(a))
#define Sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = (1 << 30);
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int A, B, K;
        cin >> A >> B >> K;
        LL ans = 0;
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < B; ++j)
                if ((i & j) < K) ++ans;
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}