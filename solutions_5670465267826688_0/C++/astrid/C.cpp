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
#define I 2
#define J 3
#define K 4

bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }

/* 1 --> 1, 2 --> i, 3 --> j, 4 --> k */
inline int multabs (int a, int b) {
  if (a == b)
    return 1;
  else if (a == 1 || b == 1)
    return a + b - 1;
  else
    return 9 - a - b;
}

inline int mult (int a, int b) {
  int sign = ((a < 0) ^ (b < 0));
  a = abs(a), b = abs(b);
  int res = multabs(a,b);
  
  if ((a == b && a != 1) ||
      (a == 3 && b == 2) ||
      (a == 4 && b == 3) ||
      (a == 2 && b == 4))
    sign = 1 - sign;
  
  if (sign)
    return -res;
  else
    return res;
}


inline int divi (int a, int b) { /* returns c such as b*c = a */
  int sign = ((a < 0) ^ (b < 0));
  a = abs(a), b = abs(b);
  int res = multabs(a,b);
  
  if ((a == 1 && b != 1) ||
      (a == 2 && b == 4) ||
      (a == 3 && b == 2) ||
      (a == 4 && b == 3))
    sign = 1 - sign;
  
  if (sign)
    return -res;
  else
    return res;
}

int main() {
  //ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    ll L, X;
    string M;
    cin >> L >> X >> M;
   
    vector<int> val(L,0);
    vector<int> cum(L+1,1);
    vector<int> cuminv(L+1,1);
    
    FOR(r,0,L) {
      val[r] = I + (int)(M[r]-'i');
      cum[r+1] = mult (cum[r], val[r]);
    }
    for (int r = L-1; r >= 0; r --)
      cuminv[r] = mult (val[r], cuminv[r+1]);
    
    int sum = cum[L];
    int tmp, iter, ri, rk, nbi, nbk;
    bool ok = false;
    
    for (ri = 0; ri < L; ri++) if (abs(cum[ri+1]) == I || abs(mult(sum, cum[ri+1])) == I) {
      if (ok) break;

      nbi = 0;
      tmp = cum[ri+1]; 
      for (iter = 0; iter <= 2 && tmp != I; iter ++) {
	tmp = mult (sum, tmp);
	nbi ++;
      }
      if (tmp != I) {
	assert ((sum == 1 && cum[ri+1] == -I) || (sum == -I && cum[ri+1] == 1));
	continue; 
      }
      
      assert ((abs(cum[ri+1]) == I && (nbi == 0 || nbi == 2))
	      || (abs(mult(sum, cum[ri+1])) == I && (nbi == 1 || nbi == 3))); 
      
      if (X - nbi < 0) continue;

      for (rk = L - 1; rk >= 0; rk --) if (abs(cuminv[rk]) == K || abs(mult(cuminv[rk], sum)) == K) {
	  nbk = 0;

	  tmp = cuminv[rk];
	  for (iter = 0; iter <= 2 && tmp != K; iter ++) {
	    tmp = mult (tmp, sum);
	    nbk ++;
	  }
	  if (tmp != K) {
	    assert ((sum == 1 && cuminv[rk] == -K) || (sum == -K && cuminv[rk] == 1));
	    continue; 
	  }

	  assert ((abs(cuminv[rk]) == K && (nbk == 0 || nbk == 2))
		  || (abs(mult(cuminv[rk], sum)) == K && (nbk == 1 || nbk == 3))); 

	  int Xrem = X - nbi - nbk - 1;

	  if (Xrem == 0) {
	    if (ri >= rk) continue;
	    tmp = divi (cum[rk], cum[ri+1]);
	  }
	  else {
	    Xrem --;
	    if (Xrem < 0) continue;

	    tmp = divi (sum, cum[ri+1]);
	    for (int z = 0; z < (Xrem % 4); z++)
	      tmp = mult (tmp, sum);
	    tmp = mult (tmp, cum[rk]);
	  }
	  if (tmp == J) {
	    ok = true;
	    //cout << M << "(" << X << "): " << endl << ri << " " << nbi << " " << rk << " " << nbk << endl;
	    break;
	  }
	}
    }
    if (ok)
      cout << "Case #" << test << ": YES" << endl;
    else
      cout << "Case #" << test << ": NO" << endl;    
  }
  return 0;
}
