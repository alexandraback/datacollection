#define TASKNAME "text"

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

template <typename T>
T sqr(T x) {
    return x * x;
}

template <typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

bool was[500];

void go(vi &x, int pos, int sum) {
    if (pos == sz(x)) {
        was[sum] = true;
        return;
    }
    go(x, pos + 1, sum + x[pos]);
    go(x, pos + 1, sum);
}

int main()
{
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    int testsCount;
    scanf("%d", &testsCount);
    for (int testNumber = 1; testNumber <= testsCount; ++testNumber) {
        printf("Case #%d: ", testNumber);
        int c, d, v;
        scanf("%d%d%d", &c, &d, &v);
        vi x(d);
        for (int i = 0; i < d; i++) {
            cin >> x[i];
        }
        memset(was, 0, sizeof(was));
        go(x, 0, 0);

        int ans = 0;
        for (int i = 1; i <= v; i++) {
            if (!was[i]) {
                ++ans;
                x.pb(i);
                vi newx;
                newx.pb(i);
                for (int j = 1; j <= v; j++) {
                    if (was[j] && !was[i + j]) {
                        x.pb(i + j);
                        newx.pb(i + j);
                    }
                }
                for (int y : newx) {
                    was[y] = true;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}