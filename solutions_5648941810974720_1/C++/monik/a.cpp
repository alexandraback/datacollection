#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

using namespace std;

int T;
string S;
vector<string> num_names;
char base[10] = { 'W', 'X', 'G',  'Z', 'H', 'R', 'F', 'O', 'V', 'I'};
int order[10] = {  2,    6,   8,    0,   3,   4,   5,  1,   7,   9 };

vector<string> init_num() {
  vector<string> num;
  num.push_back( "ZERO" );
  num.push_back( "ONE" );
  num.push_back( "TWO" );
  num.push_back( "THREE" );
  num.push_back("FOUR");
  num.push_back("FIVE");
  num.push_back("SIX");
  num.push_back("SEVEN");
  num.push_back("EIGHT");
  num.push_back("NINE");
  return num;
}

vector<int> remove(int n, vector<int> v) {
  REP(i, SIZE(num_names[n]))
    --v[num_names[n][i]-'A'];
  return v;
}

int main(void) {
  num_names = init_num();
  cin >> T;
  REP(t, T) {
    vector<int> v(26,0);
    vector<int> w(10,0);
    cin >> S;
    REP(i, SIZE(S)) 
      ++v[S[i]-'A'];
    
    REP(i, 10) {
      int n = order[i];
      char c = base[i];
      w[n] = v[c-'A'];
      REP(i, w[n]) v = remove(n, v);
      REP(i, SIZE(v)) assert(v[i] >= 0);
    }
    cout << "Case #" << (t+1) << ": ";
    REP(i, SIZE(w)) {
      REP(j, w[i])
        cout << i;
    }
    cout << endl;
  }
  return 0;
}
