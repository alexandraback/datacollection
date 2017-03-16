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

const std::vector<std::string> numbers = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

void solve()
{
    std::string S; std::cin >> S;
    std::map<char,int> H; REP(i,SZ(S)) H[S[i]]++;
    std::map<int,int> P;
    auto remove = [&H,&P](int n) { for (char c:numbers[n]) H[c]--; P[n]++; };

    while (H['Z'] > 0) remove(0);
    while (H['W'] > 0) remove(2);
    while (H['X'] > 0) remove(6);
    while (H['G'] > 0) remove(8);
    while (H['S'] > 0) remove(7);
    while (H['V'] > 0) remove(5);
    while (H['F'] > 0) remove(4);
    while (H['O'] > 0) remove(1);
    while (H['T'] > 0) remove(3);
    while (H['N'] > 0) remove(9);

    REP(i,10) REP(_,P[i]) std::cout << i; std::cout << std::endl;
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

