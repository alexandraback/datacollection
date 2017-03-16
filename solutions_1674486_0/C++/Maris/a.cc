#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <cmath>
#include <set>

typedef long long LL;
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<bool> Vb;
typedef vector<long long> Vll;
typedef vector<double> Vd;
typedef vector<Vi> Mi;
#define forUp(x,y) for(int x=0;x<(y);x++)
#define forDown(x,y) for(int x=(y)-1;x>=0;x--)
#define LET(l,r) forUp(_t,1) for(typeof(r) l=r; !_t; _t=1)
#define forEach(x,c) LET(&_s,(c)) LET(_x,_s.begin()) for(;_x!=_s.end();_x++) LET(&x,*_x)

Mi inh;
Mi np;

int n_paths(int i, int j) {
  int &val=np[i][j];
  if (val != -1) return val;
  if (i == j)
    val = 1;
  else {
    val = 0;
    forEach(x, inh[i])
      val += n_paths(x,j);
  }
  return val;
}

int main() {
  //  freopen("a.in","r",stdin);

  int n_cases;
  cin >> n_cases;
  forUp(case_nr, n_cases) {
    int n_classes;
    cin >> n_classes;
    inh = Mi(n_classes);
    forUp(i, n_classes) {
      int n_inh; cin >> n_inh;
      forUp(j, n_inh) {
        int x; cin >> x;
        inh[i].push_back(x-1);
      }
    }

    np = Mi(n_classes, Vi(n_classes,-1));
    bool diamond = false;
    forUp(i, n_classes) forUp(j, n_classes)
      if (n_paths(i,j) > 1)
        diamond = true;

    cout << "Case #" << (case_nr+1) << ": " << (diamond ? "Yes" : "No") << endl; 
  }
  return 0;
}






