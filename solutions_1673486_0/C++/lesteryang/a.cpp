#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sof(x) sizeof(x)
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define maxn 100100
double p[maxn], q[maxn];
int A, B;
double ans;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while(T--) {
        cin >> A >> B;
        double tmp = 1.0;
        for(int i = 0; i < A; i++) cin >> p[i];
        for(int i = 0; i < A; i++) {
            tmp *= p[i];
            q[i] = tmp;
        }
        ans = 1e100;
        ans = min(tmp * (B - A + 1.0) + (2.0 * B + 2.0 - A) * (1.0 - tmp), B + 2.0);
        for(int i = 0; i < A; i++) {
            ans = min(ans, (B + A - 2.0 * i - 1.0) * q[i] + (2 * B + A - 2.0 * i) * (1.0 - q[i]));
        }
        printf("Case #%d: %.7lf\n", Case++, ans);
    }
    return 0;
}
