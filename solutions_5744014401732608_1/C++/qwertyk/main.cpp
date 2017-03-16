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

const int L = 50;
int t, T;
long long int i, B, M, P, p, j;
int G[L][L];

int main()
{
#if defined(LARGE)
    freopen("../B-large.in", "r", stdin);
    freopen("../B-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../B-small-attempt2.in", "r", stdin);
    freopen("../B-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for(t = 0; t < T; ++t)
    {
        cin >> B >> M;
        for (P = 1, p = 2; 2*P <= M; P *= 2, ++p);
        if (p > B || (p == B && P < M))
        {
            cout << "Case #" << t+1 << ": IMPOSSIBLE\n";
            continue;
        }
        else
        {
            cout << "Case #" << t+1 << ": POSSIBLE\n";
            for (i = 0; i < B; ++i)
            {
                for (j = 0; j < B; ++j)
                {
                    G[i][j] = 0;
                }
            }
            for (i = 0; i < p-1; ++i)
            {
                for (j = i+1; j < p-1; ++j)
                {
                    G[i][j] = 1;
                }
            }
            for (i = 0; i < p-1; ++i) G[i][B-1] = 1;
            M -= P;
            if (M > 0) G[p-1][B-1] = 1;
            for (i = p-1; M != 0; P /= 2, --i)
            {
                if (M >= P)
                {
                    G[i][p-1] = 1;
                    
                    M -= P;
                }
            }

            for (i = 0; i < B; ++i)
            {
                for (j = 0; j < B; ++j)
                {
                    cout << G[i][j];
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
