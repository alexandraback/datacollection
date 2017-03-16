#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  size_t N;
  cin >> N;
  for (size_t k = 1; k <= N; ++k) {
    string s;
    cin >> s;
    deque<char> d;
    d.push_back(s.front());
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i] >= d.front()) {
	d.push_front(s[i]);
      } else {
	d.push_back(s[i]);
      }
    }
    cout << "Case #" << k << ": ";
    for (char c : d) {
      cout << c;
    }
    cout << endl;
  }
}
