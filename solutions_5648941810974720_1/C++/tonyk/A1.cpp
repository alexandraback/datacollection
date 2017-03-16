#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    string s;
    
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> s;
        int len = s.length();
        
        int num[10] = {0};
        int chs[26] = {0};
        
        for (int j = 0; j < len; j++) {
            chs[s[j] - 'A']++;
        }
        
        int tmp;
        
        // zeros
        tmp = chs['Z' - 'A'];
        num[0] += tmp;
        chs['Z' - 'A'] -= tmp;
        chs['E' - 'A'] -= tmp;
        chs['R' - 'A'] -= tmp;
        chs['O' - 'A'] -= tmp;

        // twos
        tmp = chs['W' - 'A'];
        num[2] += tmp;
        chs['T' - 'A'] -= tmp;
        chs['W' - 'A'] -= tmp;
        chs['O' - 'A'] -= tmp;

        // sixs
        tmp = chs['X' - 'A'];
        num[6] += tmp;
        chs['S' - 'A'] -= tmp;
        chs['I' - 'A'] -= tmp;
        chs['X' - 'A'] -= tmp;

        // eights
        tmp = chs['G' - 'A'];
        num[8] += tmp;
        chs['E' - 'A'] -= tmp;
        chs['I' - 'A'] -= tmp;
        chs['G' - 'A'] -= tmp;
        chs['H' - 'A'] -= tmp;
        chs['T' - 'A'] -= tmp;

        // threes
        tmp = chs['T' - 'A'];
        num[3] += tmp;
        chs['T' - 'A'] -= tmp;
        chs['H' - 'A'] -= tmp;
        chs['R' - 'A'] -= tmp;
        chs['E' - 'A'] -= 2 * tmp;

        // fours
        tmp = chs['R' - 'A'];
        num[4] += tmp;
        chs['F' - 'A'] -= tmp;
        chs['O' - 'A'] -= tmp;
        chs['U' - 'A'] -= tmp;
        chs['R' - 'A'] -= tmp;

        // fives
        tmp = chs['F' - 'A'];
        num[5] += tmp;
        chs['F' - 'A'] -= tmp;
        chs['I' - 'A'] -= tmp;
        chs['V' - 'A'] -= tmp;
        chs['E' - 'A'] -= tmp;
        
        // ones
        tmp = chs['O' - 'A'];
        num[1] += tmp;
        chs['O' - 'A'] -= tmp;
        chs['N' - 'A'] -= tmp;
        chs['E' - 'A'] -= tmp;

        // sevens
        tmp = chs['S' - 'A'];
        num[7] += tmp;
        chs['S' - 'A'] -= tmp;
        chs['E' - 'A'] -= tmp;
        chs['V' - 'A'] -= tmp;
        chs['E' - 'A'] -= tmp;
        chs['N' - 'A'] -= tmp;

        // nines
        tmp = chs['E' - 'A'];
        num[9] += tmp;
        chs['N' - 'A'] -= tmp;
        chs['I' - 'A'] -= tmp;
        chs['N' - 'A'] -= tmp;
        chs['E' - 'A'] -= tmp;
        
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < num[j]; k++) {
                cout << j;
            }
        }
        cout << endl;
    }
    
    return 0;
}
