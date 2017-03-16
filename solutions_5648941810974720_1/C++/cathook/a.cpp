#include <stdio.h>


const size_t SLEN_MAX = 2000;


void Update(int *num_digits, int *counter, int num, const char* ns, char c) {
  num_digits[num] = counter[c];
  for (int i = 0; ns[i] != '\0'; ++i) {
    counter[ns[i]] -= num_digits[num];
  }
}


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    static char str[SLEN_MAX + 1];
    scanf("%s", str);

    static int counter[256];
    for (int i = 'A'; i <= 'Z'; ++i) { counter[i] = 0; }

    for (int i = 0; str[i] != '\0'; ++i) { counter[str[i]] += 1; }

    static int num_digits[10];
    for (int i = 0; i <= 9; ++i) { num_digits[i] = 0; }

    Update(num_digits, counter, 0, "ZERO", 'Z');
    Update(num_digits, counter, 2, "TWO", 'W');
    Update(num_digits, counter, 4, "FOUR", 'U');
    Update(num_digits, counter, 6, "SIX", 'X');
    Update(num_digits, counter, 8, "EIGHT", 'G');
    Update(num_digits, counter, 1, "ONE", 'O');
    Update(num_digits, counter, 3, "THREE", 'T');
    Update(num_digits, counter, 5, "FIVE", 'F');
    Update(num_digits, counter, 7, "SEVEN", 'S');
    Update(num_digits, counter, 9, "NINE", 'E');

    printf("Case #%d: ", case_idx);
    for (int i = 0; i <= 9; ++i) {
      for (int j = 0; j < num_digits[i]; ++j) {
        printf("%d", i);
      }
    }
    printf("\n");
  }
  return 0;
}

//         A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// 0 ZERO          1                   1     1               1*
// 2 TWO                               1         1     1*
// 4 FOUR            1                 1     1     1*
// 6 SIX                   1                   1         1*
// 8 EIGHT         1   1*1 1                     1

// 1 ONE           1                 1 1*
// 3 THREE         2     1                   1   1*
// 5 FIVE          1 1*    1                         1
// 7 SEVEN         2                 1         1*    1

// 9 NINE          1*      1         2

