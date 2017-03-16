#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

const lglg MODS = 1000000007;

void solve() {
  int n;
  scanf("%d", &n);
  char current[102];
  vector<string> sets;

  for(int i = 0; i < n; ++i) {
    scanf("%s", current);

    sets.push_back(current);
  }

  int free = 0;

  int start[30], finish[30], middle[30], full[30], next[30];

  for(int i = 0; i < 30; ++i) {
    start[i] = 0;
    finish[i] = 0;
    middle[i] = 0;
    full[i] = 0;
    next[i] = -1;
  }

  lglg ways = 1;

  for(size_t i = 0; i < sets.size(); ++i) {
    string& curs = sets[i];
    int len = curs.size();


    char first = curs[0], last = curs[len-1];
    int firstk = first - 'a', lastk = last - 'a';

    if(first == last) { // FULL or bad
      for(int j = 1; j < len-1; ++j) {
        if(curs[j] != first) {
          printf("0\n");
          return;
        }
      }

      // FULL
      ++full[firstk];
      if(full[firstk] == 1) {
        if(middle[firstk]) {
          printf("0\n");
          return;
        }

        if(start[firstk] == 0 && finish[firstk] == 0) {
          ++free;
        }
      } else { // full[k] > 1
        ways = (ways * (lglg)full[firstk]) % MODS;
      }
    } else {  // Not FULL
      ++free;
      // Handle start;
      if(start[firstk] || middle[firstk]) {
        printf("0\n");
        return;
      }

      ++start[firstk];
      next[firstk] = lastk;

      if(finish[firstk] || full[firstk]) {
        --free;
      }

      // Handle finish;
      if(finish[lastk] || middle[lastk]) {
        printf("0\n");
        return;
      }

      ++finish[lastk];

      if(start[lastk] || full[lastk]) {
        --free;
      }

      // Handle middle
      int si = 0;
      while(curs[si] == first) {
        ++si;
      }
      while(1) {
        char letter = curs[si];
        int letterk = letter - 'a';

        while(si < len && curs[si] == letter) {
          ++si;
        }

        if(si == len) {
          break;
        }

        if(start[letterk] || middle[letterk] || finish[letterk] || full[letterk]) {
          printf("0\n");
          return;
        }

        ++middle[letterk];
      }
    }
  }

  // Check cycles
  for(int i = 0; i < 'z'-'a'; ++i) {
    int from = i;
    int it = next[i];
    while(it >= 0) {
      if(it == from) {
        printf("0\n");
        return;
      }

      it = next[it];
    }
  }

  // Count frees
  while(free > 1) {
    ways = (ways * (lglg)free) % MODS;

    --free;
  }

  // print
  printf("%ld\n", (long)ways);
}

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d: ", t+1);

    solve();
  }

  return 0;
}
