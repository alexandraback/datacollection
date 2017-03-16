#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <assert.h>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int A, B, rst;
int n, p10;

string toStr(int x) {
  stringstream ss; ss<<x<<endl;
  string str; ss>>str;
  return str;
}

void play(int x) {
  set<int> st;
  int y = x, d;
  REP(i, n) {
    d = y % 10; y /= 10; y=y+d*p10;
    if (!d) continue;
    if (st.find(y) != st.end()) continue;
    if (x!=y && y>=A && y<=B) {
      rst++;
      st.insert(y);
    }
  }
}

int main() {
  int T; cin>>T;
  FOR(cs, 1, T) {
    cin>>A>>B;
    rst=0;
    string s = toStr(A); n = s.length();
    p10 = 1; REP(i, n-1) p10*=10;
    FOR(x, A, B) play(x);
    cout<<"Case #"<<cs<<": "<<rst/2<<endl;
  }
  return 0;
}
