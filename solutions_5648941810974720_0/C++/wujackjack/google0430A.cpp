#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

string help(string s) {
    vector <int> al(26, 0);
    vector <int> res(10, 0);
    int len = s.size();
    for (int i = 0; i < len; i++) {
        al[s[i] - 'A']++;
    }
    res[8] += al['G' - 'A'];
    res[4] += al['U' - 'A'];
    res[0] += al['Z' - 'A'];
    res[2] += al['W' - 'A'];
    res[6] += al['X' - 'A'];
    al['E' - 'A'] -= al['G' - 'A'];
    al['I' - 'A'] -= al['G' - 'A'];
    al['H' - 'A'] -= al['G' - 'A'];
    al['T' - 'A'] -= al['G' - 'A'];

    al['F' - 'A'] -= al['U' - 'A'];
    al['O' - 'A'] -= al['U' - 'A'];
    al['R' - 'A'] -= al['U' - 'A'];

    al['E' - 'A'] -= al['Z' - 'A'];
    al['R' - 'A'] -= al['Z' - 'A'];
    al['O' - 'A'] -= al['Z' - 'A'];

    al['T' - 'A'] -= al['W' - 'A'];
    al['O' - 'A'] -= al['W' - 'A'];

    al['S' - 'A'] -= al['X' - 'A'];
    al['I' - 'A'] -= al['X' - 'A'];

    res[1] += al['O' - 'A'];
    res[3] += al['R' - 'A'];
    res[5] += al['F' - 'A'];
    res[7] += al['S' - 'A'];

    al['N' - 'A'] -= al['O' - 'A'];
    al['E' - 'A'] -= al['O' - 'A'];

    al['T' - 'A'] -= al['R' - 'A'];
    al['H' - 'A'] -= al['R' - 'A'];
    al['E' - 'A'] -= al['R' - 'A'] * 2;

    al['I' - 'A'] -= al['F' - 'A'];
    al['V' - 'A'] -= al['F' - 'A'];
    al['E' - 'A'] -= al['F' - 'A'];

    al['V' - 'A'] -= al['S' - 'A'];
    al['N' - 'A'] -= al['S' - 'A'];
    al['E' - 'A'] -= al['S' - 'A'] * 2;

    res[9] += al['I' - 'A'];

    string re;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < res[i]; j++)
            re.append(1, '0' + i);
    }

    return re;
    //if (s[i] == 'G' || s[i] == 'U' || s[i] == 'Z' || s[i] == 'W' || s[i] == 'X')
}

int main() {
    int T;
    cin>>T;
    int cnt = 0;
    while (T--) {
        cnt++;
        string s;
        cin>>s;
        printf("Case #%d: %s\n", cnt, help(s).c_str());
    }
    return 0;
}
