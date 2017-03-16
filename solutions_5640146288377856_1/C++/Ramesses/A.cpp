#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int t,r,c,w,s;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    cin >> t;

    for(int k = 1; k <= t; ++k)
    {
        cin >> r >> c >> w;
        s = r*(c/w);
        if (c == w)
            s += w - 1;
        else
        {
            if (c % w == 0)
                s -= 2;
            else
                s -= 1;
            s += w + 1;
        }
        cout << "Case #" << k << ": " << s << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
