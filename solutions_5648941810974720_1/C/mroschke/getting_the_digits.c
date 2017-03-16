#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 2048

// -- UTILITY

// get the next integer input
int next_int() {
  int ret = 0;
  scanf("%d", &ret);
  return ret;
}

// get the next string input
void next_string(char* out) {
  scanf("%s", out);
}

// -- REAL FUNCTIONS

// instance solver
void solve_instance(char* str) {
  // get length of the string
  int len = strlen(str);

  // record the digits to output
  int digits[10];
  for(int i = 0; i < 10; i++) {
    digits[i] = 0;
  }

  // convert to counts of each digit
  int letters[26];
  for(int i = 0; i < 26; i++) {
    letters[i] = 0;
  }
  for(int i = 0; i < len; i++) {
    letters[tolower(str[i]) - 'a']++;
  }

  // check for the simple cases
  // Z = ZERO
  while(letters['z' - 'a'] > 0) {
    digits[0]++;
    letters['z' - 'a']--;
    letters['e' - 'a']--;
    letters['r' - 'a']--;
    letters['o' - 'a']--;
    len -= 4;
  }

  // W = TWO
  while(letters['w' - 'a'] > 0) {
    digits[2]++;
    letters['t' - 'a']--;
    letters['w' - 'a']--;
    letters['o' - 'a']--;
    len -= 3;
  }

  // G = EIGHT
  while(letters['g' - 'a'] > 0) {
    digits[8]++;
    letters['e' - 'a']--;
    letters['i' - 'a']--;
    letters['g' - 'a']--;
    letters['h' - 'a']--;
    letters['t' - 'a']--;
    len -= 5;
  }

  // X = SIX
  while(letters['x' - 'a'] > 0) {
    digits[6]++;
    letters['s' - 'a']--;
    letters['i' - 'a']--;
    letters['x' - 'a']--;
    len -= 3;
  }
  
  // NOW, S = SEVEN
  while(letters['s' - 'a'] > 0) {
    digits[7]++;
    letters['s' - 'a']--;
    letters['e' - 'a']--;
    letters['v' - 'a']--;
    letters['e' - 'a']--;
    letters['n' - 'a']--;
    len -= 5;
  }

  // NOW V = FIVE
  while(letters['v' - 'a'] > 0) {
    digits[5]++;
    letters['f' - 'a']--;
    letters['i' - 'a']--;
    letters['v' - 'a']--;
    letters['e' - 'a']--;
    len -= 4;
  }

  // now f = four
  while(letters['f' - 'a'] > 0) {
    digits[4]++;
    letters['f' - 'a']--;
    letters['o' - 'a']--;
    letters['u' - 'a']--;
    letters['r' - 'a']--;
    len -= 4;
  }

  // now t = three
  while(letters['t' - 'a'] > 0) {
    digits[3]++;
    letters['t' - 'a']--;
    letters['h' - 'a']--;
    letters['r' - 'a']--;
    letters['e' - 'a']--;
    letters['e' - 'a']--;
    len -= 5;
  }

  // now o = one
  while(letters['o' - 'a'] > 0) {
    digits[1]++;
    letters['o' - 'a']--;
    letters['n' - 'a']--;
    letters['e' - 'a']--;
    len -= 3;
  }

  // remainder is nines
  while(letters['n' - 'a'] > 0) {
    digits[9]++;
    letters['n' - 'a']--;
    letters['i' - 'a']--;
    letters['n' - 'a']--;
    letters['e' - 'a']--;
    len -= 4;
  }

  // sanity checks
  if(len != 0) {
    fprintf(stderr, "WARNING :: len failure\n");
  }
  for(int i = 0; i < 26; i++) {
    if(letters[i] != 0) {
      fprintf(stderr, "Warning :: letter %c nonzero count\n", 'a' + i);
    }
  }

  // print out the digits
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < digits[i]; j++) {
      printf("%d", i);
    }
  }
}

// main function
int main(int argc, char* argv[]) {
  // number of test cases
  int t = next_int();

  // storage for strings
  char str[MAX_LENGTH];

  // iterate over test cases
  for(int i = 1; i <= t; i++) {
    // read input string
    next_string(str);

    // print prefix
    printf("Case #%d: ", i);

    // solve instance
    solve_instance(str);

    // print suffix
    printf("\n");
  }
}

