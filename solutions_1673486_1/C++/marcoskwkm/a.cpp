#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define debug(args...) fprintf(stderr,args);

typedef long long lint;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXA = 100100;

double ch[MAXA];
double acc[MAXA];
double ret[MAXA];

int main() {
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        int A,B;
        scanf("%d%d",&A,&B);
        for(int a=1;a<=A;++a) scanf("%lf",&ch[a]);
        acc[0] = 1;
        for(int a=1;a<=A;++a) {
            acc[a] = acc[a-1]*ch[a];
        }
        ch[A+1] = 0;
        for(int a=0;a<=A+1;++a) ret[a] = 0;
        for(int a=1;a<=A+1;++a) { //onde errei primeiro
            double prob = acc[a-1]*(1-ch[a]);
            for(int b=1;b<=a;++b) { //ate onde vou apagar, dando certo
                ret[b] += ((A-b+1) + (B-b+1) + 1)*prob;
            }
            for(int b=a+1;b<=A+1;++b) { //ate onde vou apagar, dando errado
                ret[b] += ((A-b+1) + (B-b+1) + 1 + B + 1)*prob;
            }
        }
        double ans = INF;
        for(int a=1;a<=A+1;++a) ans = min(ans,ret[a]);
        printf("Case #%d: %.6lf\n",t,min(ans,double(2+B)));
    }
    return 0;
}
