#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

#define FOR(i,a,n) for(int i = (int)a; i < (int)n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ALL(c) c.begin(), c.end()
#define CLEAR(c,v) memset(c,v,sizeof(c))

typedef long long int lli;
typedef pair<int,int> ii;

int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    FOR(tcase, 1, T + 1) {
        int X, Y;
        cin >> X >> Y;
        
        cout << "Case #" << tcase << ": ";
        bool pos = X > 0;
        pos = !pos;
        REP(i, 2*abs(X)) {
            cout << (pos ? 'E' : 'W');
            pos = !pos;
        }
        pos = Y > 0;
        pos = !pos;
        REP(i, 2*abs(Y)) {
            cout << (pos ? 'N' : 'S');
            pos = !pos;
        }

        cout << endl;
    }

    return 0;
}

