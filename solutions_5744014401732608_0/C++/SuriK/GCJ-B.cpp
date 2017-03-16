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
  int solve(int B, LL M)
  {

    int N = B - 2;
    LL max = 1;

    while (N) {
      max = max * 2;
      N--;
    }

    if (M > max)
    {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }

    cout << "POSSIBLE" << endl;

    VVB G(B, VB(B, false));

    FORI(i, 1, B-1) {
      FORI(j, i + 1, B) {
        G[i][j] = true;
      }
    }


    if (M == max) {
      FORI(i, 1, B) {
        G[0][i] = true;
      }
    }
    else {

      FORI(i, 0, B-2) {

        if (M & (1LL << i)) {
          G[0][B - i-2] = true;
        }

      }


    }

    FORI(i, 0, B) {
      FORI(j, 0, B) {
        if (G[i][j]) cout << "1";
        else cout << "0";
      }
      cout << endl;
    }








    return 0;
  }
};

int main() {
  int t;
  cin >> t;
  FORI(i, 1, t + 1) {

    int B;
    LL M;
    cin >>B >> M;

    Prob prob;
    cout << "Case #" << i << ": ";
    prob.solve(B, M);
  }

  return 0;
}



