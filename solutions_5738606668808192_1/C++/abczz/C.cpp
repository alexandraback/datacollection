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

void Solve() {
    int a[32], N, J;
    int div[9] = {3, 2, 3, 2, 7, 2, 3, 2, 3};
    cin >> N >> J;
    a[N - 1] = a[0] = 1;
    for (int i = 1; i < N - 1; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N - 1; ++k) {
                for (int t = k + 1; t < N - 1; ++t) {
                    if (i % 2 + j % 2 + k % 2 + t % 2 != 2) continue;
                    for (int p = 1; p < N - 1; ++p) {
                        a[p] = (p == i || p == j || p == k || p == t);
                    }
                    REP(p, N) {
                        printf("%d", a[p]);
                    }
                    REP(p, 9) {
                        printf(" %d", div[p]);
                    }
                    cout << endl;
                    if (--J == 0) {
                        return;
                    }
                }
            }
        }
    }

}

int main() {
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d:\n", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}

