//
//  main.cpp
//  codejam
//
//  Created by Todor Lyubomirov Bonchev on 1/1/16.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

// Z -> ZEROes
// W -> TWOes
// U -> FOURes
// X -> SIXes
// G -> EIGHTs
// O -> ONEs
// T -> THREEs
// F -> FIVEs
// S -> SEVENs
// N -> NINEs

void solve() {
    string nmbr;
    cin >> nmbr;
    int L[255];
    memset(L, 0, sizeof(L));
    int numbers[10];
    fill(numbers,numbers+10,0);

    for (int i=0;i<nmbr.size();++i) {
        L[nmbr[i]]++;
    }
    while (L['Z']&&L['E']&&L['R']&&L['O']) {
        numbers[0]++;
        L['Z']--;L['E']--;L['R']--;L['O']--;
    }
    while (L['W']>0) {
        numbers[2]++;
        L['T']--;L['W']--;L['O']--;
    }
    while (L['U']>0) {
        numbers[4]++;
        L['F']--;L['O']--;L['U']--;L['R']--;
    }
    while (L['X']>0) {
        numbers[6]++;
        L['S']--;L['I']--;L['X']--;
    }
    while (L['G']>0) {
        numbers[8]++;
        L['E']--;L['I']--;L['G']--;L['H']--;L['T']--;
    }
    while (L['O']>0) {
        numbers[1]++;
        L['O']--;L['N']--;L['E']--;
    }
    while (L['T']>0) {
        numbers[3]++;
        L['T']--;L['H']--;L['R']--;L['E']--;L['E']--;
    }
    while (L['F']>0) {
        numbers[5]++;
        L['F']--;L['I']--;L['V']--;L['E']--;
    }
    while (L['S']>0) {
        numbers[7]++;
        L['S']--;L['E']--;L['V']--;L['E']--;L['N']--;
    }
    while (L['N']>0) {
        numbers[9]++;
        L['N']--;L['I']--;L['N']--;L['E']--;
    }
    string res;
    for (int i=0;i<10;++i) {
        while(numbers[i]-->0) res.push_back(i+'0');
    }
    cout << res << endl;
}

int main(int argc, const char * argv[]) {
    freopen("a.txt", "r", stdin);
    freopen("b.txt", "w", stdout);

    int tests;
    scanf("%d", &tests);
    for (int test=1;test<=tests;++test) {
        printf("Case #%d: ", test);
        solve();
    }

    return 0;
}
