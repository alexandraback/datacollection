#include <iostream>

using namespace std;

int solve(int n)
{
    bool seen[10];

    for (int i = 0; i < 10; i ++)
    {
        seen[i] = false;
    }

    for (int i = n; ; i += n)
    {
        {
            int t = i;
            while (t)
            {
                seen[t % 10] = true;
                t /= 10;
            }
        }

        bool seen_all = true;
        for (int j = 0; j < 10; j ++)
        {
            if (!seen[j])
            {
                seen_all = false;
                break;
            }
        }

        if (seen_all)
        {
            return i;
        }
    }
}

int main()
{
    int ct, t;

    cin >> t;
    for (ct = 1; ct <= t; ct ++)
    {
        int n;

        cin >> n;
        if (n == 0)
        {
            cout << "Case #" << ct << ": INSOMNIA" << endl;
        }
        else
        {
            cout << "Case #" << ct << ": " << solve(n) << endl;
        }
    }

    return 0;
}
