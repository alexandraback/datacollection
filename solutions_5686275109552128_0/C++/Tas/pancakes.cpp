#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
#include <math.h>
using namespace std;

int proc( vector<int>& ncakes, int N)
{
    int best = INT_MAX;
    for (int i=1; i <= N; i++)
    {
        int total = i;

        for (int n : ncakes)
        {
                total += (n + i -1) / i   - 1;
        }

        best = min(total, best);
    }

    return best;
}

int main()
{
    int t;
    cin >> t;
    for (int cs=1; cs <= t; cs++)
    {
        int D;
        cin >> D;
        vector<int> ncakes(D);
        int N = 0;

        for (int i=0; i < D; i++) {
            cin >> ncakes[i];
            N = max( ncakes[i], N);
        }

        cout << "Case #" << cs << ": ";
        vector<int> mem(N+1, -1);
        cout << proc(ncakes,N) << " ";
        cout << endl;

    }
}





