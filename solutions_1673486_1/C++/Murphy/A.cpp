#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

double P[102400];

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);
    //cin>>caseNumber;
    REP(caseN, caseNumber) {
        int A, B;
        scanf("%d%d", &A, &B);
        REP(i, A) {
            scanf("%lf", P + i);
        }
        double exp = 0;
        exp = 2 + B;
        double p = 1;
        REP(i, A + 1) {
            exp = min(exp, A - i + B - i + 1 + ((1 - p) * (B + 1)));
            p *= P[i];
        }
        printf("Case #%d: %.8lf\n", caseN + 1, exp);
    }
    return 0;
}
