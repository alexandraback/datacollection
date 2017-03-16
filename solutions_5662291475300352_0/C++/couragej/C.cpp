#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int MAXN = 1e3 + 10;
const double eps = 1e-8;

int N, D[MAXN], H[MAXN], M[MAXN];

void Solve() {
    cin >> N;
    vector<PII> a;
    REP(i, N) {
        scanf("%d%d%d", D + i, H + i, M + i);
        REP(j, H[i]) a.PB(MP(D[i], M[i] + j));
    }
    if (SIZE(a) == 1) puts("0");
    else {
        assert(SIZE(a) == 2);
        SORT(a);
        if (a[0].first == a[1].first) {
            if (1ll * (360 - a[1].first) * a[1].second >= 1ll * (720 - a[0].first) * a[0].second) puts("1");
            else puts("0");
        } else {
            if (a[0].second > a[1].second) swap(a[0], a[1]);
            if (a[0].second == a[1].second) puts("0");
            else if (1ll * (360 - a[1].first) * a[1].second >= 1ll * (720 - a[0].first) * a[0].second) puts("1");
            else puts("0");
        }
    }

}

int main() {
//	freopen("C.in","r",stdin);
	freopen("C-small-1-attempt2.in","r",stdin);freopen("C-small-1-attempt2.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}

