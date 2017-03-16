#include <iostream>
#include <vector>
#include <string>

using namespace std;

int consume(string num, char key, vector<int>& chCount) {
  int target = key - 'A';
  int ret = chCount[target];
  for (int i = 0; i < num.size(); i++) {
    int index = num[i] - 'A';
    chCount[index] -= ret;
  }
  return ret;
}

int main() {

  vector< vector<int> > numberCount(10, vector<int>(26, 0));
  vector<string> numStrings = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

  for (int i = 0; i < numStrings.size(); i++) {
    for (int j = 0; j < numStrings[i].size(); j ++) {
      int index = numStrings[i][j] - 'A';
      numberCount[i][index]++;
    }
  }

  
  int t; cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    string input; cin >> input;
    vector<int> chCount(26, 0);
    for (int i = 0; i < input.size(); i++) {
      int index = input[i] - 'A';
      chCount[index]++;
    }

    vector<int> ans(10, 0);
    ans[0] += consume("ZERO", 'Z', chCount);
    ans[6] += consume("SIX", 'X', chCount);
    ans[2] += consume("TWO", 'W', chCount);
    ans[4] += consume("FOUR", 'U', chCount);
    ans[8] += consume("EIGHT", 'G', chCount);
    ans[7] += consume("SEVEN", 'S', chCount);
    ans[3] += consume("THREE", 'H', chCount);
    ans[5] += consume("FIVE", 'V', chCount);
    ans[1] += consume("ONE", 'O', chCount);
    ans[9] += consume("NINE", 'E', chCount);
    string ansStr = "";
    for (int i = 0; i < ans.size(); i++) {
      ansStr += string(ans[i], i + '0');
    }
    cout << "Case #" << tc << ": " << ansStr << endl;
  }
  return 0;
}
