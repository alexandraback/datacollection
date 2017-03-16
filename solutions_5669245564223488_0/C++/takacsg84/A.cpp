#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>
#include <time.h>
#include <assert.h>
#include <limits>
#include <sstream>

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))


using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    LL tmp;
    while (b) {
        a %= b;
        tmp = a;
        a = b;
        b = tmp;
    }
    return a;
}

void doStuff() {
    string s;
    cin >> s;
    LL a = 0, b = 0;
    int i = 0;
    while (s[i] != '/') a = a * 10 + s[i] - '0', ++i;
    ++i;
    while (i < s.length()) b = b * 10 + s[i] - '0', ++i;
    LL g = gcd(a, b);
    a /= g, b /= g;
    while (a > 1) {
        if (b & 1) {
            cout << "impossible" << endl;
            return;
        }
        a /= 2, b /= 2;
    }
    LL result = 0;
    while (b != 1) {
        if (b & 1) {
            cout << "impossible" << endl;
            return;
        }
        b /= 2, result++;
    }
    cout << result << endl;
}

int main() {
    int T;
    scanf("%d", &T);
    REP(t, T) printf("Case #%d: ", t + 1), doStuff();
    return 0;
}