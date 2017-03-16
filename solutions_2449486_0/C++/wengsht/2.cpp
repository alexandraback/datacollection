
/*
ID: wengsht1
LANG: C++
TASK: test
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define MX 105
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

int n, m, k, t;

int maxn[MX], maxm[MX];
int b[MX][MX];
int main() {
    scanf("%d", &t);
    OREP(c, t) {
        scanf("%d %d", &n, &m);
        memset(maxn, 0, sizeof(maxn));
        memset(maxm, 0, sizeof(maxm));
        REP(i, n) {
            REP(j, m) {
                scanf("%d", &b[i][j]);
                if(maxn[i] < b[i][j]) maxn[i] = b[i][j];
                if(maxm[j] < b[i][j]) maxm[j] = b[i][j];
            }
        }
        bool good = true;
        REP(i, n) {
            REP(j, m) {
                if(b[i][j] == maxn[i] || b[i][j] == maxm[j]) ;
                else { good = false; break; }
            }
        }
        printf("Case #%d: ", c);
        if(good) printf("YES\n");
        else     printf("NO\n");
    }
    return 0;
}

