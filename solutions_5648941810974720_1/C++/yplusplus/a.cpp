#include <iostream>
#include <set>
#include <string>
using namespace std;


/*
   "ZERO",
   "ONE",
   "TWO",
   "THREE",
   "FOUR",
   "FIVE",
   "SIX",
   "SEVEN",
   "EIGHT",
   "NINE"

   ['Z', 0]
   ['W', 2]
   ['G', 8]
   ['H', 3] - [8]
   ['U', 4]
   ['N', 1] - [2] - [4] - [0]
   ['F', 5] - [4]
   ['X', 6]
   ['V', 7] - [5]
   (['N', 9] - [1] - [7]) / 2
   */

int main() {
    int T, Case = 1;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        multiset<char> letters(s.begin(), s.end());
        int num[10] = {0};
        num[0] = letters.count('Z');
        num[2] = letters.count('W');
        num[8] = letters.count('G');
        num[3] = letters.count('H') - num[8];
        num[4] = letters.count('U');
        num[1] = letters.count('O') - num[0] - num[2] - num[4];
        num[5] = letters.count('F') - num[4];
        num[6] = letters.count('X');
        num[7] = letters.count('V') - num[5];
        num[9] = (letters.count('N') - num[1] - num[7]) / 2;
        cout << "Case #" << Case++ << ": ";
        for (int i = 0; i < 10; i++) {
            //cout << i << " " << num[i] << endl;
            if (num[i] > 0) {
                cout << string(num[i], '0' + i);
            }
        }
        cout << endl;
    }
    return 0;
}
