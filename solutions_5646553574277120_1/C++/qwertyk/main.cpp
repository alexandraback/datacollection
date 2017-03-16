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

int t, T, i, D;
long long int C, V;

int main()
{
#if defined(LARGE)
    freopen("../C-large.in", "r", stdin);
    freopen("../C-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../C-small-attempt2.in", "r", stdin);
    freopen("../C-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;
    for(t = 0; t < T; ++t)
    {
        cin >> C >> D >> V;
        int N = 0;
        vector<long long int> A(D);
        for (i = 0; i < D; ++i) cin >> A[i];
        sort(A.begin(), A.end());
        long long int last = 1, sum = C;
        i = 0;
        if (A[i] != 1) ++N;
        else ++i; 
        while (sum < V)
        {
            if (i < D)
            {
                if (A[i] > sum + 1)
                {
                    last = sum + 1;
                    sum += last * C;
                    ++N;
                }
                else
                {
                    last = A[i++];
                    sum += last * C;
                }
            }
            else
            {
                last = sum + 1;
                sum += last * C;
                ++N;
            }
        }
        cout << "Case #" << t+1 << ": " << N << "\n";
    }

    return 0;
}
