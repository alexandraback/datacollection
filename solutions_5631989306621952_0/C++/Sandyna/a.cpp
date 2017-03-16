#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

int main () {
  long long t;
  cin >> t;
  string s;
  for (int i = 0; i < t; i++) {
    cin >> s;
    deque<char> letters;
    letters.push_front(s[0]);
    for (int j = 1; j < s.size(); j++) {
      if (s[j] >= letters.front()) {
	letters.push_front(s[j]);
      } else {
	letters.push_back(s[j]);
      }
    }
    cout << "Case #" << i+1 << ": ";
    while (!letters.empty()) {
      cout << letters.front();
      letters.pop_front();
    }
    cout << "\n";
  }
  return 0;
}