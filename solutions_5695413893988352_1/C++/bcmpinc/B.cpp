#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

using namespace std;

char C[50];
char J[50];

struct entry {
  entry() : c(0), j(0) {}
  entry(entry e, int vc, int vj) : c(e.c*10+vc), j(e.j*10+vj) {}
  long long int c, j;
  long long int delta() const { 
    return abs(c-j);
  }
  bool operator<(const entry& b) const {
    if (delta() != b.delta()) return delta() > b.delta();
    if (c != b.c) return c > b.c;
    return j > b.j;
  }
};

char result[120];

void dostep() {
  cin >> C >> J;
  int n = strlen(J);
  queue<entry> src;
  src.push(entry());
  for (int i=0; i<n; i++) {
    priority_queue<entry> dst;
    while (!src.empty()) {
      entry e = src.front();
      src.pop();
      
      for (int x=0; x<100; x++) {
        int vc = x/10, vj = x%10;
        if (C[i] != '?' && C[i]-'0' != vc) continue;
        if (J[i] != '?' && J[i]-'0' != vj) continue;
        dst.push(entry(e, vc, vj));
      }
    }
    map<int, int> filter;
    while (src.size() < 10 && !dst.empty()) {
      entry e = dst.top();
      dst.pop();
      int d = e.c-e.j;
      if (!filter[d]) {
        filter[d] = 1;
        src.push(e);
      }
    }
  }
  entry r = src.front();
  snprintf(result, 120, "%0*Ld %0*Ld", n, r.c, n, r.j);
  cout << result << endl;
}

int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ": ";
    dostep();
  }
  return 0;
}
 
