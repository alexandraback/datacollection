#include <bits/stdc++.h>
using namespace std;

const string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };


string ret;
void f(string& S, int idx, int cc)
{
  for(int i = 0; i < cc; i++) ret += (char)('0' + idx);
  for(int i = 0; i < num[idx].size(); i++) {
    string T = "";
    int curr = cc;
    for(int j = 0; j < S.size(); j++) {
      if(curr > 0 && num[idx][i] == S[j]) --curr;
      else T += S[j];
    }
    S = T;
  }
}

void Solve()
{
  string S;
  cin >> S;

  ret = "";
  f(S, 0, count(S.begin(), S.end(), 'Z'));
  f(S, 2, count(S.begin(), S.end(), 'W'));
  f(S, 4, count(S.begin(), S.end(), 'U'));
  f(S, 6, count(S.begin(), S.end(), 'X'));
  f(S, 1, count(S.begin(), S.end(), 'O'));
  f(S, 3, count(S.begin(), S.end(), 'R'));
  f(S, 5, count(S.begin(), S.end(), 'F'));
  f(S, 7, count(S.begin(), S.end(), 'S'));
  f(S, 8, count(S.begin(), S.end(), 'T'));
  f(S, 9, count(S.begin(), S.end(), 'I'));
  sort(ret.begin(), ret.end());
  cout << ret << endl;
}
int main()
{
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    Solve();
  }
}
