/* Code Jam 2014
 * Task: Part Elf
 * User: SmBe19 (Benjamin Schmid)
*/

#include <iostream>
#include <string>

using namespace std;

typedef long long int lli;

int main()
{
    int tcn;
    cin >> tcn;
    for(int tc = 1; tc <= tcn; tc++){
        lli p = 0, q = 0;
        string s;
        cin >> s;
        int ap;
        for(ap = 0; s[ap] != '/'; ap++)
        {
            p *= 10;
            p += s[ap] - '0';
        }
        for(ap++; ap < s.length(); ap++)
        {
            q *= 10;
            q += s[ap] - '0';
        }

        int sol = 41;
        int ar = 1;
        if(p == 0 || p == q)
        {
            sol = 0;
        }
        else
        {
            while(ar <= 40)
            {
                if(q % 2 == 1)
                {
                    p *= 2;
                    q *= 2;
                }

                q /= 2;
                if(p >= q)
                {
                    if(ar < sol)
                    {
                        sol = ar;
                    }
                    p -= q;
                }
                if(p == q || p == 0)
                {
                    break;
                }
                ar++;
            }
        }
        if(ar <= 40 && sol <= 40)
        {
            cout << "Case #" << tc << ": " << sol << endl;
        }
        else
        {
            cout << "Case #" << tc << ": " << "impossible" << endl;
        }
    }

    return 0;
}
