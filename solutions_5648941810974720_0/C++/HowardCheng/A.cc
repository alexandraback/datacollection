#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const string words[] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
  "NINE"};

map<vector<int>, string> memo;

string S;
int n;

bool cando(const vector<int> &freq, int d)
{
  int freq2[26] = {0};
  for (int i = 0; i < words[d].length(); i++) {
    freq2[words[d][i]-'A']++;
  }
  for (int i = 0; i < 26; i++) {
    if (freq[i] < freq2[i]) return false;
  }
  return true;
}

string f(const vector<int> &freq)
{
  if (memo.find(freq) != memo.end()) {
    return memo[freq];
  }
  if (count(freq.begin(), freq.end(), 0) == 26) {
    return memo[freq] = "";
  }
  for (int d = 1; d < 10; d++) {
    if (cando(freq, d)) {
      vector<int> freq2{freq};
      for (int i = 0; i < words[d].length(); i++) {
	freq2[words[d][i]-'A']--;
      }
      if (f(freq2) != "bad") {
	return memo[freq] = to_string(d) + f(freq2);
      }
    }
  }
  return memo[freq] = "bad";
}

void solve()
{
  cin >> S;
  n = S.length();

  vector<int> freq(26,0);
  for (int i = 0; i < n; i++) {
    freq[S[i]-'A']++;
  }

  // get rid of all the 0's, 6's
  string ans;

  for (int i = 0; i < freq[25]; i++) {
    ans += '0';
  }
  freq['E'-'A'] -= freq[25];
  freq['R'-'A'] -= freq[25];
  freq['O'-'A'] -= freq[25];
  freq[25] = 0;
  
  for (int i = 0; i < freq['X'-'A']; i++) {
    ans += '6';
  }
  freq['S'-'A'] -= freq['X'-'A'];
  freq['I'-'A'] -= freq['X'-'A'];
  freq['X'-'A'] -= freq['X'-'A'];


  ans += f(freq);
  sort(ans.begin(), ans.end());
  cout << ans << endl;
  
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
