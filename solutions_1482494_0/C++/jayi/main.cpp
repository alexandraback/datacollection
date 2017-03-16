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
#define N 1024
int a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int T, n;
    int cas = 0;
    cin >> T;
    while (T--) {
        cin >> n;
        int id[16];
        REP(i, n) {
            scanf("%d%d", &a[i], &b[i]);
            id[i] = i;
        }
        int ret = 0;
        int score = 0;
        int flag[N];
        memset(flag, 0, sizeof(flag));
        
        bool ok = true;
        printf("Case #%d: ", ++cas);
        while (score < 2 * n) {
            int nid = -1;
            REP(i, n) {
                if (b[i] <= score) {
                    if (flag[i] == 0) {
                        nid = i;
                        break;
                    } else if (flag[i] == 1) {
                        nid = i;
                    }
                }
            }
            if (nid != -1) {
                score += 2 - flag[nid];
                flag[nid] = 2;
                ++ret;
                continue;
            }
            nid = -1;
            REP(i, n) {
                if (a[i] <= score) {
                    if (flag[i] == 0) {
                        if (nid == -1) {
                            nid = i;
                        } else if (b[i] > b[nid]) {
                            nid = i;
                        }                        
                    }
                }
            }
            if (nid != -1) {
                ++score;
                flag[nid] = 1;
                ++ret;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("%d\n", ret);
        } else {
            puts("Too Bad");
        }
    }
    return 0;
}