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
#define SCAN_INT() (*({int _si;assert(1==scanf("%d", &_si)); &_si;}))
#define IN(x,upper) ((x)>=0 && (x)<(upper))
#define NY(i) (*({int _nxy = i; _nxy = _nxy>=2? -5+2*_nxy : 0; &_nxy;}))
#define NX(i) (*({int _nxy = i; _nxy = _nxy<2 ? -1+2*_nxy : 0; &_nxy;}))
namespace my_namespace {
};
using namespace my_namespace;
struct TV {
    int floor;
    int ceil;
    bool visited;
    int dist;
} V[100][100];
int H, M, N;
struct TQE {
    int r, c;
    int dist;
    bool operator<(const TQE & qe) const {
        return !(dist < qe.dist);
}};
int earliest_move(TV * v1, TV * v2)
{
    assert(v1->floor <= v1->ceil - 50);
    if (v2->floor > v2->ceil - 50)
        return 1000000000 + 1;
    if (v1->floor > v2->ceil - 50)
        return 1000000000 + 2;
    if (v2->floor > v1->ceil - 50)
        return 1000000000 + 3;
    int left_water = H - (v2->ceil - 50);
    if (left_water < 0)
        return 0;
    return left_water;
}
void problem()
{
    assert(3 == scanf("%d%d%d", &H, &M, &N));
    REP(r, M) REP(c, N) {
        V[r][c].ceil = SCAN_INT();
        V[r][c].visited = false;
    }
    REP(r, M) REP(c, N)
     V[r][c].floor = SCAN_INT();
    priority_queue < TQE > q;
    q.push((TQE) {
     0, 0, 0});
    while (!q.empty()) {
        TQE qe = q.top();
        q.pop();
        TV & v = V[qe.r][qe.c];
        if (v.visited)
            continue;
        ;
        v.visited = true;
        v.dist = qe.dist;
        REP(o, 4) {
            int nr = qe.r + NX(o);
            int nc = qe.c + NY(o);
            if (!IN(nr, M) || !IN(nc, N))
                continue;
            TV & nv = V[nr][nc];
            if (nv.visited)
                continue;
            int nd = max(v.dist, earliest_move(&v, &nv));
            ;
            if (nd >= 1000000000)
                continue;
            bool swimmable = H - nd >= v.floor + 20;
            if (nd)
                nd += swimmable ? 10 : 100;
            q.push((TQE) {
             nr, nc, nd}
            );
        }
    }
    TV & v = V[M - 1][N - 1];
    assert(v.visited);
    printf("%d.%01d\n", v.dist / 10, v.dist % 10);
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
