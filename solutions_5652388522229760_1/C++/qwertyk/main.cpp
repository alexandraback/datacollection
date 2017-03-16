#define LARGE
//#define SMALL

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int t, T, N, i, M, j;
const int L = 10;
bool arr[L];

int main()
{
#if defined(LARGE)
    freopen("../A-large.in", "r", stdin);
    freopen("../A-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../A-small-attempt0.in", "r", stdin);
    freopen("../A-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for (t = 0; t < T; ++t)
    {
        cin >> N;
        if (N == 0)
        {
            cout << "Case #" << t+1 << ": INSOMNIA\n";
            continue;
        }
        for (j = 0; j < L; ++j) arr[j] = false;

        for (i = 1; ; ++i)
        {
            for (M = i * N; M != 0; M /= L)
            {
                if (!arr[M % L]) arr[M % L] = true;
            }
            for (j = 0; j < L; ++j)
            {
                if (!arr[j]) break;
            }
            if (j == L) break;
        }
        cout << "Case #" << t+1 << ": " << (i * N) << "\n";
    }

    return 0;
}
