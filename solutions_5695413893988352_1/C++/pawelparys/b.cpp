#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define INIT(a, v) __typeof(v) a = (v)
#define FOREACH(a, v) for (INIT(a, (v).begin()); a!=(v).end(); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long LL;

#define INF 1000000000
#define PB push_back
#define MP make_pair
 
//////////////////////////////////////////

char buf1[20], buf2[20];
int N;

LL best[20][3];
LL wyn1[20][3];
LL wyn2[20][3];

void popraw(int a, int r, LL mod, LL w1, LL w2) {
    LL b = abs(mod + w1 - w2);
    if (b > best[a][r])
        return;
    if (b == best[a][r]) {
        if (w1 > wyn1[a][r])
            return;
        if (w1 == wyn1[a][r] && w2 > wyn2[a][r])
            return;
    }
    best[a][r] = b;
    wyn1[a][r] = w1;
    wyn2[a][r] = w2;
}

void licz() {
    scanf("%s%s", buf1, buf2);
    N = strlen(buf1);
    reverse(buf1, buf1+N);
    reverse(buf2, buf2+N);
    wyn1[0][0] = wyn1[0][1] = wyn1[0][2] = wyn2[0][0] = wyn2[0][1] = wyn2[0][2] = 0;
    best[0][0] = 0;
    best[0][1] = best[0][2] = 1;
    LL mn = 1;
    REP(a, N) {
        best[a+1][0] = best[a+1][1] = best[a+1][2] = INF*(LL)INF+10;
        REP(c1, 10) {
            if (buf1[a] != '?' && buf1[a] != c1 + '0')
                continue;
            REP(c2, 10) {
                if (buf2[a] != '?' && buf2[a] != c2 + '0')
                    continue;
                int p = c1 == c2 ? 0 : c1 > c2 ? 1 : 2;
                popraw(a + 1, 0, 0, c1 * mn + wyn1[a][p], c2 * mn + wyn2[a][p]);
                popraw(a + 1, 1, 10 * mn, c1 * mn + wyn1[a][1], c2 * mn + wyn2[a][1]);
                popraw(a + 1, 2, -10 * mn, c1 * mn + wyn1[a][2], c2 * mn + wyn2[a][2]);
            }
        }
        mn *= 10;
    }
    printf("%.*lld %.*lld\n", N, wyn1[N][0], N, wyn2[N][0]);
}


int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        printf("Case #%d: ", (tt+1));
        licz();
    }
}


