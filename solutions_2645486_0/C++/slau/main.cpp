#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int T;

int E, R, N;
int costs[15];

int run(int activity, int energy)
{
    energy = min(energy, E);
    if (activity ==N -1)
    {
        return costs[activity]*energy;
    }

    int maxxy = 0;

    for (int i = 0; i <= energy; i++)
    {
        int ans = costs[activity]*i + run(activity+1, energy-i+R);
        maxxy = max(ans, maxxy);
    }

    return maxxy;
}

int main()
{
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);

    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        memset(costs, 0, sizeof(costs));
        cin >> E >> R >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> costs[i];
        }
        int ans = run(0, E);
        cout << "Case #" << caseNum << ": " << ans << endl;


    }
    return 0;
}
