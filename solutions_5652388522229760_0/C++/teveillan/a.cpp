#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define MEM(arr, v) memset(arr, v, sizeof(arr))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

LL solve(LL n) {
    if(n == 0) return -1;
    LL pos = 0, x = n;
    while(1) {
        LL tmp = x;
        while(tmp) {
            pos |= (1 << (tmp % 10));
            tmp /= 10;
        }
        if(pos == 1023) return x;
        x += n;
    }
}

int main()
{
	freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    LL casnum, n;
    cin >> casnum;
    FOR(casid, 1, casnum) {
        cin >> n;
        printf("Case #%d: ", casid);
        LL ret = solve(n);
        if(ret == -1) puts("INSOMNIA");
        else cout << ret << endl;
    }

    return 0;
}

