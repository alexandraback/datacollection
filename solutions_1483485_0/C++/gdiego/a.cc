#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string translate(string text, const string &mapping) {
  for (int x = 0; x < text.size(); x++) {
    text[x] = (text[x] < 97 || text[x] > 122) ? text[x] : mapping[text[x] - 97];
  }
  return text;
}
string computeMap(string *a, string *b, int c) {
  string ret = "", used = "";
  for (int x = 0; x < 26; x++)
    ret += " ";
  used = ret;

  for (int x = 0; x < c; x++) {
    for (int y = 0; y < a[c].size(); y++) {
      if (a[x][y] < 97 || a[x][y] > 122)
        continue;
      ret[a[x][y] - 97] = b[x][y];
      used[b[x][y] - 97] = '-';
    }
  }

  int missed = 0;
  for (int x = 0; x < used.size(); x++) {
    if (used[x] == ' ') {
      missed = x + 97;
      break;
    }
  }

  for (int x = 0; x < ret.size(); x++) {
    if (ret[x] == ' ') {
      if (!missed)
        throw 0;
      ret[x] = missed, missed = 0;
    }
  }

  return ret;
}
void chomp(string &x) {
  while (x.size() && (x[x.size() - 1] == 13 || x[x.size() - 1] == 10)) {
    x = x.substr(0, x.size() - 1);
  }
}
int main() {
  string tmp;
  int cases = 0;
  string input[]= {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv", "az"};
  string output[]={"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up", "yq"};
  string mapping = computeMap(input, output, 4);
  cin >> cases; getline(cin, tmp);
  for (int x = 1; x <= cases; x++) {
    getline(cin, tmp); chomp(tmp);
    cout << "Case #" << x << ": " << translate(tmp, mapping) <<endl;
  }
  return 0;
}

