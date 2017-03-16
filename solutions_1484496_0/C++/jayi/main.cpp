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

#define N 512
#define M 2000010

//int sum[1 << 20];
vector<int>state[M];

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
        printf("Case #%d:\n", ++cas);
        scanf("%d", &n);
        REP(i, n) {
            scanf("%d", &s[i]);
        }
        
        int maxsz = 1 << n;
//        CL(flag, 0);
//        CL(sum, 0);
        REP(i, M) {
            state[i].clear();
        }
        int rx = -1, ry = -1;
        bool stop = false;
        REP(i, maxsz) {
            if (i == 0) continue;
            int sum = 0;
            REP(j, n) {
                if (i & (1 << j)) {
                    sum += s[j];
                }
            }
            int sz = (int)state[sum].size();
            REP(j, sz) {
                if (state[sum][j] ^ i == i + state[sum][j]) {
                    rx = state[sum][j];
                    ry = i;
                    stop = true;
                }
            }
            if (stop) {
                break;
            } else {
                state[sum].push_back(i);
            }
        }
        
        if (rx == -1) {
            puts("Impossible");
        } else {
            bool isStart = true;
            REP(j, n) {
                if (rx & (1 << j)) {
                if (isStart) {
                    isStart = false;
                } else {
                    putchar(' ');
                }
                    printf("%d", s[j]);
                }
            }
            puts("");
            isStart = true;
            REP(j, n) {
                
                if (ry & (1 << j)) {if (isStart) {
                    isStart = false;
                } else {
                    putchar(' ');
                }
                    printf("%d", s[j]);
                }
            }
            puts("");
        }
    }
    return 0;
}