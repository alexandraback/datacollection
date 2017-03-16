#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int diff (string C, string J)
  {
    int res = 0;
    for (unsigned i = 0; i < C.size(); ++i)
      {
        res *= 10;
        res += C[i] - J[i];
      }
    return res > 0 ? res : -1*res;
  }

pair<string, string> getbest (string C, string J, unsigned c, unsigned j)
  {
    if (c != C.size())
      {
        if (C[c] != '?') return getbest(C, J, c+1, j);
        else
          {
            pair<string, string> bestpair;
            int best = 999999;
            for (char ch = '0'; ch <= '9'; ++ch)
              {
                C[c] = ch;
                pair<string, string> p = getbest(C, J, c+1, j);
                if (diff(p.first, p.second) < best)
                  {
                    bestpair = p;
                    best = diff(p.first, p.second);
                  }
              }
            return bestpair;
          }
      }
     else if (j != J.size())
      {
        if (J[j] != '?') return getbest(C, J, c, j+1);
        else
          {
            pair<string, string> bestpair;
            int best = 999999;
            for (char ch = '0'; ch <= '9'; ++ch)
              {
                J[j] = ch;
                pair<string, string> p = getbest(C, J, c, j+1);
                if (diff(p.first, p.second) < best)
                  {
                    bestpair = p;
                    best = diff(p.first, p.second);
                  }
              }
            return bestpair;
          }
      }
    else
      {
        pair<string, string> p;
        p.first = C;
        p.second = J;
        return p;
      }
  }
        
int main ()
  {
    unsigned T;
    cin >> T;
    for (unsigned t = 1; t <= T; ++t)
      {
        string C, J;
        cin >> C >> J;
        pair<string, string> p;
        p = getbest (C, J, 0, 0);
        cout << "Case #" << t << ": " << p.first << " " << p.second << "\n";
      }
    return 0;
  }
