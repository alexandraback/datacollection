#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <bitset>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define mp(a, b) make_pair(a, b)
#define D(a) #a << ": " << a << "\n"

bitset<64> aa, bb, kk;

int64 cache[70][2][2][2];

int64 search(int idx, bool canA, bool canB, bool canK = false)
{
    if (cache[idx][canA][canB][canK] != -1)
        return cache[idx][canA][canB][canK];

    if (idx == 0)
    {
        // none
        int64 res = 1;
        // in a
        if (canA || aa[idx]) ++res;
        // in b
        if (canB || bb[idx]) ++res;
        // in both
        if (canK || kk[idx]) if ((canA || aa[idx]) && (canB || bb[idx])) ++res;

        return res;
    }

    int64& res = cache[idx][canA][canB][canK];
    res = 0;

    // in none of them
    res += search(idx - 1, canA || aa[idx], canB || bb[idx], canK || kk[idx]);

    // in a?
    if (canA || aa[idx]) res += search(idx - 1, canA, canB || bb[idx], canK || kk[idx]);

    // in b?
    if (canB || bb[idx]) res += search(idx - 1, canA || aa[idx], canB, canK || kk[idx]);


    // in both?
    if (canK || kk[idx])
    if ((canA || aa[idx]) && (canB || bb[idx])) res += search(idx - 1, canA, canB, canK);

    return res;
}

int main()
{
    int CASES;
    cin >> CASES;
    for (int CASE = 1; CASE <= CASES; ++CASE)
    {
        int64 a, b, k;
        cin >> a >> b >> k;
        --a;
        --b;
        --k;
        memset(cache, -1, sizeof cache);
        int64 res = 0;
        aa.reset();
        bb.reset();
        kk.reset();
        
        FOR(64)
        {
            if (a & (1LL << i)) aa.set(i);
            if (b & (1LL << i)) bb.set(i);
            if (k & (1LL << i)) kk.set(i);
        }

        printf("Case #%d: ", CASE);
        cout << search(63, false, false) << endl;
    }
    
    return 0;
}