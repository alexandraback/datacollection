/*
 * temp.cpp
 *
 *  Created on: Apr 22, 2013
 *      Author: bdai
 */

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <numeric>

#include <stdio.h>
#include <stdint.h>

typedef long long Bigint;

using namespace std;

struct _compare {
  bool operator() (pair<int, int> a, 
		   pair<int, int> b) {
    return a.first > b.first;
  }
} compare;

int main() {
  int T;
  cin >> T;
  for (int_fast32_t t = 1; t <= T; ++t) {
    int E, R, N;
    cin >> E >> R >> N;
    vector<int> score(N, 0);
    vector<int> array(N, 0);
    for (int i = 0; i < N; i++) {
      int tmp;
      cin >> tmp;
      score[i] = tmp;
    }
    int current = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (score[i] > current)
	current = score[i];
      array[i] = current;
    }
    int res = 0;
    current = E;
    vector<pair<int, int> > spent(N, make_pair(0, 0));
    for (int i = 0; i < N - 1; i++) {
      spent[i].first = score[i];
      if (score[i] == array[i]) {
	res += score[i] * E;
	current -= E;
	spent[i].second = E;
      } else {
	int extra = current + R - E;
	if (extra > 0) {
	  // spread here or some where before
	  sort(spent.begin(), spent.begin() + i, compare);
	  for (int j = 0; j <= i; j++) {
	    if (spent[j].first >= score[i] &&
		spent[j].second < E) {
	      int left = min(E - spent[j].second, extra);
	      spent[j].second += left;
	      res += spent[j].first * left;
	      extra -= left;
	    }
	  }
	}
      }
      if (current + R <= E) current += R;
      else current = E;
      
    }
    res += current * score[N - 1];
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
