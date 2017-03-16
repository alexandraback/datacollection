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
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)

string tot;
int szK, szW, sztot, ban;
string K, W;
double res, p;

void go(int pos, string G) {
    if (pos == sztot) {
        int need = 0;
        REP(i, sztot) {
            if (i+szW <= sztot && G.substr(i, szW) == W) need++;
        }
        res += (ban-need)*1.0/p;
//        dbg3(pos, G, (ban-need)*1.0/p);
//        dbg3(ban, need, res);
        return ;
    }
    REP(i, szK) {
        string NG = G+K[i];
        go(pos+1, NG);
    }
}

int main() { 

    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    REP(tc, T) {
        cin >> szK >> szW >> sztot;
        cin >> K;
        cin >> W;

        set <char> keys;
        REP(i, szK) keys.insert(K[i]);
        bool bo = true;
        REP(i, szW) if (!keys.count(W[i])) bo = false;
        if (!bo) {
            cout << "Case #" << tc+1 << ": 0.0\n"; 
            continue;
        }

        string nor = W;
        REPN(i, 1, szW) {
            if (W.substr(i) == W.substr(0, szW - i)) {
                nor = W.substr(0, i);
                break;
            }
        }
        tot = "";
        while (tot.length() < sztot) {
            tot += nor;
        }

        tot = tot.substr(0, sztot);
//        dbg(tot);

        ban = 0;
        REP(i, sztot) {
            if (i+szW <= sztot && tot.substr(i, szW) == W) ban++;
        }
//        dbg(ban);
        
        res = 0;
        p = 1;
        REP(i, sztot) p *= szK;
//        dbg(p);
        go(0, "");
        
        cout << "Case #" << tc+1 << ": "; 
        coud(res, 8);
        cout << "\n";
    }

	return 0;
}


