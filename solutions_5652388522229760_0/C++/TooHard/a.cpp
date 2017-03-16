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

const int MAXI = 100;

void update(int N, set<int> &d) {
    string s = to_string(N);
    for (char c : s) {
        d.insert(c - '0');
    }
}

void solve() {
    int N;
    cin >> N;
    set<int> digits;
    update(N, digits);
    int last = N;
    for (int i = 1; SZ(digits) != 10 && i <= MAXI; i++) {
        update(N * i, digits);
        last = i * N;
    }
    if (last == N * MAXI) {
        printf("INSOMNIA\n");
    } else {
        printf("%d\n", last);
    }

}

int main() {
    int test;
    cin >> test;
    REP(tt, test) {
        printf("Case #%d: ", tt + 1);
        solve();
    }

    return 0;
}
