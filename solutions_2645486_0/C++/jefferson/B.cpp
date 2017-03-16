#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

typedef vector <   int  > vi;
typedef vector <   vi   > vvi;
typedef vector < double > vd;
typedef vector <   vd   > vvd;
typedef vector < string > vs;

#define MAX 11
int v[MAX];

int solve (int e, int E, int R, int n, int N) {
  if (n == N)
    return e * v[N];

  int maxi = 0;
  for (int eg = e; eg >= 0; eg--)
    maxi = max(maxi, (eg*v[n]) + solve(min(E,e-eg+R),E,R,n+1,N));

  return maxi;
}

int main () {
  int T; int E, R, N;
  cin >> T;

  for (int x = 1; x <= T; x++) {
    cin >> E >> R >> N;
    for (int i = 1; i <= N; i++)
      cin >> v[i];

    int ans = 0;
    for (int e = 0; e <= E; e++)
      ans = max(ans, solve(e, E, R, 1, N));

    cout << "Case #" << x << ": " << ans << endl;
  }

  return 0;
}
