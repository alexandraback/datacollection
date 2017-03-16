#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
#include <assert.h>

using namespace std;

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

typedef long long int ll;

// small
//#define SIZ 16
//#define HALFSIZ 7
//#define ASKED 50

// large
#define SIZ 32
#define HALFSIZ 15
#define ASKED 500

int check (vector<int>& tot, int base, int div) {
  int rem = 0;
  int pow = 1;
  FOR(i,0,SIZ) {
    assert ((pow >= 0) && (pow <= 10) && (rem >= 0) && (rem <= 10));
    if (tot[i])
      rem = (rem + pow) % div;
    pow = (pow * base) % div;
  }
  return (rem == 0);
}

int main () {
  cout << "Case #1: " << endl;
  vector<int> even (HALFSIZ, 0);
  vector<int> odd (HALFSIZ, 0);
  even[HALFSIZ - 1] = even[HALFSIZ - 2] = odd[HALFSIZ - 1] = odd[HALFSIZ - 2] = 1;
  int cpt = 0;
  int iter = 0;
  do {
    do {
      iter ++;
      vector<int> tot (32, 0);
      tot[0] = tot[SIZ - 1] = 1;
      FOR(i,0,HALFSIZ) tot[1+2*i] = odd[i];
      FOR(i,0,HALFSIZ) tot[2+2*i] = even[i];
      
      assert (check (tot, 2, 3));
      assert (check (tot, 3, 2));
      assert (check (tot, 4, 3));
      assert (check (tot, 5, 2));
      assert (check (tot, 6, 7));
      assert (check (tot, 7, 2));
      assert (check (tot, 8, 3));
      assert (check (tot, 9, 2));
      assert (check (tot, 10, 3));
      
      FOR(i,0,SIZ) cout << tot[SIZ-1-i]; cout << " 3 2 3 2 7 2 3 2 3" << endl;
      cpt ++;
      if (cpt == ASKED)
	return 0;
    } while (next_permutation (odd.begin(), odd.end()));
  } while (next_permutation (even.begin(), even.end()));
    
  cout << "failed" << endl;
  return (0);
}
