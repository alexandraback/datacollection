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
int X, Y;

bool good(int steps) {
    return false;
}

string doStuff() {
    int X, Y;
    vector<char> vc;
    cin >> X >> Y;
    while (X > 0) vc.push_back('W'), vc.push_back('E'), --X;
    while (X < 0) vc.push_back('E'), vc.push_back('W'), ++X;
    while (Y > 0) vc.push_back('S'), vc.push_back('N'), --Y;
    while (Y < 0) vc.push_back('N'), vc.push_back('S'), ++Y;
    string result;
    result.resize(vc.size());
    REP(i, vc.size()) result[i] = vc[i];
    return result;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    REP(t, T) cout << "Case #" << t + 1 << ": " << doStuff() << endl;
    cout.flush();
    return 0;
}