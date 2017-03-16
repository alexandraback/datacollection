
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
#include <sstream>
#include <set>
using namespace std;

#define MX 100005
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

int n, m, k, t;

int mask(long long ret, bool met[]) {
    int cnt = 0;
    while (ret) {
        int c = ret % 10;
        ret /= 10;
        met[c] = true;
    }
    for (int  i = 0;i < 10;++i) {
        cnt += met[i] ? 1 : 0;
    }
    return cnt;
}
long long gosleep(int n) {
    long long ret = 0;
    bool met[10];
    memset(met, false, sizeof(met));
    while (true) {
        ret = ret + n;
        
        int cnt = mask(ret, met);
        
        if (cnt == 10)
            return ret;
    }
    return -1;
}
int main() {
    scanf("%d", &t);
    
    for (int i =1; i <= t;++i) {
        scanf("%d", &n);
        printf("Case #%d: ", i);
        if (!n) {
            printf("INSOMNIA\n");
        } else {
            cout << gosleep(n) << endl;
        }
    }
    return 0;
}

