#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

#define SIZE 10000

int val[SIZE];
int prod[SIZE];
int psign[SIZE];

int mul[4][4] =
{
  {1,2,3,4},
  {2,1,4,3},
  {3,4,1,2},
  {4,3,2,1}
};

int sign[4][4] =
{
  {1,1,1,1},
  {1,-1,1,-1},
  {1,-1,-1,1},
  {1,1,-1,-1}
};

void solve(int test) {
  int l, xs, n;
  string x;
  cin >> xs >> l >> x;
  
  n = l * xs;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < xs; j++) {
      val[i*xs+j] = x.at(j) - 'i' + 2;
    }
  }
  
  /*
  for (int i = 0; i < n; i++) cout << val[i] << " ";
  cout << endl;
  */
  
  prod[0] = val[0];
  psign[0] = 1;
  for(int i = 1; i < n; i++) {
    prod[i] = mul[prod[i-1]-1][val[i]-1];
    psign[i] = sign[prod[i-1]-1][val[i]-1] * psign[i-1];
  }
  
  /*
  for (int i = 0; i < n; i++) cout << psign[i] * prod[i] << " ";
  cout << endl;
  */
  
  int pos = 0;
  int ok = 1;
  
  if (prod[n-1] != 1 || psign[n-1] != -1) // Wrong total product
    ok = 0;
  
  if (ok) {
    for (; pos < n; pos++) {
      if (prod[pos] == 2 && psign[pos] == 1) // found i
        break;
    }
    if (pos == n) ok = 0;
  }
  
  if (ok) {
    for (; pos < n; pos++) {
      if (prod[pos] == 4 && psign[pos] == 1) // found i*j
        break;
    }
    if (pos == n) ok = 0;
  }

  cout << "Case #" << (test+1) << ": " << (ok ? "YES" : "NO") << endl;
}


int main() {
  int t, T;
  cin >> T;
  for(t=0; t<T; t++) solve(t);
  return 0;
}

