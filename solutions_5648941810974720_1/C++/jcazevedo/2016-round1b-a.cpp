#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int T;
string s;

void digitErase(string word) {
  for (auto i = 0; i < word.size(); i++) {
    auto it = s.find(word[i]);
    if (it != string::npos)
      s.erase(it, 1);
  }
}

int main() {
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    cin >> s;
    vector<int> res;
    while (s.find('Z') != string::npos) { // 0
      res.push_back(0);
      digitErase(string("ZERO"));
    }
    while (s.find('W') != string::npos) { // 2
      res.push_back(2);
      digitErase("TWO");
    }
    while (s.find('X') != string::npos) { // 6
      res.push_back(6);
      digitErase("SIX");
    }
    while (s.find('S') != string::npos) { // 7
      res.push_back(7);
      digitErase("SEVEN");
    }
    while (s.find('V') != string::npos) { // 5
      res.push_back(5);
      digitErase("FIVE");
    }
    while (s.find('U') != string::npos) { // 4
      res.push_back(4);
      digitErase("FOUR");
    }
    while (s.find('O') != string::npos) { // 1
      res.push_back(1);
      digitErase("ONE");
    }
    while (s.find('G') != string::npos) { // 8
      res.push_back(8);
      digitErase("EIGHT");
    }
    while (s.find('T') != string::npos) { // 3
      res.push_back(3);
      digitErase("THREE");
    }
    while (s.find('N') != string::npos) { // 9
      res.push_back(9);
      digitErase("NINE");
    }
    sort(res.begin(), res.end());
    printf("Case #%d: ", t);
    for (auto i = 0; i < res.size(); i++)
      printf("%d", res[i]);
    printf("\n");
  }
  return 0;
}
