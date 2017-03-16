#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int R, C, W;
        cin >> R >> C >> W;
        int* row = new int[C];
        for(int i = 0; i < C; i++)
            row[i] = 0;
        row[W - 1] = W;
        for(int i = W; i < C; i++)
        {
            int minShots = 1 + row[i - 1];
            for(int j = 1; j < i; j++)
            {
                int maxShots = row[j - 1] + row[i - j - 1] + 1;
                if(W + 1 > maxShots) maxShots = W + 1;
                if(minShots > maxShots) minShots = maxShots;
            }
            row[i] = minShots;
        }
        cout << "Case #" << t << ": " << (R - 1)*(C / W) + row[C - 1] << endl;
    }
    return 0;
}
