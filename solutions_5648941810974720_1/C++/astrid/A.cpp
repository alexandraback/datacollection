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

void rem (string &s, string &t) {
  int i = 0, j = 0;
  int ns = s.size(), nt = t.size();
  sort (all (t));
  for (; (i < ns) && (j < nt); i++) {
    if (s[i] == t[j]) {
      s[i] = ' ';
      j++;
    }
  }
  assert (j == nt);
}

int main() {
  int T;
  cin >> T;
  cout.precision(12);

  FOR (test, 1, T+1) {
    string s;
    cin >> s;
    sort (all (s));
    int n = s.size();
    string sol = "";
    string t = "";
    FOR(i,0,n) {
      if (s[i] == 'Z') {t+="ZERO";sol+='0';}
      if (s[i] == 'W') {t+="TWO";sol+='2';}
      if (s[i] == 'U') {t+="FOUR";sol+='4';}
      if (s[i] == 'G') {t+="EIGHT";sol+='8';}
      if (s[i] == 'X') {t+="SIX";sol+='6';}
    }
    rem(s,t);
    t = "";
    FOR(i,0,n) {
      if (s[i] == 'H') {t+= "THREE";sol+='3';}
      if (s[i] == 'F') {t+= "FIVE";sol+='5';}
    }
    rem(s,t);
    t="";
    FOR(i,0,n) {
      if (s[i] == 'O') {t+= "ONE";sol+='1';}
      if (s[i] == 'V') {t+= "SEVEN";sol+='7';}
      if (s[i] == 'I') {t+= "NINE";sol+='9';}
    }
    rem(s,t);
    sort (all (sol));
    cout << "Case #" << test << ": " << sol << endl;
  }
  return 0;
}
