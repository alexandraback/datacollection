#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define what_is(x) cerr << #x << ": " << x << endl;

#define file "f"

typedef long long ll;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

inline int rev(int x) {
    int ans = 0;
    while (x != 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

const int kMaxn = 1000001;

int d[kMaxn];
int T, n;

int main() {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);

    scanf("%d", &T);
    forn(_t, T) {
        scanf("%d", &n);

        forn(i, kMaxn)
            d[i] = kMaxn;
        d[1] = 1;

        int z;
        for (int i = 1; i < n; i++) {
            d[i + 1] = min(d[i + 1], d[i] + 1);
            z = rev(i);
            d[z] = min(d[z], d[i] + 1);
        }

        printf("Case #%d: %d\n", _t + 1, d[n]);
    }
}
