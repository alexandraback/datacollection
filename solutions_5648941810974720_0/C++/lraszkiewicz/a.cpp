#include <bits/stdc++.h>

int main() {
   int T;
   scanf("%d", &T)?:0;
   for (int t = 1; t <= T; t++) {
      char s[2016];
      scanf(" %s", s)?:0;
      int len = strlen(s);
      int letter_count[200];
      std::fill(letter_count, letter_count+200, 0);
      for (int i = 0; i < len; i++) {
         letter_count[int(s[i])]++;
      }
      int digit_count[10];
      std::fill(digit_count, digit_count+30, 0);
      // ZERO
      digit_count[0] = letter_count['Z'];
      letter_count['E'] -= letter_count['Z'];
      letter_count['R'] -= letter_count['Z'];
      letter_count['O'] -= letter_count['Z'];
      letter_count['Z'] = 0;
      // TWO
      digit_count[2] = letter_count['W'];
      letter_count['T'] -= letter_count['W'];
      letter_count['O'] -= letter_count['W'];
      letter_count['W'] = 0;
      // FOUR
      digit_count[4] = letter_count['U'];
      letter_count['F'] -= letter_count['U'];
      letter_count['O'] -= letter_count['U'];
      letter_count['R'] -= letter_count['U'];
      letter_count['U'] = 0;
      // SIX
      digit_count[6] = letter_count['X'];
      letter_count['S'] -= letter_count['X'];
      letter_count['I'] -= letter_count['X'];
      letter_count['X'] = 0;
      // EIGHT
      digit_count[8] = letter_count['G'];
      letter_count['E'] -= letter_count['G'];
      letter_count['I'] -= letter_count['G'];
      letter_count['H'] -= letter_count['G'];
      letter_count['T'] -= letter_count['G'];
      letter_count['G'] = 0;
      // ONE
      digit_count[1] = letter_count['O'];
      letter_count['N'] -= letter_count['O'];
      letter_count['E'] -= letter_count['O'];
      letter_count['O'] = 0;
      // THREE
      digit_count[3] = letter_count['R'];
      letter_count['T'] -= letter_count['R'];
      letter_count['H'] -= letter_count['R'];
      letter_count['E'] -= 2*letter_count['R'];
      letter_count['R'] = 0;
      // FIVE
      digit_count[5] = letter_count['F'];
      letter_count['I'] -= letter_count['F'];
      letter_count['V'] -= letter_count['F'];
      letter_count['E'] -= letter_count['F'];
      letter_count['F'] = 0;
      // SEVEN
      digit_count[7] = letter_count['S'];
      letter_count['E'] -= 2*letter_count['S'];
      letter_count['V'] -= letter_count['S'];
      letter_count['N'] -= letter_count['S'];
      letter_count['S'] = 0;
      // NINE
      digit_count[9] = letter_count['I'];
      letter_count['N'] -= 2*letter_count['I'];
      letter_count['E'] -= letter_count['I'];
      letter_count['I'] = 0;
      printf("Case #%d: ", t);
      for(int i = 0; i < 10; i++) {
         for(int j = 0; j < digit_count[i]; j++) {
            printf("%d", i);
         }
      }
      puts("");
   }
   return 0;
}
