#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(typeof(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef long long ll;

#define D 0

bool safe(int N, int x, double xv, const vector<double> &c)
{
  double mark = c[x] + xv;
  double rest = 1.0-xv;
  REP(i, N) {
    if(i==x) continue;
    if(c[i] > mark) continue;
    rest -= mark - c[i];
  }
  return (rest < 0);
}

double binarize(int N, int x, double min, double max, const vector<double> &c)
{
  if(max-min < 1e-15) return (min+max)/2;
  bool r = safe(N, x, (min+max)/2, c);
  if(r)
    return binarize(N, x, min, (min+max)/2, c);
  else
    return binarize(N, x, (min+max)/2, max, c);
}
void solve(bool skip)
{
  int N;
  cin >> N;
  vector<int> s(N);
  int sum = 0;
  REP(i, N) {
    cin >> s[i];    
    sum += s[i];
  }
  if(skip) return;

  vector<double> c(N);
  REP(i, N) {
    c[i] = double(s[i])/sum;
  }
  REP(i, N) {
    //double ans = 2.0/N - double(s[i])/sum;
    double ans = binarize(N, i, 0, 1, c);
    //if(ans < 0) ans = 0;
    assert(ans >= 0);
    assert(ans <= 1);
    cout << " " << 100*ans;
  }
}

int main(int argc, char **argv)
{
  int T;
  cin >> T;
  int pick = 0;
  if(argc==2) pick = atoi(argv[1]);
  cout.precision(10);
  for(int i=0;i<T;i++) {
    bool skip = pick && (pick!=i+1);
    if(!skip) {
      cout << "Case #" << (i+1) << ":";
    }
    solve(skip);
    if(!skip) {
      cout << endl;
    }
  }
}
