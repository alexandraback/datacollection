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
  int solve(string& S)
  {

    VI number(10, 0);

    FORI(i, 0, SZ(S)) {
      number[0] = std::count(S.begin(), S.end(), 'Z');
    }

    FORI(i, 0, SZ(S)) {
      number[6] = std::count(S.begin(), S.end(), 'X');
    }

    FORI(i, 0, SZ(S)) {
      number[8] = std::count(S.begin(), S.end(), 'G');
    }

    FORI(i, 0, SZ(S)) {
      number[7] = std::count(S.begin(), S.end(), 'S') - number[6];
    }

    FORI(i, 0, SZ(S)) {
      number[2] = std::count(S.begin(), S.end(), 'W');
    }

    FORI(i, 0, SZ(S)) {
      number[3] = std::count(S.begin(), S.end(), 'H') - number[8];
    }

    FORI(i, 0, SZ(S)) {
      number[5] = std::count(S.begin(), S.end(), 'V') - number[7];
    }

    FORI(i, 0, SZ(S)) {
      number[4] = std::count(S.begin(), S.end(), 'U');
    }

    FORI(i, 0, SZ(S)) {
      number[1] = std::count(S.begin(), S.end(), 'O') - number[4] - number[2] - number[0];
    }

    FORI(i, 0, SZ(S)) {
      number[9] = std::count(S.begin(), S.end(), 'I') - number[6] - number[8] - number[5];
    }

    FORI(i, 0, 10) {
      while (number[i])
      {
        cout << i;
        number[i]--;
      }
    }




    return 0;
  }
};

int main() {
  int t;
  cin >> t;
  FORI(i, 1, t + 1) {

    string S;
    cin >> S;


    Prob prob;
    cout << "Case #" << i << ": ";
    prob.solve(S);
    cout << endl;
  }

  return 0;
}



