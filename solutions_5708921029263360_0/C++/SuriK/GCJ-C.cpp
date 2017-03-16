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
#include <cassert>


#define LL long long
#define LD long double
#define PI pair<int,int>
#define PS pair<string, string>
#define PL pair<LL,LL>
#define pb push_back
#define mp make_pair
#define FORI(i,k,n) for (int i = (k); i < (n); i++)
#define RFORI(i,k,n) for (int i = (k); i > (n); i--)
#define FORL(i,k,n) for (LL i = (k); i < (n); i++)
#define RFORL(i,k,n) for (LL i = (k); i > (n); i--)
#define VI vector<int>
#define VPI vector<PI>
#define VPS vector<PS>
#define VPL vector<PL>
#define VB vector<bool>
#define VD vector<LD>
#define VL vector<LL>
#define VS vector<string>
#define VVI vector<vector<int>> 
#define VVVI vector<vector<vector<int>>> 
#define VVB vector<vector<bool>> 
#define VVVB vector<vector<vector<bool>>> 
#define VVL vector<vector<LL>> 
#define VVD vector<vector<LD>> 
#define SZ(x) ((int)x.size())
#define epsilon 1e-06


using namespace std;

class Prob {

public:
  int solve(int J, int P, int S, int K)
  {

    VI sol;

    FORI(i, 1, J+1) {
      FORI(j, 1, P + 1) {
        FORI(k, 1, S + 1) {
          sol.push_back(i * 100 + j * 10 + k);
        }
      }
    }


    VI maxans;

    int n = J*P*S;
    RFORI(i, (1 << n) - 1, 0) {
      VI ans;
      FORI(j, 0, n) {
        if (i & (1 << j)) {
          ans.push_back(sol[j]);
        }
      }

      if (K >= 3) {
        maxans = ans;
        break;
      }

      if (SZ(ans) <= SZ(maxans))
        continue;

      bool flag = true;
      FORI(k, 0, SZ(ans)) {
        int a = 1;
        int b = 1;
        int c = 1;
        FORI(l, 0, SZ(ans)) {
          if (k == l)
            continue;
          if (ans[k] / 100 == ans[l] / 100 && ans[k] % 10 == ans[l] % 10) {
            a++;
          }
          if (ans[k] / 100 == ans[l] / 100 && (ans[k] / 10) % 10 == (ans[l] / 10) % 10) {
            b++;
          }
          if ((ans[k] / 10) % 10 == (ans[l] / 10) % 10 && ans[k] % 10 == ans[l] % 10) {
            c++;
          }
        }

        if (a > K || b > K || c > K)
        {
          flag = false;
          break;
        }

      }

      if (!flag)
        continue;

      if (SZ(ans) > SZ(maxans)) {
        maxans = ans;
      }
    }

    cout << SZ(maxans) << endl;
    FORI(k, 0, SZ(maxans)) {
      cout << maxans[k] / 100 << " " << (maxans[k] / 10) % 10 << " " << maxans[k] % 10 << endl;
    }

    return 0;
  }
};

int main() {
  int t;
  cin >> t;
  FORI(i, 1, t + 1) {

    int J, P, S, K;
    cin >> J >> P>>S>>K;

    Prob prob;
    cout << "Case #" << i << ": ";
    prob.solve(J, P, S ,K);
  }

  return 0;
}



