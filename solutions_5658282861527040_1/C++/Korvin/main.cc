#define _USE_32BIT_TIME_T 1
#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

#define DEBUG(x) cout << #x << ": " << x << "\n"
using namespace std; // }}}

int result1(int A, int B, int K)
{
    int cnt = 0;
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            cnt+= (i & j) < K;
        }
    }
    return cnt;
}

typedef long long lint;

lint calc(int A, int a, int B, int b, int K)
{
    if (a < b) {
        swap(A, B);
        swap(a, b);
    }
    int mask_a = (1 << a) - 1;
    int mask_b = (1 << b) - 1;
    A^= 1 << a;
    int A0 = A & ~mask_a;
    B^= 1 << b;
    int B0 = B & ~mask_b;
    int AB0 = A0 & B0;
    for (int i = 30; i >= a; --i) {
        int k0 = bool(K & (1 << i));
        int ab0 = bool(AB0 & (1 << i));
        if (ab0 > k0)
           return 0;
        if (ab0 < k0)
           return lint(1 << a) * (1 << b);
    }
    bool f = 1;
    lint mult = 1, cnt = 0;
    for (int i = a - 1; i >= b; --i) {
        int k0 = bool(K & (1 << i));
        int b0 = bool(B0 & (1 << i));
        if (k0 == 0) {
            if (b0 == 0) // a0 - any
                mult*= 2;
            //if (b0 == 1); // a0 - 0
        }
        if (k0 == 1) {
            cnt+= mult * lint(1 << i) * (1 << b);
            if (b0 == 0) { // add the rest
                cnt+= mult * lint(1 << i) * (1 << b);
                f = 0;
                break;
            }
            //if (b0 == 1); // continue
        }
    }
    if (!f)
        return cnt;
    //lint mult2 = 1;
    for (int i = b - 1; i >= 0; --i) {
        int k0 = bool(K & (1 << i));
        if (k0 == 1)
            cnt+= 3 * mult * lint(1 << i) * (1 << i);
        else
            mult*= 3;
    }
    return cnt;
}

lint result2(int A, int B, int K)
{
    lint res = 0;
    for (int i = 30; i >= 0; --i) {
        if (!(A & (1 << i))) continue;
        for (int j = 30; j >= 0; --j) {
            if (!(B & (1 << j))) continue;
            res+= calc(A, i, B, j, K);
        }
    }
    return res;
}

int main()
{
    time_t start, end;
    time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    //cout.precision(6);
    //cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int A, B, K;
        cin >> A >> B >> K;
        //int res1 = result1(A, B, K);
        lint res2 = result2(A, B, K);
        cout << "Case #" << i << ": " << res2 << endl;
        //assert(res1 == res2);
        time(&end);
        ::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
