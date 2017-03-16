#include <algorithm>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0,nn=static_cast<int>(n);i<nn;i++)
#define REP_R(i,n) for(int i=static_cast<int>(n)-1;i>=0;i--)
#define ALL(v) v.begin(),v.end()
#define ALL_R(v) v.rbegin(),v.rend()
#define SZ(v) static_cast<int>(v.size())
template<typename T> inline T sqr(T a) { return a*a; }

int yes(int C, int W, int x)
{
    return W+1;
}

std::map<std::pair<int,int>, int> row_cache;
int solve(int C, int W)
{
    assert(W <= C);
    if (C == W) return W;
    const std::pair<int,int> pa = std::make_pair(C,W);
    if (row_cache.find(pa) != row_cache.end()) return row_cache[pa];
    if (C/W > 1) return row_cache[pa] = (C/W-1) + solve(C-(C/W-1)*W,W);

    int me = 2000;
    REP(i,(C+1)/2)
    {
        int bro = yes(C,W,i);
        if (C-(i+1) >= W) bro = std::max(bro, 1+solve(C-(i+1),W));
        me = std::min(me, bro);
    }
    return row_cache[pa] = me;
}

int solve(int R, int C, int W)
{
    if (W == 1) return R*C;
    const int t = (R-1) * (C/W);
    return t + solve(C, W);
}

void solve()
{
    int R,C,W; std::cin >> R >> C >> W;
    std::cout << solve(R, C, W) << std::endl;
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

