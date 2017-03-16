/*
 g++ --std=c++11 -Wl,--stack=0x1000000 C.cc
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <gmpxx.h>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(false);
    cout.precision(8);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        string S;
        cin >> S;
        string o;
        for(auto c : S){
            if (o + c < c + o)
                o = c + o;
            else
                o = o + c;
        }

        cout << "Case #" << t << ": " << o << endl;
    }
}
