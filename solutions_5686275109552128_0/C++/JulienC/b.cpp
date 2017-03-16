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

void solve()
{
    int D; std::cin >> D;
    std::vector<int> P(D); REP(i,D) std::cin >> P[i];

    std::sort(ALL(P)); std::reverse(ALL(P));

    int elapsed = 0;
    int best = P.front();
    for (;;)
    {
        int left = P[0];
        if (left == 1) { std::cout << best << std::endl; return; }
        P[0] = (left + 1) / 2;
        P.push_back(left / 2);
        std::sort(ALL(P)); std::reverse(ALL(P));
        elapsed++;
        best = std::min(best, elapsed + P[0]);
    }
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

