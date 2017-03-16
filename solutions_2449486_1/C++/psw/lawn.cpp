#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>

using namespace std;

int main() {
  int T, n, m, A[102][102], U[102], V[102], i, j, k, cn, res, mv;
  cin >> T;
  for(cn=0; cn<T; cn++){
    cin >> n >> m;
    for(i=0; i<n; i++)
      for(j=0; j<m; j++)
	cin >> A[i][j];
    for(i=0; i<n; i++) {
      U[i] = A[i][0];
      for(j=1; j<m; j++)
	if(A[i][j] > U[i]) U[i] = A[i][j];
    }
    for(j=0; j<m; j++) {
      V[j] = A[0][j];
      for(i=1; i<n; i++)
	if(A[i][j] > V[j]) V[j] = A[i][j];
    }
    res = 1;
    for(i=0; i<n; i++)
      for(j=0; j<m; j++) {
	mv = U[i];
	if (mv > V[j]) mv = V[j];
	if (A[i][j] != mv) res = 0;
      }
    if (res)
      cout << "Case #" << cn+1 << ": YES\n";
    else
      cout << "Case #" << cn+1 << ": NO\n";
  }
  return 0;
}