#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string make_odd(const string& s) {
  string b = s.substr(1);
  reverse(b.begin(), b.end());
  return b + s;
}

string make_even(const string& s) {
  string b = s;
  reverse(b.begin(), b.end());
  return b + s;
}

bool cmp(const string& a, const string& b) {
  if (a.size() < b.size()) return true;
  if (a.size() > b.size()) return false;
  return a < b;
}

string sq(const string& a) {
  string b(a.size() * 2 - 1, '0');
  for (size_t i = 0; i < a.size(); ++i)
    for (size_t j = 0; j < a.size(); ++j)
      b[i + j] += (a[i] - '0') * (a[j] - '0');

  return b;
}

int main() {
  vector<string> p;
  p.push_back("1");
  p.push_back("2");
  p.push_back("3");
  for (int i = 2; i <= 50; ++i) {
    int x = i / 2 - 1;
    for (int k = 0; k <= min(3, x); ++k) {
      string s(x - k, '0');
      s += string(k, '1');
      
      do {
	if (i % 2) {
	  p.push_back(make_odd("0" + s + "1"));
	  p.push_back(make_odd("1" + s + "1"));
	  if (k == 0) {
	    p.push_back(make_odd("0" + s + "2"));
	    p.push_back(make_odd("1" + s + "2"));
	  }
	  if (k <= 1) p.push_back(make_odd("2" + s + "1"));
	} else {
	  p.push_back(make_even(s + "1"));
	  if (k == 0) p.push_back(make_even(s + "2"));
	}
      } while (next_permutation(s.begin(), s.end()));
    }
  }

  sort(p.begin(), p.end(), cmp);
  vector<string> q;
  for (auto s : p)
    q.push_back(sq(s));

  int n, C = 1;
  cin >> n;
  string a, b;
  while (n-- && cin >> a >> b) {
    while (a[0] == '0') a = a.substr(1);
    while (b[0] == '0') b = b.substr(1);
    auto it_a = lower_bound(q.begin(), q.end(), a, cmp);
    auto it_b = upper_bound(q.begin(), q.end(), b, cmp);
    cout << "Case #" << C++ << ": " << it_b - it_a << endl;
  }
}
