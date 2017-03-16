#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define debug(x) std::cerr << "DEBUG: " << #x << " = " << (x) << std::endl
#define mp make_pair
#define pb push_back
#define PATH "C:\\Users\\Valentin\\Desktop\\"

template<class T> inline int sz(const T& x)
{ return (int) x.size(); }

template<class X, class Y> inline void mx(X& x, Y&& y)
{ if (x < y) x = std::forward<Y>(y); }

template<class X, class Y> inline void mn(X& x, Y&& y)
{ if (y < x) x = std::forward<Y>(y); }

// SOLUTION BEGINS HERE


const std::string numbers[10] = {
"ZERO", // 1 Z
"ONE",  // 6 O
"TWO", // 4 W
"THREE", // 7 T
"FOUR", // 5 R
"FIVE", // 8
"SIX", // 2 X
"SEVEN", // 9
"EIGHT", // 3 G
"NINE"};

vector<int> place_order = {
  0, 6, 8, 2, 4, 1, 3, 5, 7, 9
};



void solve() {
  string s;
  cin >> s;
  vector<int> count(26, 0);
  for (char c: s) {
    count[(int)(c - 'A')]++;
  }
  vector<int> ans;
  const int INF = 1000000;
  for (int d : place_order) {
    vector<int> curr_count(26, 0);
    for (char c: numbers[d]) {
      curr_count[(int)(c - 'A')]++;
    }
    int can_place = INF;
    forn (j, 26) {
      if (curr_count[j]) {
        mn(can_place, count[j] / curr_count[j]);
      }
    }
    forn (i, can_place) {
      ans.push_back(d);
    }
    forn (j, 26) {
      count[j] -= curr_count[j] * can_place;
    }
  }
  sort(all(ans));
  for (int d: ans) {
    cout << d;
  }
  cout << endl;
}

void run() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int nTests;
  cin >> nTests;
  for (int iTest = 0; iTest < nTests; ++iTest) {
    cout << "Case #" << (iTest + 1) << ": ";
    solve();
  } 
}

// SOLUTION ENDS HERE

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run();
  std::cout.flush();
  return 0;
}