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
#define REP(i,n) for( int i=0;i<int(n);++i)
namespace my_namespace {
};
#define SCAN_INT() (*({int _si;assert(1==scanf("%d", &_si)); &_si;}))
#define VI vector<int>
using namespace my_namespace;
VI gather(VI * pv, int ind)
{
    VI & v = *pv;
    VI result;
    while (ind != 0) {
        result.push_back(ind - v[ind]);
        ind = v[ind];
    }
    return result;
}
void print_vec(const VI & vi)
{
    REP(i, vi.size())
     printf("%d%s", vi[i], i + 1 < vi.size()? " " : "\n");
}
void problem()
{
    int n;
    assert(1 == scanf("%d", &n));
    VI v;
    VI visited(1, 0);
    VI prevs(1000001, -1);
    bool finished = false;
    REP(i, n) {
        int cur = SCAN_INT();
        if (finished)
            continue;
        int os = visited.size();
        REP(j, os) {
            int next = visited[j] + cur;
            assert(next < prevs.size());
            if (prevs[next] >= 0) {
                VI col1 = gather(&prevs, next);
                VI col2 = gather(&prevs, visited[j]);
                col2.push_back(cur);
                print_vec(col1);
                print_vec(col2);
                finished = true;
                break;
            } else {
                visited.push_back(next);
                prevs[next] = visited[j];
            }
        }
    }
    if (!finished)
        printf("Impossible\n");
}
int main()
{
    int n = SCAN_INT();
    REP(i, n) {
        printf("Case #%d:\n", i + 1);
        problem();
    }
    return 0;
}
