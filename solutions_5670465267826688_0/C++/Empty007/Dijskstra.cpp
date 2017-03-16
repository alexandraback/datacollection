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

typedef long long ll;

int P[1010];

int main() {

    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    int M[6][6];
    M[1][1] = 1; M[1][2] = 2; M[1][3] = 3; M[1][4] = 4;
    M[2][1] = 2; M[2][2] = -1; M[2][3] = 4; M[2][4] = -3;
    M[3][1] = 3; M[3][2] = -4; M[3][3] = -1; M[3][4] = 2;
    M[4][1] = 4; M[4][2] = 3; M[4][3] = -2; M[4][4] = -1;

    map <char, int> MP;
    MP['i'] = 2;
    MP['j'] = 3;
    MP['k'] = 4;

    REP(tc, T) {
        int n;
        ll x;
        string S;
        cin >> n >> x;
        cin >> S;
        string G;


        REP(i, x) {
            G += S;
        }

        int sz = x*n;
        int sign = 0; //1 negative
        int cur = 1;
        int besti = -1;
        REP(i, sz) {
            cur = M[cur][MP[G[i]]];
            if (cur <= 0) sign ^= 1, cur *= -1;
            if (cur == 2 && sign == 0 && besti == -1) besti = i;
//            dbg3(i, cur, sign);
        }

        if (cur != 1 || sign != 1 || besti == -1) {
            cout << "Case #" << tc+1 << ": NO\n";
            continue;
        }

        int bestk = -1; 
        sign = 0;
        cur = 1;
        for (int i = sz-1; i >= 0; i--) {
            cur = M[MP[G[i]]][cur];
            if (cur <= 0) sign ^= 1, cur *= -1;
//            dbg3(i, cur, sign);
            if (cur == 4 && sign == 0) {
                bestk = i;
                break;
            }
        }

        if (bestk != -1 && bestk > besti)
            cout << "Case #" << tc+1 << ": YES\n";
        else 
            cout << "Case #" << tc+1 << ": NO\n";
    }
	
	return 0;
}



