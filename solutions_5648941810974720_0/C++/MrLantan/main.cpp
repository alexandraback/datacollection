//
//  main.cpp
//  A
//
//  Created by Andrey Cherevko on 4/30/16.
//  Copyright © 2016 Andrey Cherevko. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>

int letters[30];
int numbers [20];

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("outSmall.txt", "w", stdout);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        string s;
        string ans = "";
        cin >> s;

        for (int i = 0; i < 30; i++)
            letters[i] = 0;
        for (int i = 0; i < 20; i++)
            numbers[i] = 0;

        for (int i = 0; i < s.length(); i++) {
            letters[(s[i] - 'A')]++;
        }
        numbers[0] = letters['Z' - 'A'];
        letters['Z' - 'A'] -= numbers[0];
        letters['E' - 'A'] -= numbers[0];
        letters['R' - 'A'] -= numbers[0];
        letters['O' - 'A'] -= numbers[0];

        numbers[2] = letters['W' - 'A'];
        letters['T' - 'A'] -= numbers[2];
        letters['W' - 'A'] -= numbers[2];
        letters['O' - 'A'] -= numbers[2];

        numbers[6] = letters['X' - 'A'];
        letters['S' - 'A'] -= numbers[6];
        letters['I' - 'A'] -= numbers[6];
        letters['X' - 'A'] -= numbers[6];

        numbers[7] = letters['S' - 'A'];
        letters['S' - 'A'] -= numbers[7];
        letters['E' - 'A'] -= numbers[7];
        letters['V' - 'A'] -= numbers[7];
        letters['E' - 'A'] -= numbers[7];
        letters['N' - 'A'] -= numbers[7];

        numbers[5] = letters['V' - 'A'];
        letters['F' - 'A'] -= numbers[5];
        letters['I' - 'A'] -= numbers[5];
        letters['V' - 'A'] -= numbers[5];
        letters['E' - 'A'] -= numbers[5];

        numbers[4] = letters['U' - 'A'];
        letters['F' - 'A'] -= numbers[4];
        letters['O' - 'A'] -= numbers[4];
        letters['U' - 'A'] -= numbers[4];
        letters['R' - 'A'] -= numbers[4];

        numbers[3] = letters['R' - 'A'];
        letters['T' - 'A'] -= numbers[3];
        letters['H' - 'A'] -= numbers[3];
        letters['R' - 'A'] -= numbers[3];
        letters['E' - 'A'] -= numbers[3];
        letters['E' - 'A'] -= numbers[3];

        numbers[8] = letters['H' - 'A'];
        letters['E' - 'A'] -= numbers[8];
        letters['I' - 'A'] -= numbers[8];
        letters['G' - 'A'] -= numbers[8];
        letters['H' - 'A'] -= numbers[8];
        letters['T' - 'A'] -= numbers[8];

        numbers[9] = letters['I' - 'A'];
        letters['N' - 'A'] -= numbers[9];
        letters['I' - 'A'] -= numbers[9];
        letters['N' - 'A'] -= numbers[9];
        letters['E' - 'A'] -= numbers[9];

        numbers[1] = letters['N' - 'A'];
        letters['O' - 'A'] -= numbers[1];
        letters['N' - 'A'] -= numbers[1];
        letters['E' - 'A'] -= numbers[1];







        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < numbers[i]; j++)
                ans += ('0' + i);
        }

        cout << "Case #" << tt + 1 << ": " << ans << endl;
    }
    return 0;
}
