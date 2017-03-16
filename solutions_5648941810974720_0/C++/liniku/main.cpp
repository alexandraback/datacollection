#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// ZERO (unique Z)
// ONE (unique O after 2, 4)
// TWO (unique W)
// THREE (unique R after 4)
// FOUR (unique F after 5)
// FIVE (unique V after 7)
// SIX (unique X)
// SEVEN (unique S after 6)
// EIGHT (unique G)
// NINE (last)
string solve(const string &in) {
  map<char, int> m;
  vector<int> v;
  v.resize(10);

  for (int i = 0; i < in.length(); ++i) {
    ++m[in[i]];
  }

  v[0] = m['Z'];
  m['Z'] -= v[0];
  m['E'] -= v[0];
  m['R'] -= v[0];
  m['O'] -= v[0];

  v[2] = m['W'];
  m['T'] -= v[2];
  m['W'] -= v[2];
  m['O'] -= v[2];

  v[6] = m['X'];
  m['S'] -= v[6];
  m['I'] -= v[6];
  m['X'] -= v[6];

  v[8] = m['G'];
  m['E'] -= v[8];
  m['I'] -= v[8];
  m['G'] -= v[8];
  m['H'] -= v[8];
  m['T'] -= v[8];

  v[7] = m['S'];
  m['S'] -= v[7];
  m['E'] -= v[7] * 2;
  m['V'] -= v[7];
  m['N'] -= v[7];

  v[5] = m['V'];
  m['F'] -= v[5];
  m['I'] -= v[5];
  m['V'] -= v[5];
  m['E'] -= v[5];

  v[4] = m['F'];
  m['F'] -= v[4];
  m['O'] -= v[4];
  m['U'] -= v[4];
  m['R'] -= v[4];

  v[3] = m['R'];
  m['T'] -= v[3];
  m['H'] -= v[3];
  m['R'] -= v[3];
  m['E'] -= v[3] * 2;

  v[1] = m['O'];
  m['O'] -= v[1];
  m['N'] -= v[1];
  m['E'] -= v[1];

  v[9] = m['I'];
  m['N'] -= v[9] * 2;
  m['I'] -= v[9];
  m['E'] -= v[9];

  for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
    if (it->second) {
      cerr << "???" << endl;
    }
  }

  string out = "";
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < v[i]; ++j) {
      out += (char)('0' + i);
    }
  }
  return out;
}

int main() {
  int T;
  string input, output;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> input;
    output = solve(input);
    cout << "Case #" << i + 1 << ": " << output << endl;
  }
  return 0;
}
