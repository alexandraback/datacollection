#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define IN(_lower,_variable,_higher) (((_lower)<=(_variable)) && ((_variable)<=(_higher)))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORU(v,p,k) for(int v=p;v<k;++v)
#define FORD(v,p,k) for(int v=(p)-1;v>=k;--v)
#define FORLLU(v,p,k) for(LL v=p;v<k;++v)
#define FORLLD(v,p,k) for(LL v=(p)-1;v>=k;--v)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

#define MAXN 100000

int a, b;
double p[MAXN];


double solve() {
  double ret = b+2;
  double temp = 0;
  double sofarsogood = 1;
  int tempkeystrokes = 0;
  
  for (int i=0;i<a;i++) {
    sofarsogood*=p[i];
    tempkeystrokes = (a-i-1)*2 + (b-a) + 1;
    temp = sofarsogood * ( tempkeystrokes) + (1-sofarsogood)* (tempkeystrokes + b + 1);
    if (temp<ret) ret = temp;
//    cout << i << " " << sofarsogood << " " << temp << endl;
  }

  return ret;
}

int main() {

  int n=0;
  scanf("%d ", &n);
  vector<double> sols;
  
  for (int i=0;i<n;i++) {
    scanf("%d %d ", &a, &b);
    for (int j=0;j<a;j++) scanf("%lf ", &p[j]);
    sols.push_back(solve());
  }
  for (int i=0;i<n;i++) {
    printf("Case #%d: %0.6lf\n", i+1, sols[i]);
  }

  return 0;

}