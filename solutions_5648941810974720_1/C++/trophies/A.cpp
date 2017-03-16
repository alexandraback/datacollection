/*
 ZERO - by the Z
 TWO - by the W
 EIGHT - by the G
 THREE - by the T
 SIX - by the X
 SEVEN - by the S
 FOUR - by the R
 FIVE - by the V
 NINE - by the I
 ONE - by the O
 */

#include <iostream>

using namespace std;
int ascii [200];
int ans [200];
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int g=0; g<t; g++){
        cout << "Case #" << g + 1 <<": ";
        memset (ascii, 0, sizeof(ascii));
        string x; cin >> x;
        for (int y=0; y<x.length(); y++) ascii[x[y]]++;
        memset (ans, 0, sizeof(ans));
        ans['0']+=ascii['Z'];
        ascii['E'] -= ascii['Z'];
        ascii['R'] -= ascii['Z'];
        ascii['O'] -= ascii['Z'];
        ascii ['Z'] = 0;
        //
        ans['2']+=ascii['W'];
        ascii['O']-=ascii['W'];
        ascii['T']-=ascii['W'];
        ascii['W'] = 0;
        //
        ans['8']+=ascii['G'];
        ascii['E']-=ascii['G'];
        ascii['I']-=ascii['G'];
        ascii['H']-=ascii['G'];
        ascii['T']-=ascii['G'];
        ascii['G'] = 0;
        //
        ans['3']+=ascii['T'];
        ascii['E']-=ascii['T'];
        ascii['E']-=ascii['T'];
        ascii['H']-=ascii['T'];
        ascii['R']-=ascii['T'];
        ascii['T'] = 0;
        //
        ans['6']+=ascii['X'];
        ascii['S']-=ascii['X'];
        ascii['I']-=ascii['X'];
        ascii['X'] = 0;
        //
        ans['7']+=ascii['S'];
        ascii['E']-=ascii['S'];
        ascii['V']-=ascii['S'];
        ascii['E']-=ascii['S'];
        ascii['N']-=ascii['S'];
        ascii['S'] = 0;
        //
        ans['4']+=ascii['R'];
        ascii['O'] -= ascii['R'];
        ascii['U'] -= ascii['R'];
        ascii['F'] -= ascii['R'];
        ascii ['R'] = 0;
        //
        ans['5']+=ascii['V'];
        ascii['F'] -= ascii['V'];
        ascii['I'] -= ascii['V'];
        ascii['E'] -= ascii['V'];
        ascii ['V'] = 0;
        //
        ans['9']+=ascii['I'];
        ascii['N'] -= 2 * ascii['I'];
        ascii['E'] -= ascii['I'];
        ascii ['I'] = 0;
        //
        ans['1']+=ascii['O'];
        ascii['N']-=ascii['O'];
        ascii['E']-=ascii['O'];
        ascii['O'] = 0;
        //
        for (int y=0; y<200; y++){
            for (int z=0; z<ans[y]; z++) cout << char(y);
        }
        cout << endl;
    }
    return 0;
}