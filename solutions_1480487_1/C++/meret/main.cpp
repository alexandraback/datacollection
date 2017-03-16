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

void alg() {
    int n;
    scanf("%d", &n);
    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &scores[i]);
    }
    int sum = 0;
    FORE (it, scores) {
        sum += *it;
    }
    static int caseNo = 0;
    printf("Case #%d:", ++caseNo);
    for (int i = 0; i < n; ++i) {
        double l = 0, r = 1;
        for (int it = 0; it < 60; ++it) {
            double c = (l + r) / 2;
            double my_score = scores[i] + c * sum;
            double sum_p = 0;
            for (int j = 0; j < n; ++j) {
                if (j != i && scores[j] < my_score) {
                    sum_p += (my_score - scores[j]) / (double) sum;
                }
            }
            if (sum_p + c > 1) {
                r = c;
            } else {
                l = c;
            }
        }
        printf(" %.9lf", l * 100);
    }
    printf("\n");
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        alg();
    }
}
