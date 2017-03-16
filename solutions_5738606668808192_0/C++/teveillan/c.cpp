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

const int N = 1e6 + 10;
int v[20];
bool isNotPrime[N] = {};
vector<LL> vec;
void init() {
    FOR(i, 2, 1e6) {
        if(!isNotPrime[i]) vec.pb(i);
        for(int j = i + i; j <= 1e6; j += i) isNotPrime[j] = 1;
    }
}

LL check(LL x) {
    for(int i = 0; i < vec.size() && vec[i] * vec[i] <= x; ++i)
        if(x % vec[i] == 0) return vec[i];
    return -1;
}

bool solve(LL pos, int n) {
    FOR(i, 2, 10) {
        LL x = 0;
        DWN(j, n-1, 0) {
            x *= i;
            if(pos & (1ll<<j)) ++x;
        }
        v[i] = check(x);
        if(v[i] == -1) return 0;
    }
    return 1;
}


int main()
{
	freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    init();
    int casnum, n, m;
    cin >> casnum;
    FOR(casid, 1, casnum) {
        cin >> n >> m;
        printf("Case #%d:\n", casid);
        for(int i = 0; i < (1<<(n-2)) && m; ++i) {
            LL pos = i;
            pos <<= 1, pos |= (1ll<<(n-1)), pos |= 1;
            if(solve(pos, n)) {
                --m;
                DWN(j, n-1, 0) putchar( ((1<<(j)) & pos) ? '1' : '0');
                FOR(j, 2, 10) printf(" %d", v[j]);
                puts("");
            }
        }
    }

    return 0;
}

