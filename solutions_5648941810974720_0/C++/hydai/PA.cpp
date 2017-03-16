#include <iostream>
#include <cstring>
using namespace std;
/*
 * *ZERO -> Z
 * *TWO -> W
 * *FOUR -> U
 * *SIX -> X
 * *EIGHT -> G
 * **ONE -> N
 * ***THREE -> TH
 * ****FIVE -> FV
 * *****SEVEN -> SV
 * ******NINE -> NI
 */
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        char str[10000];
        char ans[10000] = "";
        int mmap[10] = {};
        int chmap[1000] = {};
        cout << "Case #" << t << ": ";
        cin >> str;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            chmap[str[i]] ++;
        }
        mmap[0] = chmap['Z'];
        chmap['E'] -= chmap['Z'];
        chmap['R'] -= chmap['Z'];
        chmap['O'] -= chmap['Z'];
        chmap['E'] -= chmap['Z'];
        mmap[2] = chmap['W'];
        chmap['T'] -= chmap['W'];
        chmap['O'] -= chmap['W'];
        mmap[4] = chmap['U'];
        chmap['F'] -= chmap['U'];
        chmap['O'] -= chmap['U'];
        chmap['R'] -= chmap['U'];
        mmap[6] = chmap['X'];
        chmap['S'] -= chmap['X'];
        chmap['I'] -= chmap['X'];
        mmap[8] = chmap['G'];
        chmap['E'] -= chmap['G'];
        chmap['I'] -= chmap['G'];
        chmap['H'] -= chmap['G'];
        chmap['T'] -= chmap['G'];
        mmap[1] = chmap['O'];
        chmap['N'] -= chmap['O'];
        chmap['E'] -= chmap['O'];
        mmap[3] = chmap['R'];
        chmap['T'] -= chmap['R'];
        chmap['H'] -= chmap['R'];
        chmap['E'] -= 2*chmap['R'];
        mmap[5] = chmap['F'];
        chmap['I'] -= chmap['F'];
        chmap['V'] -= chmap['F'];
        chmap['E'] -= chmap['F'];
        mmap[7] = chmap['V'];
        chmap['S'] -= chmap['V'];
        chmap['E'] -= 2*chmap['V'];
        chmap['N'] -= chmap['V'];
        mmap[9] = chmap['N']/2;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < mmap[i]; j++) {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}
