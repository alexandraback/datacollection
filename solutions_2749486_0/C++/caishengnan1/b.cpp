#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin >> T;

    for (int i = 0 ; i < T; i++)
    {
        int x, y;
        cin >> x >> y;

        string h, v;
        if (x > 0)
            h = "WE";
        else
            h = "EW";

        if (y > 0)
            v = "SN";
        else
            v = "NS";

      
        cout << "Case #" << i+1 << ": ";
        for (int m = 0; m < abs(x); m++)
            cout << h;
        for (int n = 0; n < abs(y); n++)
            cout << v;

        cout << endl;
    }

    return 0;
}

