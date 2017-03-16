#include <bits/stdc++.h>

using namespace std;

int x;
string s;
int t[500], ki[0];

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
cin >> x;
for(int y=1;y<=x;y++) {
    cin >> s;
    cout << "Case #" << y << ": ";
    for(int i='A';i<='Z';i++) t[i]=0;
    for(int i=0;i<s.size();i++) {
        t[s[i]]++;
    }
    ki[0]=t['Z'];
    t['E']-=ki[0];
    t['R']-=ki[0];
    t['O']-=ki[0];
    ki[2]=t['W'];
    t['T']-=ki[2];
    t['O']-=ki[2];
    ki[6]=t['X'];
    t['S']-=ki[6];
    t['I']-=ki[6];
    ki[7]=t['S'];
    t['E']-=ki[7];
    t['V']-=ki[7];
    t['E']-=ki[7];
    t['N']-=ki[7];
    ki[5]=t['V'];
    t['F']-=ki[5];
    t['I']-=ki[5];
    t['E']-=ki[5];
    ki[4]=t['U'];
    t['F']-=ki[4];
    t['O']-=ki[4];
    t['R']-=ki[4];
    ki[3]=t['R'];
    t['E']-=ki[3];
    t['T']-=ki[3];
    t['E']-=ki[3];
    t['H']-=ki[3];
    ki[8]=t['H'];
    t['E']-=ki[8];
    t['I']-=ki[8];
    t['G']-=ki[8];
    t['T']-=ki[8];
    ki[9]=t['I'];
    t['N']-=ki[9];
    t['N']-=ki[9];
    t['E']-=ki[9];
    ki[1]=t['O'];

    for(int i=0;i<=9;i++) {
        for(int j=0;j<ki[i];j++) cout << i;
    }
    cout << endl;
}
    return 0;
}
