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
    int Sm; std::cin >> Sm;
    std::string S; std::cin >> S;
    const int N = SZ(S); REP(i,N) S[i] -= '0';

    int standing = 0;
    int friends = 0;
    REP(i,N)
    {
        if (standing < i)
        {
            friends += i - standing;
            standing = i;
        }
        standing += S[i];
    }
    std::cout << friends << std::endl;
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

