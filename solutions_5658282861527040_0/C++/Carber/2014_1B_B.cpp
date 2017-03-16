#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void Solved(int nT)
{
    int A, B, K;
    cin >> A >> B >> K;
    int result = 0;
    for (int i = 0; i < A; ++i)
        for (int j = 0; j < B; ++j)
            if ((i & j) < K) ++result;
    printf("Case #%d: %d\n", nT, result);
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int T = 0;
    cin >> T;
    for (int nT = 1; nT <= T; ++nT)
    {
        Solved(nT);
    }

    return 0;
}