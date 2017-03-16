#pragma comment(linker, "/STACK:46777216")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (ll i = 0; i < ll(n); ++i)
#define mp make_pair

const int M = 3000000;
bool data[M];

bool lvl1[M];
bool lvl2[M];

set<int> pm;

// false = +, true = - 
void iter(int sum, int n) {
  while (sum > 0) {
    if (data[1]) { 
      data[1] = false;
      sum -= 2;
      if (data[2]) pm.insert(1);
      continue;
    }
    if (pm.empty()) {
      cerr << "WTF?!";
      exit(-1);
    }
    int i = *pm.begin();
    pm.erase(i);
    data[i] = !data[i];
    data[i + 1] = !data[i + 1];
    if (i - 1 >= 0 && !data[i - 1]) {
      pm.insert(i - 1);
    }
    if (i + 2 <= n && data[i + 2]) {
      pm.insert(i + 1);
    }
    sum -= 2;
  }
  
}

int main() {
  int T;
  cin >> T;
  forn (_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    int x, y; cin >> x >> y;
    string result;

    bool invx = false;
    bool invy = false;
    if (x + y < 0) {
      invx = true;
      invy = true;
      x *= -1;
      y *= -1;
    }
    if (x < 0) {
      x *= -1;
      invx = !invx;
    }

    int n = 0;
    int sum = 0;
    while (sum < abs(x) + abs(y) ||
          ((sum - x - y) % 2 == 1)) sum += ++n;

    pm.clear();
    memset(data, 1, sizeof(data));
    iter(sum - x - y, n);
    memcpy(lvl1, data, sizeof(data));
    iter(2 * x, n);
    memcpy(lvl2, data, sizeof(data));

    result.resize(n);
    for (int i = 1; i <= n; ++i) {
      if (lvl1[i] == lvl2[i]) { 
        result[i - 1] = lvl1[i] ? 'N' : 'S';
      } else {
        result[i - 1] = lvl1[i] ? 'E' : 'W';
      }

    }

    for (int i = 0; i < result.size(); ++i) {
      if (invy) {
        if (result[i] == 'S') result[i] = 'N';
        else if (result[i] == 'N') result[i] = 'S';
      }
      if (invx) {
        if (result[i] == 'E') result[i] = 'W';
        else if (result[i] == 'W') result[i] = 'E'; 
      }
    }
    cout << result << endl;
  }


  return 0;
}