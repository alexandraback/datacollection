#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iterator>
#include <set>
#include <stack>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>


#define LL long long
#define LD long double
#define PI pair<int,int>
#define PL pair<LL,LL>
#define pb push_back
#define mp make_pair
#define FORI(i,k,n) for (int i = (k); i < (n); i++)
#define RFORI(i,k,n) for (int i = (k); i > (n); i--)
#define FORL(i,k,n) for (LL i = (k); i < (n); i++)
#define RFORL(i,k,n) for (LL i = (k); i > (n); i--)
#define VI vector<int>
#define VPI vector<PI>
#define VPL vector<PL>
#define VB vector<bool>
#define VD vector<LD>
#define VL vector<LL>
#define VS vector<string>
#define VVI vector<vector<int>> 
#define VVB vector<vector<bool>> 
#define VVL vector<vector<LL>> 
#define VVD vector<vector<LD>> 
#define SZ(x) ((int)x.size())
#define epsilon 1e-06


using namespace std;

class Prob {

public:
  int solve(string C, string J)
  {

    VI vC;
    VI vJ;

    vC.push_back(0);
    FORI(i, 0, SZ(C)) {
      VI newvC;

      if (C[i] == '?')
      {
        FORI(j, 0, 10) {
          FORI(k, 0, SZ(vC)) {
            newvC.push_back(vC[k] + j * (int)pow (10, SZ(C) - i - 1));
          }
        }
      }
      else {
        FORI(k, 0, SZ(vC)) {
          newvC.push_back(vC[k] += (C[i] - '0') * (int)pow(10, SZ(C) - i - 1));
        }
      }

      vC = newvC;

    }

    vJ.push_back(0);
    FORI(i, 0, SZ(J)) {
      VI newvJ;

      if (J[i] == '?')
      {
        FORI(j, 0, 10) {
          FORI(k, 0, SZ(vJ)) {
            newvJ.push_back(vJ[k] + j * (int)pow(10, SZ(J) - i - 1));
          }
        }
      }
      else {
        FORI(k, 0, SZ(vJ)) {
          newvJ.push_back(vJ[k] + (J[i] - '0') * (int)pow(10, SZ(J) - i - 1));
        }
      }
      vJ = newvJ;

    }

    int minC = 1000;
    int minJ = 1000;
    int minDiff = 1000;

    FORI(i, 0, SZ(vC)) {
      FORI(j, 0, SZ(vJ)) {
        if (abs(vJ[j] - vC[i]) <= minDiff) {
          if ((abs(vJ[j] - vC[i]) == minDiff)) {
            if (vC[i] <= minC) {
              if (vC[i] == minC) {
                if (vJ[j] < minJ) {
                  minC = vC[i];
                  minJ = vJ[j];
                }
              }
              else {
                minC = vC[i];
                minJ = vJ[j];
              }

            }
          }
          else {
            minDiff = abs(vJ[j] - vC[i]);
            minC = vC[i];
            minJ = vJ[j];
          }
        }

      }
    }

    string c = to_string(minC);
    string j = to_string(minJ);

    while (SZ(c) < SZ(C)) {
      c = "0" + c;
    }

    while (SZ(j) < SZ(J)) {
      j = "0" + j;
    }

    cout << c << " " << j;

    return 0;
  }
};

int main() {
  int t;
  cin >> t;
  FORI(i, 1, t + 1) {

    string C, J;
    cin >> C >> J;


    Prob prob;
    cout << "Case #" << i << ": ";
    prob.solve(C, J);
    cout << endl;
  }

  return 0;
}



