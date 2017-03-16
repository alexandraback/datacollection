#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

#define REP(i, n) for(int i=0; i<n; ++i)
#define ST first
#define ND second
#define PB push_back
#define VAR(v,n) __typeof__(n) v=(n)
#define FE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define MAXN 300

int S[MAXN];

int n, X;

bool canLose(int s, double p){
    double sScore = S[s] + p * X;
    double r = X - p * X;
    REP(i, n) if ( i != s ){
        double diff = sScore - S[i];
        if ( diff > 0 ) {
            if ( diff > r ) return false;
            r -= diff;
        }
    }
    return true;
}

double bs(int s, double a, double b){
    REP(i, 150){
        double c = (a + b) / 2.0;
        if ( canLose( s, c ) ) a = c;
        else b = c;
    }
    return a;
}

void testcase(){
    scanf("%d", &n);
    REP(i, n) scanf("%d", &S[i]);
    X = 0;
    REP(i, n) X += S[i];
    REP(i, n){
        printf(" %lf", 100.0 * bs(i, 0.0, 1.0));
    }
}

int main(){
int z; scanf("%d", &z);
REP(i, z) {
    printf("Case #%d:", i+1);
    testcase();
    printf("\n");
}
return 0;
}

