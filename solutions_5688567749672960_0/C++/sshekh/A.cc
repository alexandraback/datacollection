#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long LL;
typedef pair<int, int> ii;

const int N = 1000005; 
int d[N];

int getr(int n) {
  stringstream nsout;
  nsout << n;
  string ns = nsout.str();
  reverse(ns.begin(), ns.end());
  stringstream nrs(ns);
  int nr;
  nrs >> nr;
  return nr;
}

int main() {
  fill(d, d + N, INF);
  d[1] = 1;
  for(int i = 1, ir; i + 1 < N; ++i) {
    ir = getr(i);
    if(ir < N && d[ir] > d[i] + 1) d[ir] = d[i] + 1;
    if(d[i + 1] > d[i] + 1) d[i + 1] = d[i] + 1;
  }

  int T; cin >> T;
  for(int qq = 1; qq <= T; ++qq) {
    printf("Case #%d: ", qq);
    int n;
    cin >> n;
    cout << d[n] << "\n";
  }
  
  return 0;
}

