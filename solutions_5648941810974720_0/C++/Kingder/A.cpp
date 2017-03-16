#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std;


string digit[] = {
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
};

void  get(int* a, int id, int count) {
    for (int i = 0; i < digit[id].size(); i ++) {
        a[digit[id][i]] -= count;
    }
}

string gao(char digit, char unique, int* a) {
//   cout << digit << " " << unique << " " << a[unique] << endl;
    string ret(a[unique], digit);
    //string ret = "";
    //for (int i = 0; i < a[unique]; i ++) ret += string(digit, 1);
    //cout << ret << endl;
    get(a, digit - '0', a[unique]);
    return ret;
}

int main() {
   int cases; cin >> cases;
   for (int tc = 1; tc <= cases; tc ++) {
        string s;
        cin >> s;
        int digits[256];
        fill(digits, digits + 256, 0);
        for (int i = 0; i < s.size(); i ++) {
            digits[s[i]] ++;
        }
        cout << "Case #" << tc << ": ";
        int index = 0;
        string number = "";
        
        number += gao('0', 'Z', digits);
        number += gao('2', 'W', digits);
        number += gao('4', 'U', digits);
        number += gao('6', 'X', digits);
        number += gao('8', 'G', digits);
        number += gao('7', 'S', digits);
        number += gao('5', 'F', digits);
        number += gao('1', 'O', digits);
        number += gao('9', 'I', digits);
            
        number += gao('3', 'H', digits);
        sort(number.begin(), number.end());

        cout << number << endl;
   }
}
