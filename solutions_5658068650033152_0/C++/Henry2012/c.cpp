#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n, m, k;
char * ary;

void print(char *ary)  {
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cout << *(ary +m*i +j);
    }
    cout << endl;
  }
}

char get(int i, int j) {
  return *(ary +m*i+j);
}

bool isOne(int i, int j) {
  return get(i,j) == '1';
}

int empty() {
  int ct = 0;
  for (int i=1; i<n-1; i++) {
    for (int j=1; j<m-1; j++) {
      if (isOne(i,j) && isOne(i-1, j) && isOne(i+1,j) && isOne(i,j-1) && isOne(i,j+1))
        ++ct;
    }
  }

  return ct;
}

int solve() {
  cin >> n >> m >> k;
  char mat[n][m];
  ary = (char *) mat;

  for (char * p = (char*)ary; p < (char*)ary+n*m; ++p)
    *p = '0';

  int ct = k;
  for (char * p = (char*)ary + n*m-1; ct >0; --ct) {
    *p-- = '1';
  }

  int ans = k;
  do {
     ans = min(ans, k - empty());
    /* if (empty() > 1) {
     print((char*)ary);
     cout << empty() << endl;
     }
     */
  } while (next_permutation(ary, ary+n*m));

  return ans; 
}

int main()
{
  int T;
  cin >> T;

  for (int t=1; t<=T; ++t) {
    int ct = solve();
    cout << "Case #" << t << ": " << ct << endl;
  }
}
