#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)(x).size())
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define x first
#define y second
#define INF (0x3f3f3f3f)

typedef long long LL;
typedef pair<int, int> P2;
template<class A, class B> inline bool mina(A &x, B y) {return (x > y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return (x < y)?(x=y,1):0;}

const int MAXR = 1000005;
const int MAXN = 35;
const int MAXP = 100;
int N, J;

bool is_prime(LL x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
vector<int> primes;

vector<int> xx;
vector<vector<int>> ans2;

bool bad(int n, int base) {
    vector<int> binary;
    int nn = n;
    REP(i, N - 2) {
        binary.PB(n % 2);
        n /= 2;
    }

    for (auto p : primes) {
        int r = 1;
        for (int i = N - 3; i >= 0; i--) {
            r *= base;
            r += binary[i];
            r %= p;
        }
        r *= base;
        r++;
        r %= p;
        if (r == 0) {
            xx.PB(p);
            return false;
        }
    }
    return true;
}

bool not_prime[MAXR];


void solve() {
    vector<int> ans;
    for (int i = 0; i < (1LL<<(N - 2)) && i < MAXR; i++) {
        bool good = true;
        xx.clear();
        for (int b = 2; b <= 10; b++) {
            if (bad(i, b)) {
                good = false;
                break;
            }
        }
        if (good) {
            ans.PB(i);
            ans2.PB(xx);
            if (SZ(ans) == J) break;
        }
    }
    REP(i, SZ(ans)) {
        printf("1");
        cout << bitset<14>(ans[i]);
        printf("1");
        for (int x : ans2[i]) cout << " " << x;
        cout << endl;
    }
}

int main() {
    for (int i = 2; i * i < MAXR; i++) {
        if (!not_prime[i]) {
            for (int j = i * 2; j < MAXR; j += i)
                not_prime[j] = true;
        }
    }

    for (int i = 3; i < MAXR; i++) {
        if (!not_prime[i]) {
            primes.PB(i);
            if (SZ(primes) > MAXP) break;
        }
    }
    int test;
    cin >> test;
    REP(tt, test) {
        printf("Case #%d:\n", tt + 1);
        cin >> N >> J;
        solve();
    }

    return 0;
}
