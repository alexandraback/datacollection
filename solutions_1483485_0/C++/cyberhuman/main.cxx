#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

const string GOOGLISH =
  "ejp mysljylc kd kxveddknmc re jsicpdrysi"
  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
  "de kr kd eoya kw aej tysr re ujdr lkgc jv"
  "y qee z";

const string ENGLISH =
  "our language is impossible to understand"
  "there are twenty six factorial possibilities"
  "so it is okay if you want to just give up"
  "a zoo q";

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  ifstream in(argv[1]);

  map<char, char> translator;
  const int length = GOOGLISH.length();
  for (int i = 0; i < length; ++i)
    translator[GOOGLISH[i]] = ENGLISH[i];

  int t;
  string g;
  in >> t;
  getline(in, g);
  for (int i = 0; i < t; ++i)
  {
    getline(in, g);
    for (char &c : g)
      c = translator[c];
    cout << "Case #" << 1 + i << ": " << g << endl;
  }
  return 0;
}
