#include <stdio.h>
#include <string.h>
#include <cassert>

char s[10001];
int cnt[30], res[12];

int main(){
   int T, n;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d: ", t);
      scanf("%s", s);
      n = strlen(s);
      for(int i=0; i<26; ++i)
         cnt[i] = 0;
      for(int i=0; i<=9; ++i)
         res[i] = 0;
      for(int i=0; i<n; ++i)
         cnt[s[i] - 'A'] += 1;
      // ZERO
      while(cnt['Z' - 'A']){
         res[0] += 1;
         cnt['Z' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
         cnt['R' - 'A'] -= 1;
         cnt['O' - 'A'] -= 1;
      }
      // TWO
      while(cnt['W' - 'A']){
         res[2] += 1;
         cnt['T' - 'A'] -= 1;
         cnt['W' - 'A'] -= 1;
         cnt['O' - 'A'] -= 1;
      }
      // SIX
      while(cnt['X' - 'A']){
         res[6] += 1;
         cnt['S' - 'A'] -= 1;
         cnt['I' - 'A'] -= 1;
         cnt['X' - 'A'] -= 1;
      }
      // EIGHT
      while(cnt['G' - 'A']){
         res[8] += 1;
         cnt['E' - 'A'] -= 1;
         cnt['I' - 'A'] -= 1;
         cnt['G' - 'A'] -= 1;
         cnt['H' - 'A'] -= 1;
         cnt['T' - 'A'] -= 1;
      }
      // THREE
      while(cnt['H' - 'A']){
         res[3] += 1;
         cnt['T' - 'A'] -= 1;
         cnt['H' - 'A'] -= 1;
         cnt['R' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
      }
      // FOUR
      while(cnt['R' - 'A']){
         res[4] += 1;
         cnt['F' - 'A'] -= 1;
         cnt['O' - 'A'] -= 1;
         cnt['U' - 'A'] -= 1;
         cnt['R' - 'A'] -= 1;
      }
      // FIVE
      while(cnt['F' - 'A']){
         res[5] += 1;
         cnt['F' - 'A'] -= 1;
         cnt['I' - 'A'] -= 1;
         cnt['V' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
      }
      // SEVEN
      while(cnt['S' - 'A']){
         res[7] += 1;
         cnt['S' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
         cnt['V' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
         cnt['N' - 'A'] -= 1;
      }
      // ONE
      while(cnt['O' - 'A']){
         res[1] += 1;
         cnt['O' - 'A'] -= 1;
         cnt['N' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
      }
      // NINE
      while(cnt['N' - 'A']){
         res[9] += 1;
         cnt['N' - 'A'] -= 1;
         cnt['I' - 'A'] -= 1;
         cnt['N' - 'A'] -= 1;
         cnt['E' - 'A'] -= 1;
      }
      // assert
      for(int i=0; i<26; ++i)
         assert(cnt[i] == 0);
      // output
      for(int i=0; i<=9; ++i)
         for(int j=0; j<res[i]; ++j)
            printf("%d", i);
      printf("\n");
   }
   return 0;
}
