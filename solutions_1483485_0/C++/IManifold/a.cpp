#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NUM_LETTERS = 26;
const int EXAMPLES = 4;
const int MAX_LEN = 110;

char map[NUM_LETTERS];
char line[MAX_LEN];

void buildMap() {
  string code[EXAMPLES] = {
    "y qeez",
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
  };
  string text[EXAMPLES] = {
    "a zooq",
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
  };
  for (int i = 0; i < NUM_LETTERS; i++) {
    map[i] = -1;
  }
  for (int i = 0; i < EXAMPLES; i++) {
    for (int j = 0; j < code[i].size(); j++) {
      if (code[i][j] < 'a' || code[i][j] > 'z')
        continue;
      char letter = code[i][j] - 'a';
      if (map[letter] == -1) {
        map[letter] = text[i][j];
      } else if (map[letter] != text[i][j]) {
        printf("Bad translation: %d %d\n", i, j);
      }
    }
  }
  //for (int i = 0; i < NUM_LETTERS; i++)
  //  printf("%c = %d\n", (char)('a' + i), map[i]);
}

int main() {
  int tt;
  scanf("%d\n", &tt);
  buildMap();
  for (int t = 1; t <= tt; t++) {
    fgets(line, MAX_LEN, stdin);
    for (int i = 0; i < strlen(line); i++) {
      if (line[i] < 'a' || line[i] > 'z')
        continue;
      line[i] = map[line[i] - 'a'];
    }
    printf("Case #%d: %s", t, line);
  }

  return 0;
}
