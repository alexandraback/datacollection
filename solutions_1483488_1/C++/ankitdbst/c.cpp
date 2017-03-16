//      anks
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;
#define debug(args...) dbg(),args
#define S(N) scanf("%d", &N)
#define SS(N) scanf("%s", N)
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);)
#define MEM(A,B) memset(A,B,sizeof(A))
#define MAX(A,B) ((A > B) ? A : B)
#define MIN(A,B) ((A < B) ? A : B)
#define MAXLIM 1000001
bool DBG;
struct dbg { template<typename T> dbg& operator , (const T& v) { if (DBG)
 cerr << v << " "; return *this; } ~dbg() { if (DBG) cerr << endl; } };

bool samedig(int n1, int n2) {
    int x = (int)log10(n1), y = (int)log10(n2);
    return (x==y);
}

int circular(int n1, int n2) {
    int multiplier = pow(10, (int)log10(n1)), num = n1, count = 0;
    do {
        int r = num%10;
        num /= 10;
        num += r*multiplier;
        if (num > n1 && num <= n2 && samedig(n1, num)) {
            count++;
        }
    } while (num != n1);

    return count;
}

int main (int argc, char *argv[]) {
    DBG = (argc > 1 && *argv[1]);

    int t;
    S(t);

    FOR(i, 0, t) {
        int a, b;
        S(a); S(b);
        int count = 0;
        FOR(j, a, b) {
            count += circular(j, b);
        }
        printf("Case #%d: %d\n", i+1, count);
    }

    return 0;
}
