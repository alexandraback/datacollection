#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int counter = 1; counter <= T; counter++) {
        int x, y;
        cin >> x >> y;

        cout << "Case #" << counter << ": ";

        const char *horiz = "WE";
        if (x < 0) {
            horiz = "EW";
            x = -x;
        }
        for (int i = 0; i < x; i++) {
            cout << horiz;
        }

        const char *vert = "SN";
        if (y < 0) {
            vert = "NS";
            y = -y;
        }
        for (int i = 0; i < y; i++) {
            cout << vert;
        }

        cout << "\n";
    }

    return 0;
}

