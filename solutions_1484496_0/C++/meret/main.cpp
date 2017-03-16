#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 20;

typedef bitset<N> subset;

map<LL, subset> got;

bool found;
subset s1, s2;

LL val[N];

LL get_sum(const subset& s) {
    LL result = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i]) {
            result += val[i];
        }
    }
    return result;
}

void add(const subset& s) {
    LL sum = get_sum(s);
    if (got.find(sum) != got.end()) {
        if (got[sum] != s) {
            s1 = got[sum];
            s2 = s;
            found = true;
        }
    } else {
        got[sum] = s;
    }
}

void print(const subset& s) {
    bool fst = true;
    for (int i = 0; i < N; ++i) {
        if (s[i]) {
            if (fst) {
                fst = false;
            } else {
                printf(" ");
            }
            printf("%lld", val[i]);
        }
    }
    printf("\n");
}

void alg() {
    got.clear();
    scanf("%*d");
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &val[i]);
    }
    found = false;
    for (int i = 1; i < (1 << N) && !found; ++i) {
        subset s;
        for (int j = 0; j < N; ++j) {
            s[j] = (i >> j) & 1;
        }
        add(s);
    }
    static int case_no = 0;
    printf("Case #%d:\n", ++case_no);
    if (!found) {
        printf("Impossible\n");
    } else {
        print(s1);
        print(s2);
    }
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        alg();
    }
}
