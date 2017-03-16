//#define LARGE
#define SMALL

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

int t, T, K, C, S, i;
long long int X, Y;

int main()
{
#if defined(LARGE)
    freopen("../D-large.in", "r", stdin);
    freopen("../D-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../D-small-attempt1.in", "r", stdin);
    freopen("../D-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for(t = 0; t < T; ++t)
    {
        cin >> K >> C >> S;
        X = 0;
        Y = 1;
        for (i = 1; i < C; ++i)
        {
            X += Y;
            Y *= K;
        }
        cout << "Case #" << t+1 << ":";
        for (i = 0; i < S; ++i) cout << " " << (i * X * K + i + 1);
        cout << "\n";
    }

    return 0;
}
