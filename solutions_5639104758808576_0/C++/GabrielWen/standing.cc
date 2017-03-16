#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int charToInt(char input) {return input - '0';};

int main(void) {
  int numCases;
  cin >> numCases;

  for (int cases = 0; cases < numCases; cases++) {
    int max;
    char temp[2000];
    cin >> max >> temp;
    string people(temp);
    long long acm = charToInt(people[0]);
    long long ret = 0;

    for (int i = 1; i < people.size(); i++) {
      int tar = charToInt(people[i]);
      if (acm < i) {
        ret += i - acm;
        acm = i;
      }

      acm += tar;
    }

    printf("Case #%d: %lld\n", cases+1, ret);
  }

  return 0;
};
