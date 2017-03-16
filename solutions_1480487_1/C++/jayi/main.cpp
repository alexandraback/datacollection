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
#define EPS 1e-12
#define MP make_pair
typedef long long LL;
const double pi = acos(-1.0);
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define db double
//------------------------------------------------------------------------------

#define N 256
int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    
    int T, cas = 0;
    int n;
    int s[N];
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        printf("Case #%d:", ++cas);
        int sum = 0;
        double avg;
        REP(i, n) {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        avg = sum;
        avg = avg * 2.0 / n;
//        sort(s, s + n);
        
        REP(i, n) {
            db low = 0, hi = 1;
            db mid;
            while (low + EPS < hi) {
                mid = (low + hi) / 2.0;
                db score = s[i] + sum * mid;
                db ys = 0.0;
                REP(j, n) {
                    if (i == j) {
                        continue;
                    }
                    ys += max((score - s[j]) / sum, 0);
                }
                if (ys + mid > 1.0 + EPS) {
                    hi = mid;
                } else {
                    low = mid;
                }
            }
//            REP(j, n) {
//                if (i == j) continue;
//                db tmp = (1 + (db)(s[j] - s[i]) / (db)sum) / 2.0;
//                checkMin(ret, tmp);
//            }
            db ret = low * 100;
//            if (ret < EPS) ret = 0;
            printf(" %.6f", ret);
        }
        puts("");
    }  
    return 0;
}