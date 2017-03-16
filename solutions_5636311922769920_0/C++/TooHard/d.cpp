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

const int MAXN = 105;

void solve() {
    LL K, C, S;
    cin >> K >> C >> S;
    if (S == K) {
        REP(i, K) {
            LL cur = i;
            REP(j, C - 1) {
                cur *= K;
                cur += i;
            }
            cout << " " << cur + 1;
        }
    } else {
        printf(" I don't know.");
    }
    cout << endl;
}

int main() {
    int test;
    cin >> test;
    REP(tt, test) {
        printf("Case #%d:", tt + 1);
        solve();
    }

    return 0;
}
