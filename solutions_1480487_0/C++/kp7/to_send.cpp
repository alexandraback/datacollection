#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <math.h>
#include <string.h>
#include <stdio.h>
using namespace std;
namespace my_namespace {
};
#define VALT(c) __typeof(*(c).begin())
#define ITER(c) __typeof((c).begin())
#define FORE(e,c) for( ITER(c) it_##e = (c).begin(), it2_##e = it_##e; it_##e!=(c).end() && it_##e==it2_##e; ++it_##e) for( VALT(c) e = *it_##e; it2_##e==it_##e; it2_##e++)
#define REP(i,n) for( int i=0;i<int(n);++i)
#define SCAN_INT() (*({int _si;assert(1==scanf("%d", &_si)); &_si;}))
#define ALL(x) x.begin(),x.end()
#define LD long double
#define VI vector<int>
#define LL long long
#define SUM( f, p) (*({LL _sum_v = 0; f _sum_v+= (p); &_sum_v;}))
using namespace my_namespace;
void problem()
{
    int n = SCAN_INT();
    VI v, v2;
    REP(i, n)
     v.push_back(SCAN_INT());
    v2 = v;
    sort(ALL(v));
    LD sum = SUM(FORE(e, v), e);
    LD left = sum;
    v.push_back(10000000);
    LD t = -1;
    REP(i, n + 1) {
        LD level = v[i];
        LD prev = i ? v[i - 1] : 0;
        if (left > i * (level - prev)) {
            left -= i * (level - prev);
        } else {
            t = prev + left / i;
            break;
        }
    }
    assert(t >= -0.5);
    REP(i, n) {
        printf("%s%.6Lf", i ? " " : "", max((t - v2[i]) / sum, (LD) 0.0) * 100);
    }
    printf("\n");
}
int main()
{
    int n = SCAN_INT();
    REP(i, n) {
        printf("Case #%d: ", i + 1);
        problem();
    }
    return 0;
}
