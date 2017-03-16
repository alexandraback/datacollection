#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int ROUNDUP(int a, int b) {
  return a % b ? (a/b) + 1 : a/b;
}

int main(void) {
  int numCases;
  cin >> numCases;

  for (int cases = 0; cases < numCases; cases++) {
    vector<int> table;
    int numCakes;
    cin >> numCakes;
    for (int c = 0; c < numCakes; c++) {
      int temp;
      cin >> temp;
      table.push_back(temp);
    }
    sort(table.begin(), table.end());
    int max = table[table.size()-1];
    int min = INT_MAX;

    for (int i = 1; i <= max; i++) {
      int acm = 0;
      for (int j = 0; j < table.size(); j++) {
        acm += ROUNDUP(table[j], i) - 1;
      }
      min = acm + i < min ? acm + i : min;
    }

    printf("Case #%d: %d\n", cases+1, min);
  }

  return 0;
};
