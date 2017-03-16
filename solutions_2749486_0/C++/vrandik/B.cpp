#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <set>
#include <string>

using namespace std;

string solve() 
{
    string s = "";
    int X, Y;
    cin >> X >> Y;

    string xs;
    string ys;

    if (X < 0) {
        xs = "EW";
    } else {
        xs = "WE";
    }

    if (Y < 0) {
        ys = "NS";
    } else {
        ys = "SN";
    }


    for (int i = 0; i < abs(X); ++i) {
        s += xs;
    }

    for (int i = 0; i < abs(Y); ++i) {
        s += ys;
    }

    assert(s.length() < 500);

    return s;   
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}