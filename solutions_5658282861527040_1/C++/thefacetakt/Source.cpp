#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long fool(long long a, long long b, long long k)
{
    
        long long ans = 0;
        for (long long i = 0; i < a; ++i)
            for (long long j = 0; j < b; ++j)
                if ((i & j) < k)
                    ++ans;
        return ans;
}

map <pair<pair<pair<long long, pair<long long, long long> >, long long>, long long >, long long> dp1;
map <pair<pair<pair<long long, pair<long long, long long> >, long long>, long long >, long long> dp2;

long long getBit(long long a, long long i)
{
    return (a & (1 << i));
}

void setBit(long long &mask, long long i, long long what)
{
    if (what)
    {
        mask |= (1ll << i);
    }
    else
    {
        mask &= (~(1ll << i));
    }
}

long long dp1cnt(long long n, long long k, long long a, long long b, char mode)
{
    if (n < 0ll)
        return 1ll;
    auto mp = make_pair(make_pair(make_pair(n, make_pair(a, b)), k), mode);
    if (dp1.find(mp) != dp1.end())
        return dp1[mp];
    long long aa = bool(getBit(a, n));
    long long bb = bool(getBit(b, n));
    long long kk = bool(getBit(k, n));
    long long aaa = bool(getBit(mode, 2)); // is A all ones;
    long long bbb = bool(getBit(mode, 1)); // is B all ones;
    //long long ccc = bool(getBit(mode, 0)); // if 0 then less, if 1 then less or equal
    long long curAns = 0ll;
    for (long long i = 0ll; i <= max(aa, aaa); ++i)
    {
        for (long long j = 0ll; j <= max(bb, bbb); ++j)
        {
            if (true)
            {
                if ((i & j) == kk)
                {
                    long long curMode = 0;
                    setBit(curMode, 0ll, 1ll);
                    setBit(curMode, 1ll, ((j < max(bb, bbb)) || bbb));
                    setBit(curMode, 2ll, ((i < max(aa, aaa)) || aaa));
                    curAns += dp1cnt(n - 1, k, a, b, curMode);
                }
                else if ((i & j) < kk)
                {
                    long long a1 = (((i < max(aa, aaa)) || aaa) ? (n ? (1ll << (n)) : 1ll) : ((a & ((1ll << n) - 1ll)) + 1ll));
                    long long b1 = (((j < max(bb, bbb)) || bbb) ? (n ? (1ll << (n)) : 1ll) : ((b & ((1ll << n) - 1ll)) + 1ll));
                    curAns += a1 * b1;
                }
            }
            else
            {
                if ((i & j) <= kk)
                {
                    long long curMode = 0ll;
                    if ((i & j) < kk)
                    {
                        setBit(curMode, 0ll, 1ll);
                    }
                    else
                    {
                        setBit(curMode, 0ll, 0ll);
                    }
                    setBit(curMode, 1ll, ((i < max(bb, bbb)) || bbb));
                    setBit(curMode, 2ll, ((i < max(aa, aaa)) || aaa));
                    curAns += dp1cnt(n - 1, k, a, b, curMode);
                }
            }
        }
    }
    dp1[mp] = curAns;
    return curAns;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long t;
    scanf("%lld", &t);
    for (long long z = 1; z <= t; ++z)
    {
        printf("Case #%lld: ", z);
        long long a, b, k;
        scanf("%lld %lld %lld", &a, &b, &k);
        printf("%lld\n", dp1cnt(30, (k - 1), (a - 1), (b - 1), 0));
    }
    return 0;
}