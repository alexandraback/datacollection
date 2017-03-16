#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x) {}
#   define E(x) {}
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

random_device rdev; mt19937 rmt(rdev()); uniform_int_distribution<> rnd(0, 0x7fffffff);
inline int mrand(int mod = 0x7fffffff) { return rnd(rmt) % mod; }

const int maxn = 100500 * 10;
int dist[maxn];

int64 rev(int64 value) {
    int64 res = 0;
    while (value) {
        res *= 10;
        res += value % 10;
        value /= 10;
    }
    return res;
}

int que[maxn];
void  pre() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 1;
    que[0] = 1;
    int fr = 0, bc = 1;
    while (fr < bc) {
        int cur = que[fr++];
        for (int q = 0; q < 2; ++q) {
            int next = (q == 0 ? cur + 1 : rev(cur));
            if (next >= maxn) continue;
            if (dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                que[bc++] = next;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    pre();

    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        int n; cin >> n;
        cout << "Case #" << test << ": " << dist[n] << endl;
    }

    return 0;
}
