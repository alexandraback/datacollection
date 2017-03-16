#include <bits/stdc++.h>
using namespace std;

char s[2001];
int c[256], ans[10];

int main() {
  int tc, cn;
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    printf("Case #%d: ", cn);
    scanf("%s", s);
    memset(c, 0, sizeof(c));
    memset(ans, 0, sizeof(ans));
    for(int i = 0; s[i]; i++)
      c[s[i]]++;
    //"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"    
    while(c['Z'] > 0) {
      ans[0]++;
      c['Z']--;
      c['E']--;
      c['R']--;
      c['O']--;
    }
    //"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"    
    while(c['G'] > 0) {
      ans[8]++;
      c['E']--;
      c['I']--;
      c['G']--;
      c['H']--;
      c['T']--;
    }
    //"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "NINE"
    while(c['X'] > 0) {
      ans[6]++;
      c['S']--;
      c['I']--;
      c['X']--;
    }
    //"ONE", "TWO", "THREE", "FOUR", "FIVE", "SEVEN", "NINE"
    while(c['S'] > 0) {
      ans[7]++;
      c['S']--;
      c['E']--;
      c['V']--;
      c['E']--;
      c['N']--;
    }
    //"ONE", "TWO", "THREE", "FOUR", "FIVE", "NINE"
    while(c['W'] > 0) {
      ans[2]++;
      c['T']--;
      c['W']--;
      c['O']--;
    }
    //"ONE", "THREE", "FOUR", "FIVE", "NINE"
    while(c['V'] > 0) {
      ans[5]++;
      c['F']--;
      c['I']--;
      c['V']--;
      c['E']--;
    }
    while(c['T'] > 0) {
      ans[3]++;
      c['T']--;
      c['H']--;
      c['R']--;
      c['E']--;
      c['E']--;
    }
    while(c['F'] > 0) {
      ans[4]++;
      c['F']--;
      c['O']--;
      c['U']--;
      c['R']--;
    }
    while(c['O'] > 0) {
      ans[1]++;
      c['O']--;
      c['N']--;
      c['E']--;
    }
    while(c['I'] > 0) {
      ans[9]++;
      c['N']--;
      c['I']--;
      c['N']--;
      c['E']--;
    }
    for(int i = 0; i <= 9; i++)
      while(ans[i] > 0) {
	printf("%d", i);
	ans[i]--;
      }
    puts("");
  }
}
