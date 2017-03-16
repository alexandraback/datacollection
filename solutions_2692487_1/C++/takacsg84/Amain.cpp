#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>
#include <numeric>
#include <limits.h>
#include <limits>
#include <iterator>
#include <iomanip>
#include <bitset>
#include <assert.h>

using namespace std;

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

typedef long long LL;

LL doStuff() {
    LL AA, N, result;
    cin >> AA >> N, result = N;
    vector<LL> motes(N);
    REP(i, N) cin >> motes[i];
    if (AA == 1) return N;
    sort(ALL(motes));

    REP(k, N) {
        LL temp = k, A = AA;

        REP(i, N - k) {
            while (A <= motes[i]) A += A - 1, temp++;
            A += motes[i];
        }

        //fprintf(stderr, "Result with removing %i : %i\n", k, temp);
        result = min(temp, result);
    }
    return result;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    REP(t, T) cout << "Case #" << t + 1 << ": " << doStuff() << endl;
    cout.flush();
    return 0;
}