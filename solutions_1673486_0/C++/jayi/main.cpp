#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) for(int i=0;i<n;++i)
#define FS(i,a) for(int i=0;a[i];++i)
#define FOREACH(a,b) for(typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define PR2(a,n,m) REP(i,n){REP(j,m)cout<<a[i][j]<<" ";puts("");}
#define CL(a,b) memset(a,b,sizeof(a))
#define CLQ(q) while(!q.empty())q.pop();
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define checkMax(a,b) if(b>a)a=b;
#define checkMin(a,b) if(b<a)a=b;
#define sqr(x) ((x)*(x))
#define INF 200000000
#define EPS 1e-8
#define MP make_pair
typedef long long LL;
const double pi = acos(-1.0);
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define db double
//------------------------------------------------------------------------------
#define N 100000
double p[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int T, A, B;
    int cas = 0;
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &A, &B);
        REP(i, A) {
            scanf("%lf", &p[i]);
        }
        printf("Case #%d: ", ++cas);
        
        db ans = min(2 + B, A + B + 1);
        db pro = 1;
        REP(i, A) {
            pro *= p[i];
            if (pro * (A - i + (B - i) + 1 - 2) + (1 - pro) * (A - i + B - i - 2 + 1 + B + 1) + EPS < ans) {
                ans = pro * (A - i + (B - i) + 1 - 2) + (1 - pro) * (A - i + B - i - 2 + 1 + B + 1);
            }
        }
        printf("%.6f\n", ans);
    }
    return 0;
}