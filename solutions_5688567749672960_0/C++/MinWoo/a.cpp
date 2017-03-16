
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

long long solve(long long n) {
  long long res = 1;
  while ( n != 1 ) {
    char buf[32];
    sprintf(buf, "%lld", n);
    int len = strlen(buf);
    if ( buf[len-1] == '0' ) {
      n = n - 1;
    }
    else {
      reverse(buf, buf+len);

      long long rev;
      sscanf(buf, "%lld", &rev);
      if ( rev < n ) {
        n = rev;
      }
      else {
        n = n - 1;
      }
    }
    ++res;
  }
  return res;
}

long long solve1(long long n) {
  queue<long long> q;
  q.push(1LL);
  set<long long> already;
  already.insert(1);

  for ( int k=1 ; true ; ++k ) {
    int qs = q.size();
    for ( int i=0 ; i<qs ; ++i ) {
      long long curr = q.front(); q.pop();
      if ( curr == n ) return k;

      char buf[32];
      sprintf(buf, "%lld", curr);
      int len = strlen(buf);

      long long rev;
      reverse(buf, buf+len);
      sscanf(buf, "%lld", &rev);

      if ( already.find(rev) == already.end() ) {
        q.push(rev);
        already.insert(rev);
      }
      if ( already.find(curr+1) == already.end() ) {
        q.push(curr+1);
        already.insert(curr+1);
      }
    }
  }
}

int main() {
  int TC;
  cin >> TC;
  for ( int tc=1 ; tc<=TC ; ++tc ) {
    long long n;
    cin >> n;
    cout << "Case #" << tc << ": " << solve1(n) << endl;
  }
}

