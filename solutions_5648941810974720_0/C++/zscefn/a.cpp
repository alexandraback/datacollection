#include <iostream>
using namespace std; 
int main() {
    int tt;
    cin>>tt;
    for(int xx = 1; xx <= tt; ++xx) {
        cout<<"Case #"<<xx<<": ";
        string s;
        cin>>s;
        int cnt[1000] = {0};
        for(int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]];
        }
        int num[10] = {0};
        num[0] = cnt['Z'];
        cnt['Z'] -= num[0];
        cnt['E'] -= num[0];
        cnt['R'] -= num[0];
        cnt['O'] -= num[0];
        num[2] = cnt['W'];
        cnt['T'] -= num[2];
        cnt['W'] -= num[2];
        cnt['O'] -= num[2];
        num[6] = cnt['X'];
        cnt['S'] -= num[6];
        cnt['I'] -= num[6];
        cnt['X'] -= num[6];
        num[8] = cnt['G'];
        cnt['E'] -= num[8];
        cnt['I'] -= num[8];
        cnt['G'] -= num[8];
        cnt['H'] -= num[8];
        cnt['T'] -= num[8];
        num[4] = cnt['U'];
        cnt['F'] -= num[4];
        cnt['O'] -= num[4];
        cnt['U'] -= num[4];
        cnt['R'] -= num[4];
        num[5] = cnt['F'];
        cnt['F'] -= num[5];
        cnt['I'] -= num[5];
        cnt['V'] -= num[5];
        cnt['E'] -= num[5];
        num[1] = cnt['O'];
        cnt['O'] -= num[1];
        cnt['N'] -= num[1];
        cnt['E'] -= num[1];
        num[7] = cnt['S'];
        cnt['S'] -= num[7];
        cnt['E'] -= num[7];
        cnt['V'] -= num[7];
        cnt['E'] -= num[7];
        cnt['N'] -= num[7];
        num[3] = cnt['R'];
        cnt['T'] -= num[3];
        cnt['H'] -= num[3];
        cnt['R'] -= num[3];
        cnt['E'] -= num[3];
        cnt['E'] -= num[3];
        num[9] = cnt['N']/2;
        cnt['N'] -= num[9];
        cnt['I'] -= num[9];
        cnt['N'] -= num[9];
        cnt['E'] -= num[9];
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < num[i]; ++j) {
                cout<<i;
            }
        }
        cout<<'\n';

    }
}
