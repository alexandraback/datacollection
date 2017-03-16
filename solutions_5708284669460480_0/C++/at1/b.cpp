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
typedef double dbl;

int k, l, s;
string keys, word;

ll sum = 0, amount = 0;
int maxCnt = 0;

vector<char> pressed;
void go() {
  if (sz(pressed) == s) {
    string s(all(pressed));
    int cnt = 0;
    for (int i = 0; i <= sz(s) - sz(word); i++)
      if (s.substr(i, sz(word)) == word)
        cnt++;

    sum += cnt;
    maxCnt = max(maxCnt, cnt);
    amount++;
    return;
  }

  for (char x : keys) {
    pressed.push_back(x);
    go();
    pressed.pop_back();
  }
}

void testCase()
{
  cin >> k >> l >> s >> keys >> word;

  sum = 0, maxCnt = 0, amount = 0;
  go();

  cout.precision(16);
  cout << fixed << (maxCnt - (double)sum / amount) << endl;
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cerr << "Case #" << t << endl;
    cout << "Case #" << t << ": ";
//    printf("Case #%d: ", t);
    testCase();
  }
  return 0;
}
