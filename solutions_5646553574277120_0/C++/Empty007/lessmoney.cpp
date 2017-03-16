#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

int C[40], V[40];

int main() { 

    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    REP(tc, T) {

        int c, d, v;
        cin >> c >> d >> v;
        CLR(C, 0);
        vector <int> S;
        REP(i, d) {
            int x;
            cin >> x;
            C[x] = 1;
            S.pb(x);
        }

        int need = 0;
        int F[5] = {1, 2, 4, 8, 16};
        int id = 0;

        while (true) {
            int n = S.size();
            CLR(V, 0);
//            REP(i, n) {
//                dbg2(i, S[i]);
//            }
            REP(i, (1<<n)) {
                int sum = 0;
                REP(j, n) if (i & (1<<j)) {
                    sum += S[j];
                }
                if (sum <= v) V[sum] = 1;
            }
            bool bo = true;
            int l = -1;
            REPN(i, 1, v+1) if (!V[i]) {
                if (l == -1) l = i;
//                dbg(i);
                bo = false;
            }
            if (bo) break;
            S.pb(l);
//            REP(i, 5) if (!C[F[i]]) {
//                C[F[i]] = 1;
//                S.pb(F[i]);
//                break;
//            }
            need++;
//            dbg(need);
        }

        cout << "Case #" << tc+1 << ": " << need <<"\n";
    }

	return 0;
}



