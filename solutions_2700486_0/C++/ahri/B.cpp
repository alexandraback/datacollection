/*
ID: ahri1
PROG: B
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

int gcd(int a, int b){return b==0?a:gcd(b,a%b);}

long long binomial(int x, int y) { if (2*y>x) y=x-y; long long a=1, b=1; int i, c; for (i=0;i<y;i++) { a*=(x-i); b*=b*(1+i); c=gcd(a,b); a/=c; b/=c; } return (a/b);}


double solve(){
  int N, X, Y;
  cin >> N >> X >> Y;
  if (X<0) X=-X;
  int F = 0;
  int temp=0;
  int i=0;  
  for(;;++i) {
    temp=4*i+1;
    if (F+temp<=N) F+=temp;
    else break;
  }
  int L = N-F;
  i--;
  //cout << X << " " << Y  << " - i:" << i << endl;
  if (X+Y<=i*2) return 1;
  if (X+Y>i*2+2) return 0;
  int count = (i+1)*2;
  long long total = 0;
  long long good = 0;
//  cout << "L: " << L << endl;
  //cout << "count: " << count << endl;
  for(int i=0;i<=L;++i) {
    if (i>count || (L-i)>count) continue;
    long long tb = binomial(L, i);
    if (i>Y) good+=tb;
    total+=tb;
    //cout << i << " " << L << " " << good << "=>" << total << endl;
  }
  
  return (double)good/total;;

}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    double ret = solve();
    char buff[20];
    sprintf(buff, "%0.7g", ret);
    string retS = string(buff);
    if (sz(retS) == 1) retS += ".0";
    for(int i=0;i<sz(retS);++i) {
      
    }
    cout << retS << endl;

  }
  
  return 0;
}
