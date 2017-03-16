#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

string calc(const string& s) {
  vector<char> v(s.size());
  v.reserve(1000);
  int nseen = 0;
  vector<bool> seen(10);
  auto see = [&](char c) {
    if (!seen[c]) {
      ++nseen;
      seen[c] = true;
    }
  };
  for (size_t i = 0; i < v.size(); ++i) {
    assert('0' <= s[i] && s[i] <= '9');
    char value = s[i]-'0';
    v[v.size()-i-1] = value;
    see(value);
  }
  if (nseen == 1 && seen[0]) { //only zeros
    return "INSOMNIA";
  }
  auto v0 = v;
  while (nseen < 10) {
    char overflow = 0;
    size_t i = 0;
    for (; i < v0.size(); ++i) {
      v[i] += v0[i]+overflow;
      if (v[i] >= 10) {
	v[i] %= 10;
	overflow = 1;
      } else {
	overflow = 0;
      }
      see(v[i]);
    }
    for (; i < v.size() && overflow; ++i) {
      v[i] += overflow;
      if (v[i] >= 10) {
	v[i] %= 10;
	overflow = 1;
      } else {
	overflow = 0;
      }
      see(v[i]);
    }
    if (overflow) {
      v.push_back(1);
      see(1);
    }
  }
  string res(v.size(), '0');
  for (size_t i = 0; i < v.size(); ++i) {
    res[i] = v[v.size()-i-1]+'0';
  }
  return res;
}

void test() {
  assert("INSOMNIA" == calc("0"));
  assert("10" == calc("1"));
  assert("90" == calc("2"));
  assert("110" == calc("11"));
  assert("5076" == calc("1692"));
}

int main(int argc, char** argv) {
  if (argc == 2) {
    if (string(argv[1]) == "-test") {
      test();
      return 0;
    } else if (string(argv[1]) == "-perf") {
      for (size_t i = 0; i <= 1000000; ++i) {
	ostringstream osm;
	osm << i;
	string res = calc(osm.str());
	cout << osm.str() << ' ' << res << endl;
      }
      return 0;
    }
  }
  size_t N;
  cin >> N;
  for (size_t i = 1; i <= N; ++i) {
    string s;
    cin >> s;
    string res = calc(s);
    cout << "Case #" << i << ": " << res << endl;
  }
}
