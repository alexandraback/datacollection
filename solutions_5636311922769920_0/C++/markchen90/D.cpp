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

const int MAXC = 110;
LL kpow[MAXC];

int T; LL K, C, S;

LL getNode(vector<LL>& v) { // v.size() == C
    LL node = 1;
    for (int i = 0; i < C; i++) node += (v[i]-1) * kpow[C-1-i];
    return node;
}

int main() {
    scanf("%d", &T);

    for (int TT=1; TT <= T; TT++) {
        printf("Case #%d: ", TT);
        scanf("%lld%lld%lld", &K, &C, &S);

        LL need = K / C + ((K % C) != 0);

        if (S < need) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        memset(kpow, 0, sizeof kpow);
        kpow[0] = 1; FOR1(i, C) kpow[i] = K * kpow[i-1];

        LL last = 0;

        while (last < K) {
            vector<LL> lvlpos(C);
            FORN(i, C) lvlpos[i] = min(++last, K);
            printf("%lld ", getNode(lvlpos));
        }
        printf("\n");
    }
    
    return 0;
}
