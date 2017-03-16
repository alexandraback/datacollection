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
    REP(tc, T) {

        int n;
        cin >> n;
        REP(i, n) cin >> P[i];

        int best = (1<<30);
        
        REPN(b, 1, 1001) {
            int minutes = 0;
            REP(i, n) {
                minutes += (P[i]+b-1)/b - 1;
            }
            best = min(minutes + b, best);
        }

        cout << "Case #" << tc+1 << ": " << best <<"\n";
    }
	
	return 0;
}


