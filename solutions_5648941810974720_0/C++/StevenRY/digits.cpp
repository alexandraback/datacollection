#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int main ()
  {
    unsigned T;
    cin >> T;
    for (unsigned t = 1; t <= T; ++t)
      {
        string str;
        cin >> str;
        vector<int> counts;
        for (unsigned i = 0; i < 26; ++i) counts.push_back(0);
        for (unsigned i = 0; i < str.size(); ++i)
          {
            counts[str[i]-'A']++;
          }
        vector<int> res;
        for (unsigned i = 0; i < 10; ++i) res.push_back(0);
        while (counts['Z'-'A'] > 0)
          {
            res[0]++;
            counts['Z'-'A']--;
            counts['E'-'A']--;
            counts['R'-'A']--;
            counts['O'-'A']--;
          }
        while (counts['W'-'A'] > 0)
          {
            res[2]++;
            counts['T'-'A']--;
            counts['W'-'A']--;
            counts['O'-'A']--;
          }
        while (counts['X'-'A'] > 0)
          {
            res[6]++;
            counts['S'-'A']--;
            counts['I'-'A']--;
            counts['X'-'A']--;
          }
        while (counts['U'-'A'] > 0)
          {
            res[4]++;
            counts['F'-'A']--;
            counts['O'-'A']--;
            counts['U'-'A']--;
            counts['R'-'A']--;
          }
         while (counts['F'-'A'] > 0)
          {
            res[5]++;
            counts['F'-'A']--;
            counts['I'-'A']--;
            counts['V'-'A']--;
            counts['E'-'A']--;
          }
         while (counts['O'-'A'] > 0)
          {
            res[1]++;
            counts['O'-'A']--;
            counts['N'-'A']--;
            counts['E'-'A']--;
          }
         while (counts['R'-'A'] > 0)
          {
            res[3]++;
            counts['T'-'A']--;
            counts['H'-'A']--;
            counts['R'-'A']--;
            counts['E'-'A']--;
            counts['E'-'A']--;
          }
         while (counts['S'-'A'] > 0)
          {
            res[7]++;
            counts['S'-'A']--;
            counts['E'-'A']--;
            counts['V'-'A']--;
            counts['E'-'A']--;
            counts['N'-'A']--;
          }
         while (counts['T'-'A'] > 0)
          {
            res[8]++;
            counts['E'-'A']--;
            counts['I'-'A']--;
            counts['G'-'A']--;
            counts['H'-'A']--;
            counts['T'-'A']--;
          }
         while (counts['N'-'A'] > 0)
          {
            res[9]++;
            counts['N'-'A']--;
            counts['I'-'A']--;
            counts['N'-'A']--;
            counts['E'-'A']--;
          }
        cout << "Case #" << t << ": ";
        for (unsigned i = 0; i < 10; ++i)
          {
            for (unsigned j = 0; j < res[i]; ++j) cout << i;
          }
        cout << "\n";
      }
    return 0;
  }
