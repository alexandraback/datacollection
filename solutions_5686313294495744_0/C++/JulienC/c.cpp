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
    int N; std::cin >> N;
    using Student = std::pair<std::string, std::string>;
    std::vector<Student> S(N);
    REP(i,N) std::cin >> S[i].first >> S[i].second;

    std::set<std::string> A,B;
    std::multiset<std::string> firsts, seconds;
    REP(i,N) { firsts.insert(S[i].first); A.insert(S[i].first); }
    REP(i,N) { seconds.insert(S[i].second); B.insert(S[i].second); }

    std::set<std::string> C,D;
    int OG = 0;
    REP(i,N)
    {
        const bool first_unique = (firsts.count(S[i].first) == 1);
        const bool second_unique = (seconds.count(S[i].second) == 1);
        if (first_unique || second_unique) 
        {
            OG++;
            C.insert(S[i].first);
            D.insert(S[i].second);
        }
        //if (first_unique && !second_unique) D.insert(S[i].second);
        //if (!first_unique && second_unique) C.insert(S[i].first);
    }
    OG += SZ(A) - SZ(C);
    OG += SZ(B) - SZ(D);
    const int cheaters = N - OG;
    std::cout << cheaters << std::endl;
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

