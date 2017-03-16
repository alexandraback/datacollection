#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int data[256];
int num[10];
int main() {
  string str;
  int T;
  cin >> T;
  int cas = 1;
  while(T--) {
    cin >> str;
    int n = str.size();
    memset(data, 0, sizeof data);
    memset(num, 0, sizeof num);
    for(int i = 0; i < n; i++) {
      data[str[i]] ++;
    }

    num[6] = data['X'];
    data['S'] -= num[6], data['I'] -= num[6], data['X'] -= num[6];

    num[2] = data['W'];
    data['T'] -= num[2], data['W'] -= num[2], data['O'] -= num[2];

    num[4] = data['U'];
    data['F'] -= num[4], data['O'] -= num[4], data['U'] -= num[4], data['R'] -= num[4];

    num[0] = data['Z'];
    data['Z'] -= num[0], data['O'] -= num[0], data['R'] -= num[0], data['E'] -= num[0];

    num[8] = data['G'];
    data['E'] -= num[8], data['I'] -= num[8], data['G'] -= num[8], data['H'] -= num[8], data['T'] -= num[8];

    num[7] = data['S'];
    data['S'] -= num[7], data['E'] -= num[7] * 2, data['V'] -= num[7], data['N'] -= num[7];

    num[5] = data['V'];
    data['F'] -= num[5], data['I'] -= num[5], data['V'] -= num[5], data['E'] -= num[5];

    num[3] = data['R'];
    data['T'] -= num[3], data['H'] -= num[3], data['R'] -= num[3], data['E'] -= 2 * num[3];

    num[9] = data['I'];
    data['N'] -= 2 * num[9], data['I'] -= num[9], data['E'] -= num[9];

    num[1] = data['O'];

    // for(int i = 0; i < 26; i++) {
    //   cout << data[i + 'A'] << endl;
    // }
    cout << "Case #" << cas++ << ": ";
    for(int i = 0; i <= 9; i++) {
      while(num[i]) {
        cout << i ;
        num[i]--;
      }
    }
    cout << endl;
  }
  return 0;
}