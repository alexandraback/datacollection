#include <iostream>

using namespace std;

char keys[] = {'Z', 'W', 'X', 'S', 'U', 'F', 'O', 'G', 'R', 'N'};
string overlap[] = {"ZERO", "TWO", "SIX", "SEVEN", "FOUR", "FIVE", "ONE", "EIGHT", "THREE", "NINE"};
int ints[] = {0, 2, 6, 7, 4, 5, 1, 8, 3, 9};

int main() {
  int lines;
  cin >> lines;
  for (int line = 0; line < lines; ++line) {
    string a;
    cin >> a;
    int lets[26] = {0};
    for (int i = 0; i < a.length(); ++i) {
      lets[a[i]-'A']++;
    }
    // int nums[10] = {0};
    // for (int i = 0; i < 10; ++i) {
    //   nums[ints[i]] = lets[keys[i] - 'A'];
    // }
    int nums[10] = {0};
    cout << "Case #" << (line + 1) << ": ";
    for (int i = 0; i < 10; ++i) {
      while(lets[keys[i] - 'A'] > 0) {
        nums[ints[i]]++;
        for(int a = 0; a < overlap[i].length(); a++) {
          lets[overlap[i][a] - 'A']--;
        }
      }
    }

    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < nums[i]; ++j) {
        cout << i;
      }
    }
    cout << endl;



  }
}