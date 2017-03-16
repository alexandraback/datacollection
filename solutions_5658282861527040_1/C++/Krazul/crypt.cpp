#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long L;

string standardize(L x) {
  string answer;
  while (x) {
    if (x % 2 == 1) {
      answer = string("1").append(answer);
    } else {
      answer = string("0").append(answer);
    }
    x /= 2;
  }
  while (answer.size() < 32) {
    answer = string("0").append(answer);
  }
  return answer;
}

void supersplit(string& s, vector<string>& result) {
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      string cpy = s;
      cpy[i] = '0';
      for (int j = i+1; j < s.size(); ++j) cpy[j] = 'X';
      result.push_back(cpy);
    }
  }
}

L ways(string a, string b, string k) {
  L answer = 1;
  for (int i = 0; i < 32; ++i) {
    if (a[i] == '0' || b[i] == '0') { // answer must be 0
      if (k[i] == '0' || k[i] == 'X') {
        if (a[i] == 'X' || b[i] == 'X') answer *= 2;
      } else {
        answer = 0;
      }
    }
    if (a[i] == '1' && b[i] == '1') { // answer must be 1
      if (k[i] == '1' || k[i] == 'X') {
      } else {
        answer = 0;
      }
    }
    if (a[i] == 'X' && b[i] == '1') { // choices: 0,1
      if (k[i] == 'X') {
        answer *= 2;
      }
    }
    if (a[i] == '1' && b[i] == 'X') { // choices: 0,1
      if (k[i] == 'X') {
        answer *= 2;
      }
    }
    if (a[i] == 'X' && b[i] == 'X') { // choices: 0, 0, 0, 1
      int multiplier = 0;
      switch(k[i]) {
        case '0': multiplier = 3; break;
        case '1': multiplier = 1; break;
        case 'X': multiplier = 4; break;
      }
      answer *= multiplier;
    }
  }
  return answer;
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    L aa, bb, kk; cin >> aa >> bb >> kk;
    string as = standardize(aa), bs = standardize(bb), ks = standardize(kk);
    vector<string> av, bv, kv;
    supersplit(as, av);
    supersplit(bs, bv);
    supersplit(ks, kv);
    L wins = 0;
    for (int i = 0; i < av.size(); ++i) {
      for (int j = 0; j < bv.size(); ++j) {
        for (int ii = 0; ii < kv.size(); ++ii) {
          wins += ways(av[i], bv[j], kv[ii]);
        }
      }
    }

    cout << "Case #" << test << ": " << wins << endl;
  }
  return 0;
}