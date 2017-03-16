#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

map<char, int> counts;
vector<string> numbers = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

void sub(int ind, int count)
{
    for (char c : numbers[ind])
      counts[c] -= count;
}

int main(void)
{
  int T;
  cin >> T;
  cin.ignore();
  for (int CN = 1; CN <= T; ++CN)
  {
    counts.clear();
    string s;
    getline(cin, s);


    for (char c : s)
      ++counts[c];


    map<int, int> out;
    out[0] = counts['Z'];
    sub(0, out[0]);

    out[2] = counts['W'];
    sub(2, out[2]);

    out[6] = counts['X'];
    sub(6, out[6]);

    out[8] = counts['G'];
    sub(8, out[8]);

    out[4] = counts['U'];
    sub(4, out[4]);

    out[5] = counts['F']; // depends on 4
    sub(5, out[5]);

    out[7] = counts['V']; // depends on 4
    sub(7, out[7]);

    out[3] = counts['H']; // depends on 8
    sub(3, out[3]);

    out[1] = counts['O']; // depends on stuff
    sub(1, out[1]);

    out[9] = counts['I'];
    sub(9, out[9]);

    cout << "Case #" << CN << ": ";

    for (int i = 0; i < 10; ++i)
      cout << string(out[i], '0' + i);

    cout << endl;
  }
}
