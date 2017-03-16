#include <string.h>
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
typedef pair<int, int> PII;
typedef vector<PII> VPII;

void doStuff() {
    double C, F, X, prod = 2, t = 0;
    scanf("%lf%lf%lf", &C, &F, &X);
    double result = X / 2.0;
    while (true) {
        double step = C / prod;
        if (t + step + X / (prod + F) < result) t += step, prod += F, result = t + X / prod;
        else break;
    }
    printf("%1.7f\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    REP(t, T) printf("Case #%d: ", t + 1), doStuff();
    return 0;
}