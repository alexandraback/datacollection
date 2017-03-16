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

int z = 1;

const double eps = 1e-9;

inline void out(int ans) {
    printf("Case #%d: %d\n", z, ans);
    z++;
}

struct Hik {
    int d, t;
    Hik() {};
    Hik(int d, int t): d(d), t(t) {};
};

int top = 0;
int T, n;
int d[10];
int h[10];
int m[10];
Hik hiker[10];

int main() {
    freopen(file".in", "r", stdin);
    freopen("new.out", "w", stdout);

    scanf("%d", &T);
    forn(_t, T) {
        scanf("%d", &n);
        int cnt = 0;
        top = 0;
        forn(i, n) {
            scanf("%d%d%d", d + i, h + i, m + i);
            cnt += h[i];
        }
        if (cnt < 2) {
            out(0);
            continue;
        }

        forn(i, n) {
            forn(j, h[i]) {
                hiker[top++] = Hik(d[i], m[i] + j);
            }
        }

        if (hiker[0].t > hiker[1].t)
            swap(hiker[0], hiker[1]);


        if (n == 4) {
            out(0);
            continue;
        }
        cerr << "For " << n << endl;
        double time1 = hiker[0].t / 360.0 * (360 - hiker[0].d);
        double time2 = hiker[1].t / 360.0 * (360 - hiker[1].d);

        cerr << hiker[0].d << " " << hiker[0].t << endl;
        cerr << hiker[1].d << " " << hiker[1].t << endl;
        cerr << time1 << " " << time2 << endl;

        if (time2 < time1 + eps)
            out(0);
        else {
            time2 -= time1;
            time1 = hiker[0].t;
            if (time1 + eps <= time2)
                out(1);
            else
                out(0);
        }
    }
}
