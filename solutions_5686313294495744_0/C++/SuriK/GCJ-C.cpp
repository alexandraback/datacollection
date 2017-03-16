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
#define VVB vector<vector<bool>> 
#define VVL vector<vector<LL>> 
#define VVD vector<vector<LD>> 
#define SZ(x) ((int)x.size())
#define epsilon 1e-06


using namespace std;

class Prob {

public:
  int solve(int N, VPS& vS)
  {

    set<string> first;
    set<string> second;

    FORI(i, 0, N) {
      first.insert(vS[i].first);
      second.insert(vS[i].second);
    }


    int min = 100;

    FORI(i, 1, 1 << N) {

      set<string> f;
      set<string> s;

      int len = 0;
      FORI(j, 0, N) {
        if (i & (1 << j)) {
          f.insert(vS[j].first);
          s.insert(vS[j].second);
          len++;
        }
      }
      if (f.size() == first.size() && s.size() == second.size())
      {
        min = std::min(min, len);
      }


    }




    return N - min;
  }
};

int main() {
  int t;
  cin >> t;
  FORI(i, 1, t + 1) {

    int N;
    cin >> N;

    VPS vS(N);
    FORI(j, 0, N) {
      cin >> vS[j].first >> vS[j].second;
    }

    Prob prob;
    cout << "Case #" << i << ": ";
    cout << prob.solve(N, vS);
    cout << endl;
  }

  return 0;
}



