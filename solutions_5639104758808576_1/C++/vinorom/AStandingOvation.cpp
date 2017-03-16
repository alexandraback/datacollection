#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int smax;
        string str;
        cin >> smax >> str;

        int upcount = 0;
        int missingcount = 0;
        for (int s = 0; s <= smax; ++s)
        {
            int scount = str[s] - '0';
            if (upcount < s)
            {
                missingcount += s - upcount;
                upcount += s - upcount;
            }
            upcount += scount;
        }

        cout << "Case #" << t << ": " << missingcount << endl;
    }

    return 0;
}
