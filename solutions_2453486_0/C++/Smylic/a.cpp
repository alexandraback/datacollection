#include <iostream>

using namespace std;

char a[8][8];

char p[4] = "XO";

int main()
{
    int t;
    cin >> t;
    for (int tt=1; tt<=t; tt++)
    {
        cin >> a[0] >> a[1] >> a[2] >> a[3];

        char ans = 'D';

        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                if (a[i][j] == '.')
                    ans = '.';

        for (int k=0; k<2; k++)
        {
            bool ok = true;
            for (int i=0; i<4; i++)
                ok &= a[i][i] == p[k] || a[i][i] == 'T';

            if (ok)
                ans = p[k];

            ok =  true;
            for (int i=0; i<4; i++)
                ok &= a[i][3-i] == p[k] || a[i][3-i] == 'T';

            if (ok)
                ans = p[k];

            for (int i=0; i<4; i++)
            {
                ok = true;
                for (int j=0; j<4; j++)
                    ok &= a[i][j] == p[k] || a[i][j] == 'T';

                if (ok)
                    ans = p[k];

                ok = true;
                for (int j=0; j<4; j++)
                    ok &= a[j][i] == p[k] || a[j][i] == 'T';

                if (ok)
                    ans = p[k];
            }
        }

        cout << "Case #" << tt << ": ";

        if (ans == 'X' || ans == 'O')
            cout << ans << " won" << endl;
        if (ans == 'D')
            cout << "Draw" << endl;
        if (ans == '.')
            cout << "Game has not completed" << endl;
    }
}
