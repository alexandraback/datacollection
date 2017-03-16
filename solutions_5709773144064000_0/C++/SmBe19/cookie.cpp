/* Code Jam 2014
 * Task: Cookie
 * User: SmBe19 (Benjamin Schmid)
*/

#include <iostream>

using namespace std;

typedef long double ld;

int main()
{
    cout.precision(7);
    cout.setf(ios::fixed);

    int tcn;
    cin >> tcn;

    for(int tc = 1; tc <= tcn; tc++)
    {
        ld c, f, x;
        ld res = 0;
        ld rate = 2;
        cin >> c >> f >> x;
        while(x/rate > c/rate + x/(rate + f))
        {
            res += c/rate;
            rate += f;
        }
        res += x/rate;

        cout << "Case #" << tc << ": " << res << endl;
    }

    return 0;
}
