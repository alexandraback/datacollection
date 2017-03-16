#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int t;
string s;

int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #"<<i<<": ";
        cin >> s;

        int h[400] = {0};
        int d[20] = {0};
        
        for (int j = 0; j < s.length(); j++)
            h[s[j]]++;
        
        d[0] = h['Z'];
        d[4] = h['U'];
        d[6] = h['X'];
        d[2] = h['W'];
        d[7] = h['S']-d[6];
        d[5] = h['V']-d[7];
        d[3] = h['R']-d[0]-d[4];
        d[1] = h['O']-d[0]-d[2]-d[4];
        d[8] = h['H']-d[3];
        d[9] = (h['N']-d[1]-d[7])/2;
        
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < d[j]; k++)
                cout << j;
        }
        cout << endl;
    }

    return 0;
}
