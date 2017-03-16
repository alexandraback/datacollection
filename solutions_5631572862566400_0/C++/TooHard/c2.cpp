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


const int MAXN = 1005;


int fff[MAXN];

int in[MAXN];

void solve() {
    int N;
    cin >> N;
    int bbf;
    REP(i, N) {
        cin >> bbf;
        bbf--;
        fff[i] = bbf;
    }
    REP(i, N) {
        in[i] = i;
    }
    int ans = 0;
    do {
        REP(i, N) {
            bool good = true;
            if (i == 0) continue;
            REP(j, i + 1) {
                int p1 = in[(j - 1 + (i + 1)) % (i + 1)];
                int p2 = in[(j + 1) % (i + 1)];
                if (fff[in[j]] == p1 || fff[in[j]] == p2) {

                } else {
//                    REP(i, N) cout << in[i] << " ";
//                    cout << endl;
//                    cout << in[i] << " " << fff[in[i]] << " " << p1 << " " << p2 << endl;
                    good = false;
//                    if (i == 3)
//                        exit(0);
                    break;
                }
            }
            if (good) maxa(ans, i + 1);
        }
    } while (next_permutation(in, in + N));

    cout << ans << endl;
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
