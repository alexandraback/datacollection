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

int mul[8][8] = {
  {0,1,2,3,4,5,6,7},
  {1,4,3,6,5,0,7,2},
  {2,7,4,1,6,3,0,5},
  {3,2,5,4,7,6,1,0},
  {4,5,6,7,0,1,2,3},
  {5,0,7,2,1,4,3,6},
  {6,3,0,5,2,7,4,1},
  {7,6,1,0,3,2,5,4},
};

int get(char c) {
  assert('i' <= c && c <= 'k');
  return c - 'i' + 1;
}

void testCase()
{
  int L, x;
  cin >> L >> x;

  string s, a;
  cin >> a;
  while (x-- > 0) {
    s += a;
  }
 // cerr << s << endl;

  int i = 0;
  int p = 0;

  for (i = 0; i < sz(s) && p != get('i'); i++) {
    p = mul[p][get(s[i])];
//    cerr << "p = " << p << endl;
  }

//  cerr << i << endl;

  p = 0;
  for (; i < sz(s) && p != get('j'); i++) {
    p = mul[p][get(s[i])];
//    cerr << "p = " << p << endl;
  }

//  cerr << i << endl;

  p = 0;
  for (; i < sz(s); i++) {
    p = mul[p][get(s[i])];
  }
  cout << (p == get('k') ? "YES" : "NO") << endl;
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
//  cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
//    cout << "Case #" << t << ": ";
    printf("Case #%d: ", t);
    testCase();
  }
  return 0;
}
