
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

#define MX 1000005
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

LL n, m, k;
int t;

int s[MX];
int solve() {
    int ret = n;
    int j = 0;
    for(int i = 0;i < n;i++) {
        if(j + n-i < ret) ret = j + n - i;
        if(j > ret) break;
        if(m > s[i]) {
            m += (LL)s[i];
        }
        else {
            j ++;
            m += m-1;
            i --;
        }
    }
    if(j < ret) ret = j;
    return ret;
}
int main() {
//    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for(int c = 1;c <= t;c++) {
        cin >> m >> n;
        for(int i = 0;i < n;i++) scanf("%d", s+i);
        sort(s, s+n);

        int ret = solve();
        printf("Case #%d: %d\n", c, ret);
    }

    return 0;
}

