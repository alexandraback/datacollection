#include <iostream>

using namespace std;

int ccount[1000];
int cnt[10];
char str[10000];

int main() {
    int T, tc;

    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";

        memset(ccount, 0, sizeof(ccount));
        memset(cnt, 0, sizeof(cnt));
        cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            ccount[str[i]]++;
        }
        cnt[0] = ccount['Z'];
        cnt[2] = ccount['W'];
        cnt[4] = ccount['U'];
        cnt[6] = ccount['X'];
        cnt[8] = ccount['G'];
        
        ccount['Z'] -= cnt[0];
        ccount['E'] -= cnt[0];
        ccount['R'] -= cnt[0];
        ccount['O'] -= cnt[0];

        ccount['T'] -= cnt[2];
        ccount['W'] -= cnt[2];
        ccount['O'] -= cnt[2];

        ccount['F'] -= cnt[4];
        ccount['O'] -= cnt[4];
        ccount['U'] -= cnt[4];
        ccount['R'] -= cnt[4];

        ccount['S'] -= cnt[6];
        ccount['I'] -= cnt[6];
        ccount['X'] -= cnt[6];

        ccount['E'] -= cnt[8];
        ccount['I'] -= cnt[8];
        ccount['G'] -= cnt[8];
        ccount['H'] -= cnt[8];
        ccount['T'] -= cnt[8];

        cnt[1] = ccount['O'];
        cnt[3] = ccount['R'];
        cnt[5] = ccount['F'];
        cnt[7] = ccount['S'];

        ccount['O'] -= cnt[1];
        ccount['N'] -= cnt[1];
        ccount['E'] -= cnt[1];

        ccount['T'] -= cnt[3];
        ccount['H'] -= cnt[3];
        ccount['R'] -= cnt[3];
        ccount['E'] -= cnt[3];
        ccount['E'] -= cnt[3];

        ccount['F'] -= cnt[5];
        ccount['I'] -= cnt[5];
        ccount['V'] -= cnt[5];
        ccount['E'] -= cnt[5];

        ccount['S'] -= cnt[7];
        ccount['E'] -= cnt[7];
        ccount['V'] -= cnt[7];
        ccount['E'] -= cnt[7];
        ccount['N'] -= cnt[7];

        cnt[9] = ccount['I'];
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}
