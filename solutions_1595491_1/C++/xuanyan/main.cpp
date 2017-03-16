#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        int N, S, p;
        cin >> N >> S >> p;
        int line1, line2;

        if (p <= 1)
            line1 = line2 = p;
        else
        {
            line1 = 3 * p - 2;
            line2 = 3 * p - 4;
        }

        int good = 0, ok = 0;

        for (int j = 0; j < N; ++j)
        {
            int t;
            cin >> t;

            if (t >= line1)
                ++good;
            else if (t >= line2)
                ++ok;
        }

        cout << "Case #" << i << ": " << good + min(S, ok) << endl;
    }
}
