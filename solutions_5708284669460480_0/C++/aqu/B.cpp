#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int count(string src, char c) {
  int res = 0;
  for (char e : src)
    res += e == c;
  return res;
}

int countoverlap(string tmp, string target, int S) {
  int result = 0;
  for (int i = 0; i <= S-target.size(); ++i) {
    result += tmp.substr(i, target.size()) == target; 
  }
  return result;
}

double doit() {
  int K, L, S;
  cin >> K >> L >> S;
  string letters, target;
  cin >> letters >> target;
  
  for (int c : target)
    if (letters.find(c) == string::npos)
      return 0;

  string tmp = target;
  while (tmp.size() < S) tmp += target;
  tmp = tmp.substr(0, S);

  double corrprob = 1;
  for (int i = 0; i < target.size(); ++i) {
    corrprob *= 1.0*count(letters, target[i])/letters.size();
  }
  
  return countoverlap(tmp, target, S)*(1-corrprob);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
    printf("Case #%d: %lf\n", t, doit());
}
