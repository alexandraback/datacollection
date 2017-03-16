#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;

int K, L, S;
string keyboard, word;

bool can_place(vector<char> &ans, int pos) {
  if (pos + L > S) {
    return false;
  }
  for(int i = 0; i < L; i++) {
    if (ans[pos + i] != word[i] && ans[pos+i] != '0') {
      return false;
    }
  }
  return true;
}

bool good(vector<char> &ans, int pos) {
  if (pos + L > S) {
    return false;
  }
  for(int i = 0; i < L; i++) {
    if (ans[pos + i] != word[i]) {
      return false;
    }
  }
  return true;
}

int count_num(vector<int> &v) {
  vector<char> ans(S);
  for (int i = 0; i < S; i++) {
    ans[i] = keyboard[v[i]];
  }
  int n = 0;
  for (int i = 0; i < S; i++) {
    if (good(ans, i)) {
      n++;
    }
  }
  return n;
}


int main() {
  srand(time(NULL));
  int T;
  cin >> T;

  for(int tt = 1; tt <= T; tt++) {
    cin >> K >> L >> S;
    cin >> keyboard;
    cin >> word;

    int num_b_max = 0;
    vector<char> ans(S);
    for (int i = 0; i < S; i++) {
      ans[i] = '0';
    }
    for (int i = 0; i < S; i++) {
      if (can_place(ans,i)) {
        num_b_max++;
        for (int j = 0; j < L; j++) {
          ans[i+j] = word[j];
        }
      }
    }

    int num_found = 0;
    int num_total = 0;
    vector<int> v(S);
    for(int i = 0; i < S; i++) {
      v[i] = 0;
    }
    while(1) {
      // count
      num_found += count_num(v);
      num_total ++;
      // update
      bool done = true;
      for (int i = 0; i < S; i++) {
        if(v[i] < K-1) {
          v[i]++;
          done = false;
          break;
        } else {
          v[i] = 0;
        }
      }
      if (done)
        break;
    }

    long double final_ans = ((long double)num_found) / ((long double) num_total);
    final_ans = ((long double)num_b_max) - final_ans;

    // corner case
    set<char> all_chars;
    for (int i = 0; i < K; i++) {
      all_chars.insert(keyboard[i]);
    }
    for (int i = 0; i < L; i++) {
      if (all_chars.find(word[i]) == all_chars.end()) {
        final_ans = 0.0;
      }
    }
    
    cout << fixed;
    cout << setprecision(7);
    cout << "Case #" << tt << ": " << final_ans << endl;

  }

  return 0;
}

int r_solve() {



}

