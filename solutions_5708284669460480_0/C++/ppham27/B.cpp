#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int findBananasNeeded(string target, int L, int S) {
  int tailLength = 0;
  for (int i = 1; i < L; ++i) {
    if (target.substr(L-i, i) == target.substr(0, i)) {
      tailLength = i;
    }
  }
  return 1 + (S - L)/(L - tailLength);
}

double calculateExpectedBananas(int K, int L, int S,
                                string keyboard, string target) {
  // check if its possible to type
  map<char, int> keyCnt;
  for (char c : keyboard) { 
    if (keyCnt.count(c)) {
      ++keyCnt[c];
    } else { 
      keyCnt[c] = 1;
    }
  }
  for (char c : target) if (!keyCnt.count(c)) return 0;
  // now we know it's possible
  int bananasNeeded = findBananasNeeded(target, L, S);
  // brute force
  vector<string> possibleStrings; possibleStrings.push_back("");
  for (int s = 0; s < S; ++s) {
    vector<string> newStrings;
    for (int k = 0; k < K; ++k) {
      for (string oldString : possibleStrings) {
        oldString += keyboard[k];
        newStrings.push_back(oldString);
      }
    }
    possibleStrings = newStrings;
  }
  double expectedBananas = 0;
  for (string s : possibleStrings) { 
    int currentIdx = 0;
    int bananas = 0;
    while ((currentIdx = s.find(target, currentIdx)) != -1) {
      ++expectedBananas; ++currentIdx;
      ++bananas;
    }
  }
  return bananasNeeded - expectedBananas/possibleStrings.size();
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int K, L, S;
    string keyboard, target;
    cin >> K >> L >> S >> keyboard >> target;
    cout << "Case #" << i + 1 << ": "
         << calculateExpectedBananas(K, L, S, keyboard, target)
         << endl;
  }
  return 0;
}
