
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

#define MX 100005
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

int n, m, k, t;
LL a, b;

int tmp[100];
bool is(LL p) {
    m = 0;
    while(p) {
        tmp[m++] = p % 10;
        p /= 10;
    }
    int mid = m / 2;
    for(int i = 0;i < mid;i++) 
        if(tmp[i] != tmp[m-i-1]) 
            return false;

    return true;

}
int solve() {
    int ret = 0;
    int sqrb = sqrt(1.0*b);

    for(int i = ceil(sqrt((double)a));i <= sqrb;i++) {
        if(is(i) && is((LL)i*i)) {
            ret ++;
        }
    }
    return ret;
}
int main() {
    scanf("%d", &t);
    OREP(c, t) {
        scanf("%lld %lld", &a, &b);

        printf("Case #%d: %d\n", c, solve());
    }

    return 0;
}

