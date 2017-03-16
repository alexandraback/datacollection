#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;

void testCase()
{
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    s[i].resize(unique(all(s[i])) - s[i].begin());
  }

  vector<int> p(n);
  for (int i = 0; i < n; i++)
    p[i] = i;
  int ans = 0;
  vector<int> freq;
  do {
    string str = "";
    for (int i = 0; i < n; i++)
      str += s[p[i]];
//    cerr << str << endl;
    freq.assign(26, 0);
    for (int l = 0, r = 0; l < sz(str); l = r)
    {
      for (r = l + 1; r < sz(str) && str[l] == str[r]; r++)
        ;
//      cerr << "[" << l << "," << r << ") = " << str[l] << endl;
      freq[str[l] - 'a']++;
    }
    bool bad = false;
    for (int i = 0; i < 26 && !bad; i++)
      if (freq[i] > 1)
        bad = true;
    ans += !bad;
  } while (next_permutation(all(p)));
  printf("%d\n", ans);
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
//    cout << "Case #" << t << ": ";
    cerr << "test #" << t << endl;
    printf("Case #%d: ", t);
    testCase();
  }
  return 0;
}
