#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

int n, m;
char str[1000000000];
map<char, int> cc;
int ans[20];

int main() {
  int T, tmp;
  scanf("%d", &T);
  for (int I = 1; I <= T; ++I) {
    scanf("%s", str);
    cc.clear();
    for (int i = 0; str[i]; ++i) {
      cc[str[i]]++;
    }
    for (int i = 0; i < 10; ++i) ans[i] = 0;
    // printf("HHH\n");

    // ZERO
    ans[0] = cc['Z'];
    cc['Z'] -= ans[0];
    cc['E'] -= ans[0];
    cc['R'] -= ans[0];
    cc['O'] -= ans[0];

    // TWO
    tmp = cc['W'];
    ans[2] = tmp;
    cc['T'] -= tmp;
    cc['W'] -= tmp;
    cc['O'] -= tmp;

    // EIGHT
    tmp = cc['G'];
    ans[8] = tmp;
    cc['E'] -= tmp;
    cc['I'] -= tmp;
    cc['G'] -= tmp;
    cc['H'] -= tmp;
    cc['T'] -= tmp;

    // SIX
    tmp = cc['X'];
    ans[6] = tmp;
    cc['S'] -= tmp;
    cc['I'] -= tmp;
    cc['X'] -= tmp;

    // SEVEN
    tmp = cc['S'];
    ans[7] = tmp;
    cc['S'] -= tmp;
    cc['E'] -= tmp;
    cc['V'] -= tmp;
    cc['E'] -= tmp;
    cc['N'] -= tmp;

    // THREE
    tmp = cc['H'];
    ans[3] = tmp;
    cc['T'] -= tmp;
    cc['H'] -= tmp;
    cc['R'] -= tmp;
    cc['E'] -= tmp;
    cc['E'] -= tmp;

    // FOUR
    tmp = cc['R'];
    ans[4] = tmp;
    cc['F'] -= tmp;
    cc['O'] -= tmp;
    cc['U'] -= tmp;
    cc['R'] -= tmp;

    // FIVE
    tmp = cc['F'];
    ans[5] = tmp;
    cc['F'] -= tmp;
    cc['I'] -= tmp;
    cc['V'] -= tmp;
    cc['E'] -= tmp;

    // ONE
    tmp = cc['O'];
    ans[1] = tmp;
    cc['O'] -= tmp;
    cc['N'] -= tmp;
    cc['E'] -= tmp;

    // NINE
    tmp = cc['I'];
    ans[9] = tmp;

    printf("Case #%d: ", I);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < ans[i]; ++j) printf("%d", i);
    }
    printf("\n");
  }
}
