#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <numeric>
#include <limits.h>
#include <iomanip>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef long long ll;

#define ITE(v) typeof(v.begin())
#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORIT(it,v) for(ITE(v) it = v.begin(); it != v.end(); it++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) int(v.size())
#define pb push_back
#define SQR(a) ((a)*(a))

#define INF 0x3f3f3f3f
#define EPS (1e-9)

inline int cmp(double a, double b = 0.0) {
  if (fabs(a-b) <= EPS) return 0;
  if (a < b) return -1;
  return 1;
}

struct triple {
  int first, second, third;
  triple(int first, int second, int third): first(first), second(second), third(third) {};
  bool operator < (triple b) const {
    if (first != b.first) return first < b.first;
    if (second != b.second) return second < b.second;
    return third < b.third;
  }
};

int v[1001][2];

set<triple> s1, s2;

int main(int argc, char **argv) {
  int ncases;
  cin >> ncases;
  FOR(kk, ncases) {
    s1.clear();
    s2.clear();
    printf("Case #%d: ", kk+1);
    int n;
    cin >> n;
    FOR(i,n) cin >> v[i][0] >> v[i][1];
    FOR(i,n) {
      s1.insert(triple(v[i][0], v[i][1], i));
      s2.insert(triple(v[i][1], v[i][0], i));
    }
    int stars = 0;
    int count = 0;
    bool ok = true;
    while (!s1.empty() || !s2.empty()) {
      count++;
      triple ele2 = *s2.begin();
      if (ele2.first <= stars) {
        triple other = triple(v[ele2.third][0], v[ele2.third][1], ele2.third);
        if (s1.count(other)) {
          stars += 2;
          s1.erase(other);
        }
        else {
          stars++;
        }
        s2.erase(s2.begin());
        //cout << ele2.third << endl;
        continue;
      }
      if (s1.empty()) {
        ok = false;
        break;
      }
      set<triple>::iterator iter = s1.begin(), miniter = iter;
      while (iter != s1.end() && iter->first <= stars) {
        if (iter->second > miniter->second) {
          miniter = iter;
        }
        iter++;
      }
      triple ele1 = *miniter;
      if (ele1.first <= stars) {
        stars++;
        s1.erase(miniter);
        //cout << ele1.third << endl;
      }
      else {
        ok = false;
        break;
      }        
    }
    if (ok) cout << count << endl;
    else cout << "Too Bad" << endl;
  }
  return 0;
}
