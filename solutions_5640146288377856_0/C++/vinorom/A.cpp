#include <iostream>
#include <vector>

using namespace std;

int solve (int R, int C, int W)
{
    if (R == 1)
    {
        int s = C / W;
        if (C % W == 0)
            return s + W-1;
        else
            return s + W;
    }

    return 0; // TODO
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
