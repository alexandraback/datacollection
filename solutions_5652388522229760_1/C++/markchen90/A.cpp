#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007
#define INF 2000000000

const int MAXD = 10;
int has[MAXD];

int T; LL N;

bool check(LL x) {
    while (x > 0) {
        has[x % 10] = 1;
        x /= 10;
    }

    FORN(i, MAXD) if (!has[i]) return false;
    return true;
}

void solve(LL N) {
    if (N == 0) {
        printf("INSOMNIA\n");
        return;
    }

    memset(has, 0, sizeof has);

    LL mult = N;
    while (!check(mult)) mult += N;

    printf("%lld\n", mult);
    return;
}

int main() {
    scanf("%d", &T);
    
    FOR1(tc, T) {
        printf("Case #%d: ", tc);
        scanf("%lld", &N);
        solve(N);
    }

    return 0;
}
