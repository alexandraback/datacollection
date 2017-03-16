#include <iostream>

using namespace std;

const int SIZE = 255;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    string s;
    cin >> s;
    int cnt[SIZE];
    int ans[SIZE];
    for (int i = 0; i < SIZE; ++i)
      cnt[i] = ans[i] = 0;
    for (char c : s)
      ++cnt[(int) c];
    cout << "Case #" << test + 1 << ": ";
    //0
    ans[0] = cnt['Z'];
    cnt['Z'] -= ans[0];
    cnt['E'] -= ans[0];
    cnt['R'] -= ans[0];
    cnt['O'] -= ans[0];
    //8
    ans[8] = cnt['G'];
    cnt['E'] -= ans[8];
    cnt['I'] -= ans[8];
    cnt['G'] -= ans[8];
    cnt['H'] -= ans[8];
    cnt['T'] -= ans[8];
    //6
    ans[6] = cnt['X'];
    cnt['S'] -= ans[6];
    cnt['I'] -= ans[6];
    cnt['X'] -= ans[6];
    //7
    ans[7] = cnt['S'];
    cnt['S'] -= ans[7];
    cnt['E'] -= ans[7];
    cnt['V'] -= ans[7];
    cnt['E'] -= ans[7];
    cnt['N'] -= ans[7];
    //2
    ans[2] = cnt['W'];
    cnt['T'] -= ans[2];
    cnt['W'] -= ans[2];
    cnt['O'] -= ans[2];
    //3
    ans[3] = cnt['H'];
    cnt['T'] -= ans[3];
    cnt['H'] -= ans[3];
    cnt['R'] -= ans[3];
    cnt['E'] -= ans[3];
    cnt['E'] -= ans[3];
    //4
    ans[4] = cnt['R'];
    cnt['F'] -= ans[4];
    cnt['O'] -= ans[4];
    cnt['U'] -= ans[4];
    cnt['R'] -= ans[4];
    //5
    ans[5] = cnt['F'];
    cnt['F'] -= ans[5];
    cnt['I'] -= ans[5];
    cnt['V'] -= ans[5];
    cnt['E'] -= ans[5];
    //9
    ans[9] = cnt['I'];
    cnt['N'] -= ans[9];
    cnt['I'] -= ans[9];
    cnt['N'] -= ans[9];
    cnt['E'] -= ans[9];
    //1
    ans[1] = cnt['O'];
    cnt['O'] -= ans[1];
    cnt['N'] -= ans[1];
    cnt['E'] -= ans[1];
    for (int i = 0; i <= 9; ++i)
      for (int j = 0; j < ans[i]; ++j)
        cout << i;
    cout << endl;
  }
  return 0;
}
