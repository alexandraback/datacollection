#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int
main(void)
{
    int T;
    int i, j;
    long long X, Y;
    string s;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> X >> Y;
        s = "";

        while (X > 0) {
            s += "WE";
            X--;
        }
        while (X < 0) {
            s += "EW";
            X++;
        }
        while (Y > 0) {
            s += "SN";
            Y--;
        }
        while (Y < 0) {
            s += "NS";
            Y++;
        }

        cout << "Case #" << i << ": " << s << endl;
    }
    
    return 0;
}
