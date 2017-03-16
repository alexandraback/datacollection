#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n;
vector<string> ss;

bool valid(int * a) {
  char prev = ss[ a[0] ].back();

  /*
  for (int i=0; i<n; ++i) {
    cout << ss[a[i]] << ' ';
  }
  cout << endl;
  */

  for (int i=1; i<n; ++i) {
    if (ss[a[i]][0] != prev)
      return false;

    prev = ss[a[i]].back();
  }

  return true;
}

int solve() {
  cin >> n;
  int a[n];
  ss.clear();
  ss.resize(n);
  string tmp;
  for (int i=0; i<n; i++) {
    cin >> tmp; 
    ss[i] = tmp;
    a[i] = i;
  }

  int ans = 0;
  do {
    if (valid(a))
      ++ans;
  } while (next_permutation(a, a +n));

  return ans;
}

int main()
{
  int T;
  cin >> T;

  for (int t=1; t<=T; ++t) {
    int ct = solve();
    cout << "Case #" << t << ": " << ct << endl;
  }
}
