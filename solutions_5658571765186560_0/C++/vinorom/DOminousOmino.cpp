#include <iostream>
#include <string>

using namespace std;

static const string RICHARD("RICHARD");
static const string GABRIEL("GABRIEL");

void win(int tc, const string& winner)
{
    cout << "Case #" << tc << ": " << winner << endl;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int X, R, C;
        cin >> X >> R >> C;

        int RC = R * C;
        if (RC % X != 0) // Gabriel could not fill in the grid
        {
            win(t, RICHARD);
            continue;
        }
        if (X == 1 || X == 2) // Gabriel always wins
        {
            win(t, GABRIEL);
            continue;
        }
        // X >= 3
        if (X >= 7) // for X >= 7 it's easy for Richard to win with one cell that is not accessible to fit
        {
            win(t, RICHARD);
            continue;
        }
        // 3 <= X <= 6
        if (X > max(R, C)) // Gabriel could not fit long stick
        {
            win(t, RICHARD);
            continue;
        }
        int X2 = X / 2 + (X % 2 == 0 ? 0 : 1);
        if (X2 < min(R, C)) // Gabriel can way around
        {
            win(t, GABRIEL);
            continue;
        }
        else if (X2 > min(R, C)) // Gabriel could not fit long stairs
        {
            win(t, RICHARD);
            continue;
        }
        // X/2 == min(R, C)

        // for X = 3 Gabriel wins, no good choice for Richard
        // for X = 4, 5 or 6 it is easy to figure out what Richard to choose to win
        win(t, (X == 3 ? GABRIEL : RICHARD));
    }

    return 0;
}
