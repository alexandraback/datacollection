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
    int n, m, K;
    cin >> n >> m >> K;
    if (n > m) swap(n, m);
    int ans = K;
    if (n > 2) {
        for (int a = 1; a < n - 1; ++a) {
            for (int b = a; b < m - 1; ++b) {
                int s = a + a + b + b;
                if (a * b + s >= K) {
                    ans = min(ans, s);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
    //	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
    //	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
    //	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
    }
    return 0;
}

