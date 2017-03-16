//#include "testlib.h"
//#include <spoj.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <set>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
//#include <unordered_map>

using namespace std;

int cc[11];
int cou[1111];

string getAns(string s) {
    memset(cou, 0, sizeof cou);
    for(int i = 0; i < s.size(); ++i)
        cou[s[i]]++;

    cc[0] = cou['Z'];
    for(int i = 0; i < cc[0]; ++i)
        cou['Z']--, cou['E']--, cou['R']--, cou['O']--;
    cc[6] = cou['X'];
    for(int i = 0; i < cc[6]; ++i)
        cou['X']--, cou['S']--, cou['I']--;
    cc[4] = cou['U'];
    for(int i = 0; i < cc[4]; ++i)
        cou['F']--, cou['O']--, cou['U']--, cou['R']--;
    cc[5] = cou['F'];
    for(int i = 0; i < cc[5]; ++i)
        cou['F']--, cou['I']--, cou['V']--, cou['E']--;
    cc[7] = cou['V'];
    for(int i = 0; i < cc[7]; ++i)
        cou['S']--, cou['E']--, cou['V']--, cou['E']--, cou['N']--;
    cc[2] = cou['W'];
    for(int i = 0; i < cc[2]; ++i)
        cou['T']--, cou['W']--, cou['O']--;
    cc[8] = cou['G'];
    for(int i = 0; i < cc[8]; ++i)
        cou['E']--, cou['I']--, cou['G']--, cou['H']--, cou['T']--;
    cc[9] = cou['I'];
    for(int i = 0; i < cc[9]; ++i)
        cou['N']--, cou['I']--, cou['N']--, cou['E']--;
    cc[1] = cou['O'];
    for(int i = 0; i < cc[2]; ++i)
        cou['O']--, cou['N']--, cou['E']--;
    cc[3] = cou['T'];

    string res = "";
    for(int i = 0; i < 10; ++i)
    while (cc[i] --> 0)
        res += (i + '0');
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;
    for(int i = 0; i < tt; ++i) {
        string s;
        cin >> s;
        cout << "Case #" << i+1 << ": ";
        cout << getAns(s) << "\n";
    }

    return 0;
}
