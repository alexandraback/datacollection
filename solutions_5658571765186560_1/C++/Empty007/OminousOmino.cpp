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

int main() {

    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    REP(tc, T) {

        int X, R, C;
        cin >> X >> R >> C;
        int maxi = max(R, C);
        int mini = min(R, C);
        if (X <= 4) {
            if (maxi < (X+2)/2 || mini < (X+1)/2 || (R*C)%X != 0 || (X == 4 && mini == 2 && maxi == 4))
                cout << "Case #" << tc+1 << ": RICHARD\n";
            else 
                cout << "Case #" << tc+1 << ": GABRIEL\n";
        }
        else {
            if (X >= 7 || mini < 5 || maxi < X || (R*C)%X != 0)
                cout << "Case #" << tc+1 << ": RICHARD\n";
            else 
                cout << "Case #" << tc+1 << ": GABRIEL\n";
        }
    }
	
	return 0;
}


