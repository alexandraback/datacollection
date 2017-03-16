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

int a[1000], b[1000];
int t;
static int score = 0;

class Level {
  public:
  int easy, hard, starsLeft;
  const bool operator< (const Level &drugi) const {
    if (score>=hard) return true;
    if (score>=drugi.hard) return false;
    if (score>=easy && score >=drugi.easy) return hard > drugi.hard;
    if (easy<drugi.easy) return true;
    if (easy>drugi.easy) return false;
    if (easy == hard) return true;
    if (drugi.easy == drugi.hard) return false;
    return hard > drugi.hard;
  }
};



int solve() {
  int ret = 0;
  vector<Level> v;
  Level level;
  score = 0;
  for (int i=0;i<t;i++) {
    level.easy = a[i];
    level.hard = b[i];
    level.starsLeft = 2;
    v.push_back(level);
  }
  sort(v.begin(), v.end());
  
  while (score<t*2) {
//  cout << score <<" " <<  v[0].easy << " " << v[0].hard << endl;
    if (score<v[0].easy) return -1;
    if (score>=v[0].hard) {
      ret++; score+=v[0].starsLeft;
      v.erase(v.begin());
    }
    else {
      ret++; score+=1;
      v[0].easy = v[0].hard;
      v[0].starsLeft = 1;
    }
    sort(v.begin(), v.end());
      
  }
  
  return ret;
}

int main() {

  int n=0;
  scanf("%d ", &n);
  vector<int> sols;
  
  for (int i=0;i<n;i++) {
    scanf("%d ", &t);
    for (int j=0;j<t;j++) scanf("%d %d ", &a[j], &b[j]);
    sols.push_back(solve());
  }
  for (int i=0;i<n;i++) {
    if (sols[i]!=-1) {
    printf("Case #%d: %d\n", i+1, sols[i]);
    }
    else {
    printf("Case #%d: Too Bad\n", i+1);
    }
  }

  return 0;

}