#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

int tryadd(int a, vector <int> stones) {
  int sum, cost;
  int i, j, n;

  n = stones.size();
  cost = 0;

  sum = a;

  for (i = 0; i < n; i++) {
    while (sum <= stones[i]) {
      cost++;
      sum = sum * 2 - 1;
    }
    sum += stones[i];
  }
  return cost;

}

int tryadddel(int a, vector <int> stones) {
  int n, i, j;
  int cost, mncost;
  vector <int> s2;

  n = stones.size();
  sort(stones.begin(), stones.end());

  if (a == 1) {
    return n;
  }

  mncost = cost = n;

  for (i = 0; i < n; i++) {
    for (j = n - 1; j >= i; j--) {
      vector <int> s2;
      int k;
      for (k = i; k <= j; k++) {
	s2.push_back(stones[k]);
      }
      cost = n - s2.size();
      cost += tryadd(a, s2);
      if (mncost > cost) {
	mncost = cost;
      }
    }
  }

  return mncost;
  
}


int main(void) {
  int T, c;
  int n;
  int a;
  int t;
  int i;
  int cost;

  cin >> T;

  for (c = 1; c <= T; c++) {
    cin >> a;
    cin >> n;
    vector <int> v;
    for (i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);

    }

    cost = tryadddel(a, v);      
    cout << "Case #" << c << ": " << cost << endl;

  }

  return 0;
}
