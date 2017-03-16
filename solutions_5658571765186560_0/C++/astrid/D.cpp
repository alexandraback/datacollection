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

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> int2;
typedef pair<float, float> float2;
typedef pair<ull, ull> ull2;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(s,i) for ( __typeof((s).begin()) i = ((s).begin())   ; i != (s).end(); ++i)  
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)
#define del(s,x) if(s.find(x)!=s.end()) s.erase(s.find(x))

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }

int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int X, R, C;
    cin >> X >> R >> C;
    int tmp = max(R,C);
    R = min(R,C);
    C = tmp;
    bool alwayspossible = false;

    switch (X) {
    case 1:
      alwayspossible = true;
      break;

    case 2:
      if ((R % 2 == 0) || (C % 2 == 0))
	alwayspossible = true;
      break;

    case 3:
      if (R == 2 && (C % 3 == 0))
	alwayspossible = true;
      if (R == 3 && (C == 3 || C == 4))
      	alwayspossible = true;
      break;
    case 4:
      if ((R == 3 || R == 4) && (C == 4))
	alwayspossible = true;
      break;
    }
    if (alwayspossible)
      cout << "Case #" << test << ": GABRIEL" << endl;
    else
      cout << "Case #" << test << ": RICHARD" << endl;
  }
  return 0;
}
