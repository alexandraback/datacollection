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

int reverse_digits(int N)
{
    std::vector<int> digits;
    while (N > 0) { digits.push_back(N % 10); N /= 10; }
    int res = 0, power = 1;
    std::reverse(ALL(digits));
    for (int digit : digits) { res += digit * power; power *= 10; }
    return res;
}

const int MAX = 1000000;
std::vector<int> cache;
void fill_cache()
{
    cache.resize(MAX+2);
    REP(i,MAX+1) cache[i] = i;
    REP(i,MAX+1)
    {
        int rev = reverse_digits(i);
        if (rev > i)
        {
            cache[rev] = std::min(cache[rev], cache[i]+1);
        }
        cache[i+1] = std::min(cache[i+1], cache[i]+1);
    }
}

void solve()
{
    int N; std::cin >> N;
    std::cout << cache[N] << std::endl;
}

int main()
{
    fill_cache();
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

