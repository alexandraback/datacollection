#include <iostream>
#include <cstdlib>
#include <map>
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

int main()
{
	freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int casnum;
    cin >> casnum;
    FOR(casid, 1, casnum) {
        int n, x;
        map<int, int>m;
        cin >> n;
        FOR(i, 1, 2 * n - 1) {
            FOR(j, 1, n) {
                scanf("%d", &x);
                ++m[x];
            }
        }
        VI ret;
        FOR(i, 1, 2500) if(m[i] % 2 == 1) ret.pb(i);

        printf("Case #%d:", casid);
        REP(i, ret.size()) printf(" %d", ret[i]);
        puts("");
    }

    return 0;
}

