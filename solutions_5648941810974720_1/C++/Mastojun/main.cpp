#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#include <string>
using namespace std;

vector<string> nums = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

vector<pair<char, int>> order = {
  {'G', 8},
  {'U', 4},
  {'W', 2},
  {'X', 6},
  {'Z', 0},

  {'F', 5},
  {'T', 3},
  {'O', 1},
  {'S', 7},

  {'I', 9}
};

int main()
{
  int n;
  
  cin >> n;

  for (int kase = 1; kase <= n; kase++) {
    string number;
    cin >> number;
    vector<int> counter(26);

    for (char c : number) {
      counter[c - 'A']++;
    }

    vector<int> numCount(10);
    for (auto o : order) {
      if (counter[o.first - 'A'] != 0) {
        numCount[o.second] = counter[o.first - 'A'];
        for (char c : nums[o.second]) {
          counter[c - 'A'] -= numCount[o.second];
          if (counter[c - 'A'] < 0) {
            printf("!!!");
          }
        }
      }
    }

    for (int i = 0; i < 26; i++) {
      if (counter[i] != 0) {
        printf("??????????????\n");
      }

    }

    cout << "Case #" << kase << ": ";
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < numCount[i]; j++) {
        cout << i;
      }
    }
    cout << endl;
  }

  return 0;
}