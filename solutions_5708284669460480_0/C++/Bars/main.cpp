#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <memory>
#include <functional>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>
#include <sstream>
#include <set>
#include <map>

using namespace std;

vector<int> MaxBorderArray(const char *s)
{
  int i, j, n = strlen(s);
  vector<int> p(n,0);
  p[0] = 0;
  for(i = 1; i < n; i++)
  {
    j = p[i - 1];
    while ((j > 0) && (s[i] != s[j])) j = p[j - 1];
    if (s[i] == s[j]) p[i] = j + 1; else p[i] = 0;
  }
  return p;
}


int kmp(string word, string text)
{
  int i, j, counter;
  vector<int> p = MaxBorderArray(word.c_str());
  for(i = j = 0; i < text.size(); i++)
  {
    while(j && (text[i] != word[j])) j = p[j - 1];
    if (j + 1 == word.size())
    {
      counter++;
      if (j) j = p[j - 1];
    }
    if (text[i] == word[j]) j++;
  }

  return counter;
}


int main()
{
    ifstream in ("in.in");
    ofstream out ("out.txt");

    int T;

    in >> T;

    for (int t = 1; t <= T; ++t)
    {
        out << "Case #" << t << ": ";

        int k, l, s;
        char c;
        string pattern;
        map<char, int> keys;

        in >> k >> l >> s;

        for (int i = 0; i < k; ++i)
        {
            in >> c;
            ++keys[c];
        }

        in >> pattern;

        double p = keys[pattern[0]] / (double) k;

        for (int i = 1; i < pattern.length(); ++i)
        {
            double pt = keys[pattern[i]] / (double) k;
            p *= pt;
        }

        cout << p << endl;

        if (p == 0)
        {
            out << 0.0 << endl;
            continue;
        }

        string word = "";

        int i;
        for (i = 0; i < s / l; ++i)
            word += pattern;

        int q = 0;
        i*= l;
        for (; i < s; ++i)
            word += pattern[q++];

        int counter = kmp(pattern, word);

        cout << counter << endl;

        double perfect = counter;

        p *= counter;

        out << (double) (perfect - p) << endl;
    }

    in.close();
    out.close();
    return 0;
}
