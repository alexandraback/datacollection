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

ll D[100], H[100], M[100];

int main() { 

    int T;
    cin >> T;

    REP(tc, T) {

        int n;
        cin >> n;
        REP(i, n) {
            cin >> D[i] >> H[i] >> M[i];
        }
        if (n == 1 && H[0] == 2) {
            n = 2;
            D[1] = D[0];
            M[1] = M[0]+1;
        }
        if (n == 1 || M[0] == M[1]) 
            cout << "Case #" << tc+1 << ": 0\n";
        else {
            if (M[0] > M[1]) {
                swap(M[0], M[1]);
                swap(D[0], D[1]);
            }
//            dbg2(M[0], M[1]);
            ll falta0 = 360-D[0];
            ll falta1 = 360-D[1];
//            dbg2(falta0, falta1);
//            dbg2(D[0], D[1]);
//            dbg2(M[0]*falta0 + 360*M[0], M[1]*falta1);
            if (M[0]*falta0 + 360*M[0] <= M[1]*falta1)
                cout << "Case #" << tc+1 << ": 1\n";
            else
                cout << "Case #" << tc+1 << ": 0\n";
        }
    }

	return 0;
}


