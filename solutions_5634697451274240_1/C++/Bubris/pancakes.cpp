#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main () {
    int t, flips;
    string s;
    char current;
    cin >> t;
    for(int j = 1; j <= t; j++) {
        cin >> s;
        current = s[0];
        flips = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != current) {
                flips++;
                current = s[i];
            }
        }
        if (current == '-') {
            flips++;
        }
        cout << "Case #" << j << ": " << flips << endl;;
    }

    return 0;
}
