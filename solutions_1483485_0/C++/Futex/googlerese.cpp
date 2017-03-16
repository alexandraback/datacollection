#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
using namespace std;

char mapping[26];

int main(int argc, char** argv) {

  for (int idx = 0; idx < 26; ++idx) {
    mapping[idx] = '?';
  }

  const string train =
      "ejp mysljylc kd kxveddknmc re jsicpdrysi"
      "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
      "de kr kd eoya kw aej tysr re ujdr lkgc jv";

  const string answer =
      "our language is impossible to understand"
      "there are twenty six factorial possibilities"
      "so it is okay if you want to just give up";

  assert(train.size() == answer.size());

  for (int idx = 0; idx < train.size(); ++idx) {
    if (train[idx] == ' ') {
      assert(answer[idx] == ' ');
      continue;
    }
    assert(train[idx] >= 'a');
    assert(train[idx] <= 'z');

    mapping[train[idx] - 'a'] = (answer[idx] - 'a');
  }

  mapping['q' - 'a'] = 'z' - 'a';
  mapping['z' - 'a'] = 'q' - 'a';

  int cases = 0;
  cin >> cases;
  string blah;
  getline(cin, blah);
  assert(blah.empty());
  for (int idx = 0; idx < cases; ++idx) {
    cout << "Case #" << (idx + 1) << ": ";

    string line;
    getline(cin, line);
    stringstream sin(line);
    while (true) {
      string str;
      sin >> str;
      if (!sin) {
        break;
      }
      for (int s = 0; s < str.size(); ++s) {
        cout << char(mapping[str[s] - 'a'] + 'a');
      }
      cout << ' ';
    }

    cout << endl;
  }

  return 0;
}
