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

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int K, L, S;
    cin >> K >> L >> S;

    string keyboard;
    cin >> keyboard;
    vector<int> key (200,0);
    FOR(i,0,K) key[keyboard[i]] ++;

    string targ;
    cin >> targ;
    
    /* check if we have the good letters */
    bool possible = true;
    FOR(i,0,L) if (key[targ[i]] == 0) possible = false;
    if (!possible) {
      cout << "Case #" << test << ": " << 0 << endl;
      continue;
    }

    int mini = L;
    FOR(i,1,L) {
      bool ok = true;
      FOR(j,0,L) {
	if ((i+j < L) && (targ[j+i] != targ[j]))
	  ok = false;
      }
      if (ok) {mini = i; break;}
    }
    int nb = (S - L + mini) / mini;
    //cout << mini << " " << nb <<  endl;

    /* proba[i][j] = proba que target[0...j-1] soit suffixe du mot écrit au bout de i touches tappées */
    vector<vector<double> > proba(S+1,vector<double>(L+1,0));
    double sum = 0;
    proba[0][0] = 1.;
    FOR(i,1,S+1) {
      proba[i][0] = 1;
      FOR(j,1,L+1) {
	proba[i][j] = proba[i-1][j-1] * (double)key[targ[j-1]]/(double)K;
      }
      sum += proba[i][L];
    }
    //cout << sum << endl;
    cout << "Case #" << test << ": " << nb - sum << endl;
  }
  return 0;
}
