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
    int K, C, S;
    cin >> K >> C >> S;
    int need = (K + C - 1) / C;
    if (need > S) {
        puts(" IMPOSSIBLE");
    } else {
        for (int i = 0; i < K; i += C) {
            LL ps = 0;
            int t = i;
            REP(j, C) {
                ps = ps * K + t;
                t = min(t + 1, K - 1);
            }
            cout << " " << ps + 1;
        }
        puts("");
    }
}

int main() {
    //	freopen("D.in","r",stdin);
//    	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
    // 	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
    // 	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
    	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d:", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}


