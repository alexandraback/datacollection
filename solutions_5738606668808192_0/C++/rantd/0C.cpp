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

ll bs[11][17];

ll mod_mul(ll x, ll y, ll p) {
    x %= p, y %= p;
    ll res = 0;
    while (y > 0) {
      if(y & 1) {
            res += x;
            if(res >= p) res -= p;
        }
        x <<= 1, y >>= 1;
        if(x >= p) x -= p;
    }
    return res;
}

ll mod_pow(ll x, ll y, ll p) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = mod_mul(res, x, p);
        x = mod_mul(x, x, p);
        y >>= 1;
    }
    return res;
}

bool is_prime(ll n) {
    if (n < 2) return false;
    static int a[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (int i = 0; i < 9; ++i) {
        if (n % a[i] == 0){
            if (n == a[i]) return true;
            else return false;
        }
    }
    ll d = n - 1;
    int s = 0;
    while (d & 1 == 0) {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < 9; ++i) {
        ll x = mod_pow(a[i], d, n);
        if (x == 1 || x == n - 1) continue;
        bool pass = false;
        for (int j = 1; j < s; ++j) {
            x = mod_mul(x, x, n);
            if (x == 1) return false;
            if (x == n - 1) {
                pass = true;
                break;
            }
        }
        if (pass) continue;
        return false;
    }
    return true;
}

ll val[11];
typedef pair<string, vector<ll>> P;

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);

    REPU(i, 2, 11) {
        bs[i][0] = 1;
        REPU(j, 1, 17) bs[i][j] = i * bs[i][j - 1];
    }

    int noTest, N, J;
    
    cin >> noTest;
    REPU(it, 1, noTest + 1) {
        cin >> N >> J;
        vector<P> ans;
        REPU(msk, 0, 1 << (N - 2)) {
            if (ans.size() >= J) break;
            bool ok = true;
            REPU(i, 2, 11) val[i] = bs[i][0] + bs[i][N - 1];
            string num(N, '1');
            REPU(i, 0, N - 2) {
                if (msk & (1 << i)) {
                    REPU(b, 2, 11) val[b] += bs[b][i + 1];
                }
                else num[i + 1] = '0';
            }
            REPU(i, 2, 11) {
                if (is_prime(val[i])) {
                    ok = false; break;
                }
            }
            if (!ok) continue;
            vector<ll> divs(9);
            REPU(i, 2, 11) {
                ll x = (ll) sqrt(val[i] + 0.5);
                REPU(d, 2, x + 1) {
                    if (val[i] % d == 0) {
                        divs[i - 2] = d; break;
                    }
                }
            }
            reverse(ALL(num));
            ans.push_back(P(num, divs));
        }
        printf("Case #%d:\n", it);
        REPU(i, 0, J) {
            printf("%s ", ans[i].first.c_str());
            REPU(j, 0, 9) printf("%lld%c", ans[i].second[j], " \n"[j == 8]);
        }
    }
	
	return 0;
}
