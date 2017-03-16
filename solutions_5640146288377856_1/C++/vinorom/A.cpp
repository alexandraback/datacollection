#include <iostream>
#include <vector>

using namespace std;

int solve(int R, int C, int W)
{
    int s = C / W;
    return R * s + (C % W == 0 ? W-1 : W);
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int R, C, W;
        cin >> R >> C >> W;

        int answer = solve(R, C, W);
        cout << "Case #" << t << ": " << answer << endl;
    }

    return 0;
}
