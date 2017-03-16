#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string digit[10] =
    {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
     "NINE"};
int maxpos[10] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};

bool FindDigit(string& str, int now) {
  int pos = 0;
  bool find = false;
  for (int mi = 0; mi < maxpos[now]; ++mi) {
    bool lf = false;
    for (int i = 0; i < str.size(); ++i) {
      if (str[i] == digit[now][pos]) {
        ++pos;
        lf = true;
      }
    }

    if (!lf) break;
    if (pos == maxpos[now]) {
      find = true;
      break;
    }
  }

  pos = 0;
  if (find) {
    for (int mi = 0; mi < maxpos[now]; ++mi) {
      for (int i = 0; i < str.size(); ++i) {
        if (str[i] == digit[now][pos]) {
          str[i] = '.';
          ++pos;
        }
      }

      if (pos == maxpos[now]) break;
    }
  }

  return find;
}



int main() {
  int t;
  cin >> t;
  for (int ci = 1; ci <= t; ++ci) {
    string str;
    cin >> str;

    vector<int> res;
    vector<pair<char, int> > block;
    block.push_back(make_pair('Z', 0));
    block.push_back(make_pair('W', 2));
    block.push_back(make_pair('U', 4));
    block.push_back(make_pair('X', 6));
    block.push_back(make_pair('G', 8));
    for (int i = 0; i < block.size(); ++i) {
      char c = block[i].first;
      int now = block[i].second;
      while (find(str.begin(), str.end(), c) != str.end()) {
        FindDigit(str, now);
        res.push_back(now);
      }
    }

    block.clear();
    block.push_back(make_pair('H', 3));
    block.push_back(make_pair('F', 5));
    block.push_back(make_pair('I', 9));
    for (int i = 0; i < block.size(); ++i) {
      char c = block[i].first;
      int now = block[i].second;
      while (find(str.begin(), str.end(), c) != str.end()) {
        FindDigit(str, now);
        res.push_back(now);
      }
    }

    block.clear();
    block.push_back(make_pair('O', 1));
    block.push_back(make_pair('V', 7));
    for (int i = 0; i < block.size(); ++i) {
      char c = block[i].first;
      int now = block[i].second;
      while (find(str.begin(), str.end(), c) != str.end()) {
        FindDigit(str, now);
        res.push_back(now);
      }
    }

    sort(res.begin(), res.end());
    cout << "Case #" << ci << ": ";
    for (int i = 0; i < res.size(); ++i) {
      cout << res[i];
    }
    cout << endl;
  }

  return 0;
}
