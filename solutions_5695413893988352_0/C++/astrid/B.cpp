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
#define del(s,x) do {__typeof((s).begin()) abcde=(s).find(x); if(abcde !=(s).end()) s.erase(abcde); } while(0);
#define del2(s,x) do {__typeof((s).begin()) abcde=find(all(s),x); if(abcde !=(s).end()) s.erase(abcde); } while(0);
 
template<class T> inline bool comp(T a, T b) {return a>b;} // sort(t, t+9, comp<int>);

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

int main() {
  int T;
  cin >> T;
  cout.precision(12);

  FOR (test, 1, T+1) {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n = s1.size();
    assert (n == s2.size());
    
    if (n == 1) {
      if (s1[0] == '?' && s2[0] == '?') {
	s1 = "0";
	s2 = "0";
      }
      if (s1[0] == '?')
	s1 = s2;
      if (s2[0] == '?')
	s2 = s1;
      cout << "Case #" << test << ": " << s1 << " " << s2 << endl;
    }
    else {
      int maxi = 1000;
      int diz = 1, uni = 2, cent = 0;
      if (n == 2) {
	maxi = 100;
	diz = 0;
	uni = 1;
	cent = -1;
      }
      int bestdiff = 100000;
      int besti = -1, bestj = -1;
      FOR(i,0,maxi) {
	FOR(j,0,maxi) {
	  if (s1[uni] != '?' && ((int)(s1[uni]-'0')) != (i % 10))
	    continue;
	  if (s2[uni] != '?' && ((int)(s2[uni]-'0')) != (j % 10))
	    continue;
	  if (s1[diz] != '?' && ((int)(s1[diz]-'0')) != ((i/10) % 10))
	    continue;
	  if (s2[diz] != '?' && ((int)(s2[diz]-'0')) != ((j/10) % 10))
	    continue;
 
	  if (n == 3) {
	    if (s1[cent] != '?' && ((int)(s1[cent]-'0')) != ((i/100) % 10))
	      continue;
	    if (s2[cent] != '?' && ((int)(s2[cent]-'0')) != ((j/100) % 10))
	      continue;
	  }
	  int diff = max (i - j, j - i);
	  // cout << i << " " << j << " " << diff << " " << bestdiff << endl;
	  if ((diff < bestdiff) || 
	      ((diff == bestdiff) && (i < besti)) ||
	      ((diff == bestdiff) && (i == besti) && (j < bestj))) {
	    bestdiff = diff;
	    besti = i;
	    bestj = j;
	  }
	}
      }
      cout << "Case #" << test << ": ";
      if (n == 2 && besti < 10) cout << "0";
      if (n == 3 && besti < 10) cout << "0";
      if (n == 3 && besti < 100) cout << "0";
      cout << besti << " ";
      if (n == 2 && bestj < 10) cout << "0";
      if (n == 3 && bestj < 10) cout << "0";
      if (n == 3 && bestj < 100) cout << "0";

      cout << bestj << endl;
    }
  }
  return 0;
}
