#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
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

        cout << "Case #" << i << ": " << missingcount << endl;
    }

    return 0;
}
