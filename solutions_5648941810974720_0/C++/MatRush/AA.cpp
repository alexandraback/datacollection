#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

const string pre[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[26], answer[10];
int contribute[10][26];
string s;

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i] - 'A']++;
    }
    answer[0] = cnt['Z' - 'A'];
    cnt['Z'-'A'] -= answer[0];
    cnt['E'-'A'] -= answer[0];
    cnt['R'-'A'] -= answer[0];
    cnt['O'-'A'] -= answer[0];
    
    answer[2] = cnt['W' - 'A'];
    cnt['T' - 'A'] -= answer[2];
    cnt['W' - 'A'] -= answer[2];
    cnt['O' - 'A'] -= answer[2];
    
    answer[4] = cnt['U' - 'A'];
    cnt['F'-'A'] -= answer[4];
    cnt['O'-'A'] -= answer[4];
    cnt['U'-'A'] -= answer[4];
    cnt['R'-'A'] -= answer[4];
    
    answer[1] = cnt['O' - 'A'];
    cnt['O'-'A'] -= answer[1];
    cnt['N'-'A'] -= answer[1];
    cnt['E'-'A'] -= answer[1];
    
    answer[6] = cnt['X' - 'A'];
    cnt['S'-'A'] -= answer[6];
    cnt['I'-'A'] -= answer[6];
    cnt['X'-'A'] -= answer[6];

    answer[7] = cnt['S' - 'A'];
    cnt['S'-'A'] -= answer[7];
    cnt['E'-'A'] -= answer[7];
    cnt['V'-'A'] -= answer[7];
    cnt['E'-'A'] -= answer[7];
    cnt['N'-'A'] -= answer[7];

    answer[5] = cnt['V' - 'A'];
    cnt['F'-'A'] -= answer[5];
    cnt['I'-'A'] -= answer[5];
    cnt['V'-'A'] -= answer[5];
    cnt['E'-'A'] -= answer[5];
            
    answer[9] = cnt['N' - 'A'] / 2;
    cnt['N'-'A'] -= answer[9];
    cnt['I'-'A'] -= answer[9];
    cnt['N'-'A'] -= answer[9];
    cnt['E'-'A'] -= answer[9];
    
    answer[8] = cnt['G' - 'A'];
    cnt['E'-'A'] -= answer[8];
    cnt['I'-'A'] -= answer[8];
    cnt['G'-'A'] -= answer[8];
    cnt['H'-'A'] -= answer[8];
    cnt['T'-'A'] -= answer[8];
    
    answer[3] = cnt['R' - 'A'];
    cnt['T'-'A'] -= answer[3];
    cnt['H'-'A'] -= answer[3];
    cnt['R'-'A'] -= answer[3];
    cnt['E'-'A'] -= answer[3];
    cnt['E'-'A'] -= answer[3];

    printf("Case #%d: ", T);
    for (int i = 0; i < 10; ++i) {
      int num = answer[i];
      for (int j = 0; j < num; ++j) {
        printf("%d", i);
      }
    }
    puts("");

    // for (int i = 0; i < 26; ++i) {
    //   printf("%d", cnt[i]);
    // }
    // puts("");
  }
}