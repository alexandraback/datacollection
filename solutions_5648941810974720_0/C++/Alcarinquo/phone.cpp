#include <bits/stdc++.h>

using namespace std;

char line[2005];
int numbers[10];
char letters[27];

int main() {
  int T;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%s", line);

    memset(letters, 0, sizeof(letters));

    for(int i = 0; line[i] != '\0'; i++) {
      letters[line[i]-'A'] += 1;
    }

    memset(numbers, 0, sizeof(numbers));

    numbers[0] = letters['Z'-'A'];
    letters['E'-'A'] -= numbers[0];
    letters['R'-'A'] -= numbers[0];
    letters['O' - 'A'] -= numbers[0];
    letters['Z'-'A'] = 0;

    numbers[8] = letters['G'-'A'];
    letters['E'-'A'] -= numbers[8];
    letters['I' - 'A'] -= numbers[8];
    letters['H'-'A'] -= numbers[8];
    letters['T'-'A'] -= numbers[8];
    letters['G'-'A'] = 0;

    numbers[3] = letters['H'-'A'];
    letters['T'-'A'] -= numbers[3];
    letters['R'-'A'] -= numbers[3];
    letters['E'-'A'] -= 2*numbers[3];
    letters['H'-'A'] = 0;

    numbers[4] = letters['R'-'A'];
    letters['F'-'A'] -= numbers[4];
    letters['O'-'A'] -= numbers[4];
    letters['U'-'A'] -= numbers[4];
    letters['R'-'A'] = 0;

    numbers[5] = letters['F'-'A'];
    letters['I'-'A'] -= numbers[5];
    letters['V'-'A'] -= numbers[5];
    letters['E'-'A'] -= numbers[5];
    letters['F'-'A'] = 0;

    numbers[7] = letters['V'-'A'];
    letters['S'-'A'] -= numbers[7];
    letters['E'-'A'] -= 2*numbers[7];
    letters['N'-'A'] -= numbers[7];
    letters['V'-'A'] = 0;

    numbers[2] = letters['W'-'A'];
    letters['T'-'A'] -= numbers[2];
    letters['O'-'A'] -= numbers[2];
    letters['W'-'A'] = 0;

    numbers[6] = letters['X'-'A'];
    letters['S'-'A'] -= numbers[6];
    letters['I'-'A'] -= numbers[6];
    letters['X'-'A'] = 0;

    numbers[1] = letters['O'-'A'];
    letters['N'-'A'] -= numbers[1];
    letters['E'-'A'] -= numbers[1];
    letters['O'-'A'] = 0;

    numbers[9] = letters['I'-'A'];

    printf("Case #%d: ", caso);

    for(int i = 0; i <= 9; i++) {
      for(int j = numbers[i]; j > 0; j--) {
        printf("%d", i);
      }
    }
    printf("\n");
  }

  return 0;
}
