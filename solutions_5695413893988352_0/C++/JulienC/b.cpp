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

int pow10(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 10;
    if (n == 2) return 100;
    if (n == 3) return 1000;
    assert(false); return 0;
}

std::string tos(int n, int L)
{
    std::string s; REP(_,L) s += '0';
    int idx = L-1;
    while (n > 0)
    {
        s[idx--] = '0' + n % 10;
        n /= 10;
    }
    return s;
}

void solve()
{
    std::string C,J; std::cin >> C >> J;
    const int L = SZ(C);

    int best = (int) 1e9;
    int bestC = 0, bestJ = 0;
    REP(i,pow10(L))
    {
        bool ok = true;
        REP(k,L) if (C[k] != '?' && C[k] != tos(i,L)[k]) { ok = false; break; }
        if (!ok) continue;
        REP(j,pow10(L))
        {
            ok = true;
            REP(k,L) if (J[k] != '?' && J[k] != tos(j,L)[k]) { ok = false; break; }
            if (!ok) continue;
            if (abs(i-j) < best)
            {
                best = abs(i-j);
                bestC = i;
                bestJ = j;
            }
        }
    }
    std::cout << tos(bestC,L) << " " << tos(bestJ,L) << std::endl;
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

