#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define SETMIN(a,b) a = min(a,b)
#define SETMAX(a,b) a = max(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define CLR(x,a) memset(x,a,sizeof(x))
#define BEND(v) v.begin(),v.end()
#define MP make_pair
#define A first
#define B second

#define INF 0x7FFFFFFF

int tenpow(int x) {
    if (x == 0) return 1;
    if (x == 1) return 10;
    if (x == 2) return 100;
    if (x == 3) return 1000;
    if (x == 4) return 10000;
    if (x == 5) return 100000;
    if (x == 6) return 1000000;

    cout << "FAILURE" << endl;
    exit(0);

    /*
    int n = 1;
    for (int i = 0; i < x; i++) {
        n *= 10;
    }
    return n;
    */
}

int digcount(int x) {
    if (x < 10) return 1;
    if (x < 100) return 2;
    if (x < 1000) return 3;
    if (x < 10000) return 4;
    if (x < 100000) return 5;
    if (x < 1000000) return 6;
    if (x < 10000000) return 7;

    cout << "FAILURE" << endl;
    exit(0);

    /*
    if (x == 0) return 1;

    int count = 0;
    while (x != 0) {
        count++;
        x /= 10;
    }
    return count;
    */
}

typedef unsigned long long int ull;
typedef long double ld;

int casenum = 1;

void doit() {
    int A, B;
    cin >> A >> B;

    int counter = 0;

    for (int n = A; n <= B; n++) {
        int ndigs = digcount(n);

        int done[10];
        done[0] = n;

        for (int i = 1; i < ndigs; i++) {
            int m = n / tenpow(i) + (n % tenpow(i)) * tenpow(ndigs - i);

            bool uniq = true;

            for (int j = 0; j < i; j++) {
                if (done[j] == m) {
                    uniq = false;
                }
            }
            done[i] = m;

            if (A <= n && n < m && m <= B && digcount(m) == ndigs && uniq) {
                counter++;
            }
        }
    }

    printf("Case #%d: %d\n", casenum++, counter);
}

int main() {
    int ZZZ;
    cin >> ZZZ;
    while(ZZZ--) {
        doit();
    }
}
