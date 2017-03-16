#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool G[50][50];

ll t,b,m;

int main()
{
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> b >> m;

        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                G[i][j] = 0;
            }
        }

        if ((1<<(b-2))<m)
        {
            cout << "Case #" << i+1  << ": IMPOSSIBLE" << endl;
            continue;
        }

        for (int i = 0; i < b-1; ++i)
        {
            for (int j = i+1; j < b-1; ++j)
            {
                G[i][j] = 1;
            }
        }

        if (m==(1<<(b-2)))
        {
            for (int i = 0; i < b-1; ++i)
            {
                G[i][b-1] = true;
            }
        }
        else
        {
            int pos = 1;

            while (m)
            {
                if (m%2)
                {
                    G[pos][b-1] = true;
                }

                m >>= 1;
                pos++;
            }
        }

        cout << "Case #" << i+1 << ": POSSIBLE" << endl;

        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                cout << G[i][j];
            }

            cout << endl;
        }
    }
}
