#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

const string PROGRAM_NAME = "google";

int cnt[256];

int br[10];

string names[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void add(int val, int broi) {
  br[val] += broi;
  for (int i  = 0; i < (int)names[val].size(); ++i) {
    cnt[(int)names[val][i]] -= broi;
  }
}
int main() {
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  string s;
  getline(cin, s);
  for (int it = 1; it <= nt; it++) {
    getline(cin, s);
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < (int)s.size(); ++i) {
      cnt[(int)s[i]]++;
    }

    memset(br, 0, sizeof(br));

    add(4, cnt['U']);
    add(2, cnt['W']);
    add(6, cnt['X']);
    add(0, cnt['Z']);
    add(8, cnt['G']);
    add(5, cnt['F']);
    add(3, cnt['H']);
    add(7, cnt['V']);
    add(1, cnt['O']);
    add(9, cnt['I']);

    string res = "";
    for (int v = 0; v < 10; ++v) {
      for (int c = 0; c < br[v]; ++c) {
        res.push_back('0' + v);
      }
    }
    cout << "Case #" << it << ": " << res << endl;
  }
  return 0;
}
