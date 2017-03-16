#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
int const BL = 30;
llint dp[BL][27];
inline int f(int x, int y)
{
    return x < y ? 0 : (x == y ? 1 : 2);
}
inline int encode(int i, int j, int k)
{
    return i * 9 + j * 3 + k;
}
inline void decode(int s, int &i, int &j, int &k)
{
    i = s / 9;
    j = (s % 9) / 3;
    k = s % 3;
}
inline llint get(int b, int i, int j, int k)
{
    return b >= 0 ? dp[b][encode(i, j, k)] : (i == 1 && j == 1 && k == 1 ? 1 : 0);
}
llint solve(int A, int B, int K)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < BL; ++i)
    {
        for (int a = 0; a < 2; ++a)
        {
            for (int b = 0; b < 2; ++b)
            {
                int k = a & b;
                int sa = f(a << i, A & (1 << i)),
                    sb = f(b << i, B & (1 << i)),
                    sk = f(k << i, K & (1 << i));
                for (int sp = 0; sp < 27; ++sp)
                {
                    int spa, spb, spk;
                    decode(sp, spa, spb, spk);
                    int sca = sa != 1 ? sa : spa, scb = sb != 1 ? sb : spb, sck = sk != 1 ? sk : spk;
                    dp[i][encode(sca, scb, sck)] += get(i - 1, spa, spb, spk);
                }
            }
        }
    }
    return dp[BL - 1][encode(0, 0, 0)];
}
int main()
{
    int tc;
    int A, B, K;
    cin >> tc;
    for (int cc = 1; cc <= tc; ++cc)
    {
        cin >> A >> B >> K;
        cout << "Case #" << cc << ": " << solve(A, B, K) << endl;
    }
    return 0;
}
