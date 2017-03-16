#include <bits/stdc++.h>
using namespace std;
const string LETTER = "ZWUFXSORGI";
const int DIGIT[] = {0, 2, 4, 5, 6, 7, 1, 3, 8, 9};
const string SPELLING[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cerr << "Running test " << iTest << "..." << endl;
    int cnt[256] = {0}, ans[10] = {0};
    string s;
    cin >> s;
    for (auto c : s)
      cnt[c]++;
    for (int i = 0; i < 10; i++)
    {
      ans[DIGIT[i]] = cnt[LETTER[i]];
      for (auto c : SPELLING[DIGIT[i]])
        cnt[c] -= ans[DIGIT[i]];
    }

    cout << "Case #" << iTest << ": ";
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < ans[i]; j++)
        cout << i;
    cout << endl;
  }
}