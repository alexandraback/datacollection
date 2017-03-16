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

int k, l, s;
string alphabet, need;
int ans = 0, all = 0;
string now = "";
int maxAns = 0;

void go(int pos) {
    if (pos == s) {
        ++all;
        int add = 0;
        for (int i = 0; i <= s - l; i++) {
            if (now.substr(i, l) == need) {
                ++add;
            }
        }
        maxAns = max(maxAns, add);
        ans += add;
        return;
    }
    for (int i = 0; i < k; i++) {
        now[pos] = alphabet[i];
        go(pos + 1);
    }
}

int main()
{
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    int testsCount;
    scanf("%d", &testsCount);
    for (int testNumber = 1; testNumber <= testsCount; ++testNumber) {
        printf("Case #%d: ", testNumber);
        scanf("%d%d%d", &k, &l, &s);
        cin >> alphabet;
        cin >> need;
        ans = 0;
        all = 0;
        maxAns = 0;
        now = "";
        for (int i = 0; i < s; i++)
            now += 'a';
        go(0);
        printf("%.10f\n", maxAns - ans * 1.0 / all);
    }
    return 0;
}